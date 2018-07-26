# coding:utf-8

import os
import json
import time
import re
import platform
from threading import Thread

from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException, NoSuchWindowException
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from bs4 import BeautifulSoup
from Question import Question
from Solution import Submission


class Leetcode:

    HOME_URL = "https://leetcode.com/"
    LOGIN_URL = "https://leetcode.com/accounts/login/"
    PROBLEM_URL = "https://leetcode.com/problemset/all/"
    SUBMISSION_URL = "https://leetcode.com/submissions/#/1"

    def __init__(self, num_thread=5,visible=False):
        # self.Questions = []
        self.num_thread = num_thread
        self.id2title = {}
        self.title2id = {
        }  #record questions that have been added to self.Questions
        self.username = None
        self.password = None
        self.target_status = []
        self.isPremium = False
        self.num_total_questions = 0
        self.num_solved = 0
        self.total_accepted = 0
        self.total_submission = 0
        self.cookies = None
        self.options = Options()
        if not visible:
            self.options.add_argument('--headless')
            self.options.add_argument('--disable-gpu')
        self.question_save_path = '../data/Questions'
        self.submission_save_path = '..data/Submissions'
        self.config_path = '../data/config.txt'
        self.account_save_path = '../data/Leetcode'

        system = platform.system()
        if system.startswith("Windows"):
            self.driver_path = "../bin/chromedriver.exe"
        elif system.startswith("Linux") or system.startswith("Mac"):
            self.driver_path = "../bin/chromedirver"
        else:
            raise RuntimeError("Your operating system cannot be recognized, "
                               "please run this program on Linux, Windows or Mac platform")
        self.page_driver = webdriver.Chrome(self.driver_path,chrome_options=self.options)
        if not os.path.exists(self.question_save_path):
            os.mkdir(self.question_save_path)

    @staticmethod
    def unicode_decode(string):
        pattern = re.compile('(\\\\u[0-9a-zA-Z]{4})')
        m = pattern.findall(string)
        for item in m:
            string = string.replace(item, chr(int(item[2:],
                                                  16)))  # item[2:]去掉\u
        return string

    def login(self):
        if not os.path.exists(self.config_path):
            raise Exception(
                "config file doesn't exist, please add config.txt to your current path"
            )
        config = {}
        f = open(self.config_path, 'r')
        for line in f:
            inputs = line.split(':')
            if len(inputs) < 2:
                raise ValueError(
                    "Invalid config input, please check your config.txt")
            config[inputs[0]] = inputs[1].rstrip('\n')

        if 'username' not in config:
            raise ValueError(
                "Missed username, please check your config.txt file")
        if 'password' not in config:
            raise ValueError(
                "Missed password, please check your config.txt file")
        print("Logging into Leetcode...")
        self.page_driver.get(Leetcode.LOGIN_URL)
        try:
            WebDriverWait(self.page_driver, 15).until(
                EC.presence_of_element_located((By.ID, "id_login")))
        except TimeoutException:
            self.page_driver.close()
            raise RuntimeError(
                "Fail to open the login page within time limit, please check your Internet"
            )
        time.sleep(1)

        self.page_driver.find_element_by_id('id_login').send_keys(
            config['username'])
        self.page_driver.find_element_by_id('id_password').send_keys(
            config['password'])
        self.page_driver.find_element_by_xpath(
            '//button[@type="submit"]').click()

        try:
            WebDriverWait(self.page_driver, 10).until(
                EC.title_contains(
                    "LeetCode - The World's Leading Online Programming Learning Platform"
                ))
        except TimeoutException:
            self.page_driver.close()
            raise RuntimeError(
                "Fail to log into Leetcode,please check your username and password or Internet"
            )

        print("Successfully Log into Leetcode")
        if len(self.page_driver.find_elements_by_id("subscribe")) == 0:
            self.isPremium = True
            print("Congratulations! You are a Premium user")

        self.cookies = self.page_driver.get_cookies()

    def is_login(self):
        try:
            cookie_page = self.page_driver.get_cookie("LEETCODE_SESSION")
            if cookie_page is not None:
                return True
            else:
                return False
        except NoSuchWindowException:
            print("browse was closed!")
            return False

    def load_cookies(self):
        if not os.path.exists('cookie.txt'):
            self.login()
        f = open(self.account_save_path, 'r')
        cookies = json.loads(f)
        self.cookies = cookies
        return cookies

    def fetch_question_page(self, page_url, start_page=1, start_index=1):
        if not self.is_login():
            self.login()
        self.page_driver.get(page_url)

        try:
            WebDriverWait(self.page_driver, 10).until(
                EC.presence_of_element_located((By.TAG_NAME, "tr")))
        except TimeoutException:
            self.page_driver.close()
            raise RuntimeError(
                "Fail to open the submission page within time limit, please check your Internet"
            )

        for i in range(1, start_page):
            try:
                self.page_driver.find_element_by_class_name(
                    "reactable-next-page").click()
            except NoSuchElementException:
                print("Reaching the final page")
                break

        page = start_page

        question_list = []
        while True:
            try:
                WebDriverWait(self.page_driver, 10).until(
                    EC.presence_of_element_located((By.TAG_NAME, "tr")))
            except TimeoutException:
                self.page_driver.close()
                raise RuntimeError(
                    "Fail to load the problem page, please check your Internet"
                )

            soup = BeautifulSoup(self.page_driver.page_source, 'lxml')
            trs = soup.find_all("tr")
            index = 0
            if page == start_page:
                index = start_index
            for tr in trs[index:]:
                if tr.find("th") is not None or tr.find(
                        class_="row-selector") is not None:
                    continue
                else:
                    tds = tr.find_all("td")
                    question_id = int(tds[1].text)
                    question_title = str(''.join(
                        list((filter(lambda x: x not in " ?.*<>|\/:",
                                     tds[2].find('a').text)))))
                    question_url = str(Leetcode.HOME_URL[:-1] +
                                       tds[2].find('a').attrs['href'] +
                                       "/description/")
                    frequency = tds[-1].attrs['value']
                    paid_only = tds[2].find(class_="fa fa-unlock") is not None
                    self.num_total_questions += 1
                    if tds[0].has_attr(
                            "value") and tds[0].attrs['value'] == 'ac':
                        self.num_solved += 1
                    if paid_only and not self.isPremium:
                        continue
                    question = Question(
                        id=question_id,
                        title=question_title,
                        url=question_url,
                        paidOnly=paid_only,
                        frequency=frequency)
                    question_list.append(question)
                    if question_id in self.id2title:
                        raise ValueError("Question Id already in the dict")
                    if question_title in self.title2id:
                        raise ValueError("Question title already in the dict")
                    self.id2title[question_id] = question_title
                    self.title2id[question_title] = question_id

            time.sleep(1)
            try:
                self.page_driver.find_element_by_class_name(
                    "reactable-next-page").click()
                page += 1
            except NoSuchElementException:
                break
        self.page_driver.close()
        print(
            "Successfully got all questions url, there are total %d questions"
            % (self.num_total_questions))

        threads = []
        questions_per_thread = (
            self.num_total_questions + 1) // self.num_thread
        for i in range(0, self.num_total_questions, questions_per_thread):
            thread = Thread(
                target=self.fetch_question,
                args=(question_list, i,
                      min(i + questions_per_thread, self.num_total_questions)))
            threads.append(thread)
            thread.start()
        for t in threads:
            t.join()

        print("Successfully Fetched all questions information")
        self.write2disk(save_path=self.account_save_path)

    def fetch_submission_page(self,
                              submission_page_url,
                              start_page=1,
                              start_index=1):
        if not self.is_login():
            self.login()
        self.page_driver.get(submission_page_url)
        try:
            WebDriverWait(self.page_driver, 10).until(
                EC.presence_of_element_located((By.TAG_NAME, "tr")))
        except TimeoutException:
            self.page_driver.close()
            raise RuntimeError(
                "Fail to open the submission page within time limit, please check your Internet"
            )

        for i in range(1, start_page):
            try:
                next = self.page_driver.find_element_by_class_name("next")
                button = next.find_element_by_tag_name("a")
                button.click()
                try:
                    WebDriverWait(self.page_driver, 10).until(
                        EC.presence_of_element_located((By.CLASS_NAME,
                                                        "next")))
                except TimeoutException:
                    self.page_driver.close()
                    raise RuntimeError(
                        "Fail to enter the next submission page within time limit, "
                        "please check your Internet")

            except NoSuchElementException:
                print("Reaching the final page")
                break

        page = start_page
        ac_submission_list = []

        while True:
            try:
                WebDriverWait(self.page_driver, 15).until(
                    EC.presence_of_element_located((By.TAG_NAME, "tr")))
            except TimeoutException:
                self.page_driver.close()
                raise RuntimeError(
                    "Fail to load the submission page, please check your Internet"
                )

            soup = BeautifulSoup(self.page_driver.page_source, 'lxml')
            trs = soup.find_all("tr")
            index = 1
            if page == start_page:
                index = start_index

            for tr in trs[index:]:
                tds = tr.find_all("td")
                status = tds[2].text.strip()
                if status == 'Accepted':
                    submit_time = str(" ".join(tds[0].text.split()))
                    question_title = str(tds[1].text.strip(" ?.*<>|\/:"))
                    submission_url = Leetcode.HOME_URL + tds[2].find(
                        "a").attrs['href']
                    runtime = int(tds[3].text.strip()[:-2])
                    lang = str(tds[4].text.strip())
                    submission = Submission(question_title, submit_time,
                                            status, submission_url, runtime,
                                            lang)
                    ac_submission_list.append(submission)
                    self.total_accepted += 1
                self.total_submission += 1
            try:
                self.page_driver.find_element_by_css_selector(
                    "[class='next disabled']")
                break
            except NoSuchElementException:
                next = self.page_driver.find_element_by_class_name("next")
                button = next.find_element_by_tag_name("a")
                button.click()
                page += 1
        print(
            "Finished getting all accepted solution list, there are total %d AC submission"
            % self.total_accepted)

        threads = []
        url_per_thread = (self.total_accepted + 1) // self.num_thread
        for i in range(0, self.total_accepted, url_per_thread):
            thread = Thread(
                target=self.fetch_submission(
                    ac_submission_list, i,
                    min(i + url_per_thread, len(ac_submission_list))))
            threads.append(thread)
            thread.start()
        for t in threads:
            t.join()
        print("Finish fetching all accepted submission")
        self.page_driver.close()

    def fetch_question(self, question_list, start_index, end_index):
        driver = webdriver.Chrome(self.driver_path, chrome_options=self.options)
        driver.get(Leetcode.HOME_URL)

        for c in self.cookies:
            driver.add_cookie(c)

        for question in question_list[start_index:end_index]:
            print("Fetching question " + str(question.get_id()) + " " +
                  question.get_title())
            driver.get(question.get_url())
            try:
                WebDriverWait(driver, 150).until(
                    EC.presence_of_element_located((By.CLASS_NAME,
                                                    "like-and-dislike")))
            except TimeoutException:
                print(
                    "Fail to load the question %s within time limit,please check your Internet"
                    % (str(question.get_id()) + " " + question.get_title()))
            soup = BeautifulSoup(driver.page_source, 'lxml')
            question.set_soup(soup)
            question.build()
            save_path = os.path.join(
                self.question_save_path,
                str(question.get_id()) + " " + question.get_title())
            if not os.path.exists(save_path):
                os.mkdir(save_path)
            question.write2disk(save_path)
            time.sleep(3)

        driver.close()

    def fetch_submission(self, submission_list, start_index, end_index):
        driver = webdriver.Chrome(self.driver_path, chrome_options=self.options)
        driver.get(Leetcode.HOME_URL)
        for c in self.cookies:
            driver.add_cookie(c)
        for submission in submission_list[start_index:end_index]:
            print("Fetching Submission " + submission.submit_time)
            driver.get(submission.submission_url)

            try:
                WebDriverWait(driver, 15).until(
                    EC.presence_of_element_located((By.ID, "edit-code-btn")))
            except TimeoutException:
                driver.close()
                raise RuntimeError(
                    "Fail to load the submission page within time limit,please check your Internet"
                )

            pattern = re.compile(
                r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl', re.S)
            id_pattern = re.compile(
                r'questionId: \'(?P<id>.*)\',\n  sessionId', re.S)

            source_code = re.search(pattern,
                                    driver.page_source).groupdict()['code']
            source_code = Leetcode.unicode_decode(source_code)
            submission._source_code = str(source_code)
            question_id = re.search(
                id_pattern,
                driver.page_source).groupdict()['id'].encode('utf-8')
            submission.question_id = int(question_id)
            soup = BeautifulSoup(driver.page_source, 'lxml')
            submission.set_soup(soup)
            submission.fetch_defeat()
            submission.check_attribute()
            save_path = os.path.join(
                self.submission_save_path,
                str(submission.question_id) + " " + submission.question_title)
            if not os.path.exists(save_path):
                os.mkdir(save_path)
            submission.write2disk(save_path)
        driver.close()

    def write2disk(self, save_path):
        if not os.path.exists(save_path):
            os.mkdir(save_path)
        f = open(os.path.join(save_path, 'id2title.txt'), 'w')
        f.write(json.dumps(self.id2title))
        f.close()

        f = open(os.path.join(save_path, 'title2id.txt'), 'w')
        f.write(json.dumps(self.title2id))
        f.close()

        params = {}
        params['username'] = self.username
        params['password'] = self.password
        params['isPremium'] = self.isPremium
        params['num_questions'] = self.num_total_questions
        params['num_sovled'] = self.num_solved

        f = open(os.path.join(save_path, 'Leetcode.txt'), 'w')
        f.write(json.dumps(params))
        f.close()
