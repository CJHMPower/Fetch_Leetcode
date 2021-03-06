//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 57 Insert Interval
// https://leetcode.com//problems/insert-interval/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 26 ms
// This solution defeats 6.3% cpp solutions

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  bool islap(Interval& a, Interval& b) { return a.end >= b.start; }
  Interval imerge(Interval a, Interval b) {
    return Interval(a.start, max(a.end, b.end));
  }
  vector<Interval> merge(vector<Interval>& intervals) {
    auto cmp = [](Interval a, Interval b) { return a.start < b.start; };
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> result;
    if (intervals.empty()) {
      return result;
    }
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      Interval tp = result.back();
      if (islap(tp, intervals[i]) == true) {
        result.pop_back();
        Interval temp = imerge(tp, intervals[i]);
        result.push_back(temp);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
  }
};