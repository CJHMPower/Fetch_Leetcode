# code --utf-8--

from Leetcode import Leetcode
import time
from optparse import OptionParser

if __name__ == '__main__':

    parser = OptionParser()
    parser.add_option('-m', '--mode question or solution', dest='mode', default='s')
    parser.add_option('-n', '--num of threads',dest='num_thread',default=5)
    parser.add_option('--sp', '--start page for fetching',dest='start_page',default=1)
    parser.add_option('--si','--start index for fetching', dest='start_index',default=1)
    parser.add_option('-v','--chrome browser is visible or not',dest='visible',default=False)
    options, args = parser.parse_args()

    if not options.visible:
        leetcode = Leetcode(num_thread=options.num_thread,visible=False)
    else:
        leetcode = Leetcode(num_thread=options.num_thread, visible=True)

    if options.mode == 's':
        start = time.time()
        leetcode.fetch_submission_page(
             Leetcode.SUBMISSION_URL, start_page=int(options.start_page), start_index=int(options.start_index))
        end = time.time()
        print ("Total time cost for fetching solutions : %.4f s"%(end - start))
    elif options.mode == 'q':
        start = time.time()
        leetcode.fetch_question_page(
             Leetcode.PROBLEM_URL, start_page=int(options.start_page), start_index=int(options.start_index))
        end = time.time()
        print("Total time cost for fetching questions information : %.4f s" % (end - start))
