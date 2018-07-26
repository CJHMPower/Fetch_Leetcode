#-*- coding:utf-8 -*-
#Generated by the Fetch-Leetcode project on the Github
#https://github.com/CJHMPower/Fetch-Leetcode/

#165 Compare Version Numbers
#https://leetcode.com//problems/compare-version-numbers/description/
#Fetched at 2018-07-24
#Submitted 1 year, 10 months ago
#Runtime: 59 ms


class Solution(object):
    def compareVersion(self, version1, version2):
        """

        :type version1: str

        :type version2: str

        :rtype: int

        """

        list1 = version1.split('.')

        list2 = version2.split('.')

        length = min(len(list1), len(list2))

        for i in range(0, length):

            if (int(list1[i]) < int(list2[i])):

                return -1

            elif (int(list1[i]) > int(list2[i])):

                return 1

        if (len(list1) > len(list2)):

            for i in range(length, len(list1)):

                if (int(list1[i]) > 0):

                    return 1

            return 0

        elif (len(list1) < len(list2)):

            for i in range(length, len(list2)):

                if (int(list2[i]) > 0):

                    return -1

            return 0

        else:

            return 0