# coding:utf-8

import os
import urllib

from optparse import OptionParser


def check_file(file_name):
    if file_name.endswith(".cpp"):
        os.system('clang-format -style=Google -i "%s"' % file_name)
    elif file_name.endswith(".java"):
        os.system(
            'java -jar google-java-format-1.6-all-deps.jar --replace "%s"' %
            file_name)
    elif file_name.endswith(".py"):
        os.system('yapf --style pep8 -i "%s"' % file_name)


def check_directory(input_dir):
    if not os.path.exists(input_dir):
        raise Exception("Input dir %s does not exist" % input_dir)
    path_list = os.listdir(input_dir)
    for path in path_list:
        next_path = os.path.join(input_dir, path)
        if os.path.isfile(next_path):
            print("Checking source code ", path)
            check_file(next_path)
        else:
            check_directory(next_path)


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option(
        '-i',
        '--input_dir',
        dest='i',
        default='../data/Submission',
        help='Input dir for source code directy')
    if not os.path.exists("../bin/google-java-format-1.6-all-deps.jar"):
        url = "https://github.com/google/google-java-format/releases/download/google-java-format-1.6/google-java-format-1.6-all-deps.jar"
        urllib.urlretrieve(url, "../bin/google-java-format-1.6-all-deps.jar")
    options, args = parser.parse_args()
    input_dir = options.i
    check_directory(input_dir)
