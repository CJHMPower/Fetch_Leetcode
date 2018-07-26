#-*- coding:utf-8 -*-
#Generated by the Fetch-Leetcode project on the Github
#https://github.com/CJHMPower/Fetch-Leetcode/

#435 Non-overlapping Intervals
#https://leetcode.com//problems/non-overlapping-intervals/description/
#Fetched at 2018-07-24
#Submitted 10 months ago
#Runtime: 59 ms
#This solution defeats 10.11% python solutions

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e


class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if len(intervals) < 2:
            return 0
        intervals = sorted(intervals, key=lambda x: (x.start, x.end))
        ret = 0
        pre = 0
        i = 1
        while (i < len(intervals)):
            if intervals[i].start < intervals[pre].end:
                ret += 1
                if intervals[i].end < intervals[pre].end:
                    pre = i
                i += 1
            else:
                pre = i
                i += 1
        return ret