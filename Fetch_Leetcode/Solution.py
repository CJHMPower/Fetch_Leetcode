# coding:utf-

import os
import time
import re
from bs4 import BeautifulSoup


class Submission:
    HOME_URL = "https://leetcode.com/"
    lang2extend = {
        'java': ['.java', '//'],
        'cpp': ['.cpp', '//'],
        'python': ['.py', '#'],
        'javascript': ['.js', '//'],
        'python3': ['.py', '#'],
        'c': ['.c', '//'],
        'csharp': ['.cs', '//'],
        'ruby': ['.rb', '#'],
        'golang': ['.go', '//'],
        'swift': ['.swift', '//'],
        'mysql': ['.sql', '#'],
        'scala': ['.scala', '//'],
        'kotlin': ['.kt', '//'],
        'mssql': ['.sql', '#'],
        'oracle': ['.sql', '#'],
        'bash': ['.sh', '#']
    }

    def __init__(self,
                 question_title=None,
                 submit_time=None,
                 status=None,
                 submission_url=None,
                 runtime=None,
                 language=None):
        self.question_id = None
        self.question_title = question_title
        self.submit_time = submit_time
        self.status = status
        self.submission_url = submission_url
        self.runtime = runtime
        self.language = language
        self._source_code = None
        self._soup = None
        self.defeat = None

    def set_soup(self, soup):
        if not isinstance(soup, BeautifulSoup):
            raise TypeError("Soup is not a valid BeautifulSoup object")
        if self._soup is not None:
            raise ValueError("Question soup can only be set for one time")
        self._soup = soup

    def set_source_code(self, source_code):
        if not isinstance(source_code, str):
            raise TypeError("Source code must be string type but got",
                            type(source_code))
        if self._source_code is not None:
            raise RuntimeError("Source code could only be set for one time")
        self._source_code = source_code

    def get_source_code(self):
        if self._source_code is None:
            raise RuntimeError("Get source code before setting")
        return self._source_code

    def fetch_defeat(self):
        tag = self._soup.find(class_="callout")
        if tag is None:
            return
        text = tag.text.encode("utf-8")
        pattern = re.compile(r'[0-9]{1,3}\.[0-9]{1,3}')
        defeat = re.search(pattern, text)
        defeat = float(defeat.group())
        self.defeat = defeat

    def check_attribute(self):
        assert isinstance(self.question_id, int) and self.question_id > 0
        assert isinstance(self.question_title, str)
        assert isinstance(self.submit_time, str)
        assert isinstance(self.runtime, int) and self.runtime >= 0
        assert isinstance(self.language,
                          str) and self.language in Submission.lang2extend
        assert isinstance(self._source_code, str)

    def write2disk(self, save_path):
        extend, comment = Submission.lang2extend[self.language][
            0], Submission.lang2extend[self.language][1]

        def title2url(title):
            words = title.split()
            words = '-'.join([word.lower() for word in words])
            url = Submission.HOME_URL + "/problems/" + words + "/description/"
            return url

        text = comment + "-*- coding:utf-8 -*-"
        text += "\n" + comment + "Generated by the Fetch-Leetcode project on the Github"
        text += "\n" + comment + "https://github.com/CJHMPower/Fetch-Leetcode/ \n"
        text += "\n" + comment + str(
            self.question_id) + " " + self.question_title
        text += '\n' + comment + title2url(self.question_title)
        text += '\n' + comment + "Fetched at " + time.strftime(
            '%Y-%m-%d', time.localtime(time.time()))
        text += '\n' + comment + "Submitted " + self.submit_time
        text += "\n" + comment + "Runtime: " + str(self.runtime) + " ms"
        if self.defeat is not None:
            text += "\n" + comment + "This solution defeats " + str(
                self.defeat) + "% " + self.language + " solutions"
        text += "\n\n"
        text += self._source_code

        i = 1
        fname = os.path.join(save_path,
                             self.question_title + '_' + str(i) + extend)
        while os.path.exists(fname):
            i += 1
            fname = os.path.join(save_path,
                                 self.question_title + '_' + str(i) + extend)
        with open(fname, 'w') as f:
            f.write(text)
            f.close()
