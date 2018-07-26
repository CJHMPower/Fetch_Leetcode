#coding:utf-8

import os
import json

from bs4 import BeautifulSoup


class Question:
    def __init__(self,
                 id=None,
                 title=None,
                 url=None,
                 paidOnly=False,
                 frequency=None):
        self._id = id
        self._title = title
        self._url = url
        self._paidOnly = paidOnly
        self._soup = None
        self.level = None
        self.total_submission = None
        self.total_accepted = None
        self.ac_rate = None
        self.like = None
        self.dislike = None
        self.frequency = frequency
        self.similar_questions = []  # store the title of similar questions
        self.topics = []
        self.companies = []
        self.solutions = []

    def set_id(self, id):
        if not isinstance(id, int):
            raise TypeError("Question id must be int type")
        if self._id is not None:
            raise Exception("Question id can only be set for one time")
        self._id = id

    def set_title(self, title):
        if not isinstance(title, str):
            raise TypeError("Question title must be string type")
        if self._title is not None:
            raise Exception("Question title can only be set for one time")
        self._title = title

    def set_url(self, url):
        if not isinstance(url, str):
            raise TypeError("Question url must be string type")
        if self._url is not None:
            raise Exception("Question url can only be set for one time")
        self._url = url

    def set_soup(self, soup):
        if not isinstance(soup, BeautifulSoup):
            raise TypeError("Soup is not a valid BeautifulSoup object")
        if self._soup is not None:
            raise ValueError("Question soup can only be set for one time")
        self._soup = soup

    def get_id(self):
        if self._id is None:
            raise ValueError("Get question id before initialzaiton")
        return self._id

    def get_title(self):
        if self._title is None:
            raise ValueError("Get question title before initialization")
        return self._title

    def get_url(self):
        if self._url is None:
            raise ValueError("Get question url before initilization")
        return self._url

    def check_soup(self):
        if self._soup is None:
            raise ValueError("Get BeautifulSoup before initialization")

    def get_soup(self):
        self.check_soup()
        return self._soup

    def parse_sidebar(self):
        self.check_soup()
        return self._soup.find(class_="side-bar-list")

    def parse_details(self, side_bar_list):
        def parse_int(text):
            try:
                val = int(text)
            except ValueError:
                if text.endswith('K'):
                    val = int(float(text[:-1]) * 1000)
                elif text.endswith('M'):
                    val = int(float(text[:-1]) * 1000000)
                else:
                    raise ValueError("Invalid submission number")
            finally:
                return val

        items = side_bar_list.find_all(class_="list-item")
        for item in items:
            if len(item.contents) == 0:
                continue
            # print(item.contents[0])
            if item.contents[0].text.startswith('Difficulty'):
                self.level = item.contents[1].text.encode('utf-8')
            elif item.contents[0].text.startswith('Total Accepted'):
                self.total_accepted = parse_int(item.contents[1].text)
            elif item.contents[0].text.startswith('Total Submission'):
                self.total_submission = parse_int(item.contents[1].text)
        if self.total_accepted is not None and self.total_submission is not None:
            self.ac_rate = float(self.total_accepted) / self.total_submission

    def parse_tags(self, side_bar_list):
        try:
            side_bar = side_bar_list.find(id='tags-company')
            company_list = side_bar.find_all('a')
            for c in company_list:
                if isinstance(c.text, str):
                    self.companies.append(c.text)
                else:
                    self.companies.append(c.text.encode('utf-8'))
        except AttributeError:
            print("No company tags for " + self._title + " question")

        try:
            side_bar = side_bar_list.find(id="tags-topics")
            topic_list = side_bar.find_all('a')
            for topic in topic_list:
                if isinstance(topic.text, str):
                    self.topics.append(topic.text)
                else:
                    self.topics.append(topic.text.encode('utf-8'))
        except AttributeError:
            print("No topic tags for " + self._title + " question")

        try:
            side_bar = side_bar_list.find(id="tags-question")
            question_list = side_bar.find_all('a')
            for question in question_list:
                if isinstance(question.text, str):
                    self.similar_questions.append(question.text)
                else:
                    self.similar_questions.append(
                        question.text.encode('utf-8'))
        except AttributeError:
            print("No similar questions for " + self._title + " question")

    def parse_like_dislike(self):
        like = self._soup.find(class_='btn btn-default text-success ')
        if like is None:
            like = self._soup.find(
                class_='btn btn-default text-success active')
        text = like.text
        self.like = int(text)

        dislike = self._soup.find(class_='btn btn-default text-danger ')
        if dislike is None:
            dislike = self._soup.find(
                class_='btn btn-default text-danger active')
        text = dislike.text
        self.dislike = int(text)

    def check_attribute(self):
        assert isinstance(self._id, int) and self._id > 0
        assert isinstance(self._title, str)
        assert isinstance(self._url, str)
        assert isinstance(self.level,
                          str) and self.level in ['Easy', 'Medium', 'Hard']
        assert isinstance(self._paidOnly, bool)
        assert isinstance(self.total_submission,
                          int) and self.total_submission >= 0
        assert isinstance(self.total_accepted,
                          int) and self.total_accepted >= 0
        assert isinstance(self.ac_rate,
                          float) and self.ac_rate >= 0 and self.ac_rate <= 1
        assert isinstance(self.like, int) and self.like >= 0
        assert isinstance(self.dislike, int) and self.dislike >= 0

    def build(self):
        side_bar_list = self.parse_sidebar()
        if side_bar_list is None:
            print("Questions %d error occur " % self._id)
            return
        self.parse_details(side_bar_list)
        self.parse_tags(side_bar_list)
        self.parse_like_dislike()
        self.check_attribute()

    def write2disk(self, path):
        question_dict = {}
        question_dict['id'] = self._id
        question_dict['title'] = self._title
        question_dict['url'] = self._url
        question_dict['paid_only'] = self._paidOnly
        question_dict['frequency'] = self.frequency
        question_dict['level'] = self.level
        question_dict['total_submission'] = self.total_submission
        question_dict['total_accpeted'] = self.total_accepted
        question_dict['like'] = self.like
        question_dict['dislike'] = self.dislike
        question_dict['companies'] = self.companies
        question_dict['topics'] = self.topics
        question_dict['similar_questions'] = self.similar_questions
        question_dict['ac_rate'] = self.ac_rate

        fname = str(self._id) + " " + self._title
        assert (os.path.exists(path))
        with open(os.path.join(path, fname + '.txt'), 'w') as f:
            question_string = json.dumps(question_dict)
            f.write(question_string)
            f.close()
