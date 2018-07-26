
# Multithreading Fetch Leetcode

## Overview
This is a Python web crawler project aims at fetching Leetcode question information and personal accepted solutions. [Leetcode](https://leetcode.com/) is one of the most popular online judging website, it contains more than eight hundred technical interview questions up to now. The core method for fetching leetcode information is to use the [Selenium](https://www.seleniumhq.org/) python package. The selenium library can automatically control the web browser and fetch web pages with python code. This project can run in multithreading mode and Windows, Linux, MacOS operating system. This project is still in progress and further analysis will be added.

## Main Functions

This project mainly has three functions.

### 1. Fetching your personal Leetcode AC solutions.
Given your username and password, the program can automatically check all your AC solutions in Leetcode and save the source code into your local environment. 
### 2. Fetching all accessible Leetcode question information.
The program will fetch all question features for further analysis, such as the its frequencies in real interviews, like and dislike number, companies asked this question and all its similar questions. The program can save each question information to a ```txt``` file or save them into a single ```csv```file.
### 3. Automatically correct code style for your solutions
The program contains a ```Code_Style.py``` file. It is a python script to check and correct your code sytle. Only C++, Java and Python source code are supported now. You need to firstly install the [clang-format](https://clang.llvm.org/docs/ClangFormat.html) and [yafp](https://github.com/google/yapf) in your machine. See their website for installation guide and details

## Dependencies

* Python 2.7 
* Selenium 3.13.0 
* Chrome v66-68 
* ChromeDriver  2.40 
* bs4 4.5.1
* pandas 0.19.2 

## How to Run

* First, you need to install the pre-mentioned Chrome web browser in your machine. Then, download the ChromeDriver for your platform from [here](http://chromedriver.chromium.org/downloads). Please notice the version of Chrome and ChromeDriver should be consistent. Other versions of driver may also work but the version mentioned above is most recommended. 

* Extract the chromedriver/chromedriver.exe file to the ```bin``` directory. Also, add the chromeDriver location to your PATH environment variable. See [here](http://chromedriver.chromium.org/getting-started) if you need help.

* Input your Leetcode username and password into the ```data/config.txt``` file.

* After above steps, you can start fetching your Leetcode. Enter the Fetch_Leetcode path and execute:

    ``` python main.py -m s ``` <br></br>
    This command will fetch all your Leetcode AC solutions and save them to the ```data/Submission``` directory<br></br>
    ``` python main.py -m q ```<br></br>
    This command will fetch all Leetcode questions information and save them to the ```data/Questions``` directory<br></br>
    This program supports breakpoint crawler. You can change the start page and start index in the problems main page by the following command:<br></br>
    ``` python main.py -m q -sp 5 -si 10 ``` <br></br>
    This will begin to fetch Leetcode questions from 5th page 10th question<br></br>
    ``` python main.py -m s -v ``` <br></br>
    This will fetch all submissions but make the backend chrome driver visible in screen. Please notice this option will significantly slow the program. 
    This crawler program supports multithreading. You can specify the number of threads by the following command: <br></br>
    ``` python main.py -m s -n 10 ``` <br></br>
    Please notice starting too many threads may slow the speed of url get request in your machine. So ```num_of_thread``` under 10 is recommended

* After fetching all AC solutions, you can check and correct your code style like this: <br></br>
``` python Code_Style.py -i ../data/Submission``` <br></br>

* After fetching all questions information, a csv file containing all question info can be generated: <br></br>
``` python to_csv.py ``` <br></br>
