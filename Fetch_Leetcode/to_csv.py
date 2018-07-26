import os
import json
from tqdm import tqdm

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


def question2csv(input_dir):
    question_dir = input_dir
    question_list = os.listdir(question_dir)
    df = pd.DataFrame(index=['id'],columns={'dislike', 'level', 'topics', 'title', 'ac_rate',
                                        'similar_questions', 'total_accpeted', 'paid_only', 'total_submission', 'frequency',
                                        'companies', 'url', 'like'})

    for question in tqdm(question_list):
        fname = os.path.join(question_dir, question, question+".txt")
        f = open(fname)
        q_dict = json.loads(f.read())
        df = df.append(q_dict,ignore_index=True)
        f.close()
    df = df.dropna(how='all')
    df.to_csv("../data/question.csv",index=False)

if __name__ == '__main__':
    question2csv("../data/Questions")
    print("Successfully write question information to csv file","See /data/question.csv for details")