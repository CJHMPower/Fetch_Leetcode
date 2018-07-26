#-*- coding:utf-8 -*-
#Generated by the Fetch-Leetcode project on the Github
#https://github.com/CJHMPower/Fetch-Leetcode/

#520 Detect Capital
#https://leetcode.com//problems/detect-capital/description/
#Fetched at 2018-07-24
#Submitted 1 year, 1 month ago
#Runtime: 56 ms


class Solution(object):
    def detectCapitalUse(self, word):
        """

        :type word: str

        :rtype: bool

        """

        sign = (word[0] >= 'A' and word[0] <= 'Z')

        title = sign

        for c in word[1:]:

            case = c >= 'A' and c <= 'Z'

            if case == True:

                title = False

            if case != sign:

                if title == True:

                    sign = False

                    title = False

                else:

                    return False

        return True
