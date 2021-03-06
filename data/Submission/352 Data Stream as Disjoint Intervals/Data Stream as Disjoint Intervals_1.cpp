//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 352 Data Stream as Disjoint Intervals
// https://leetcode.com//problems/data-stream-as-disjoint-intervals/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 136 ms
// This solution defeats 5.47% cpp solutions

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
 public:
  /** Initialize your data structure here. */
  SummaryRanges() : maximam(INT_MAX), mini(INT_MIN) {}

  void addNum(int val) {
    if (interval.empty()) {
      interval.push_back(Interval(val, val));
      mini = val;
      maximam = val;
      return;
    }
    if (val > maximam) {
      if (val - maximam > 1) {
        interval.push_back(Interval(val, val));
      } else {
        interval[interval.size() - 1].end++;
      }
      maximam = val;
    } else if (val < mini) {
      if (mini - val > 1) {
        interval.insert(interval.begin(), Interval(val, val));
      } else {
        interval[0].start--;
      }
      mini = val;
    } else {
      int low = 0, high = interval.size() - 1;
      while (high >= low) {
        int mid = (low + high) / 2;
        if (val >= interval[mid].start && val <= interval[mid].end) {
          return;
        } else if (val < interval[mid].start) {
          high = mid - 1;
        } else if (val > interval[mid].end) {
          low = mid + 1;
        }
      }
      if (interval[low].start - val == 1) {
        interval[low].start--;
        if (low - 1 >= 0 && interval[low].start == interval[low - 1].end + 1) {
          interval[low - 1].end = interval[low].end;
          interval.erase(interval.begin() + low);
        }
      } else if (interval[high].end + 1 == val) {
        interval[high].end++;
        if (high + 1 < interval.size() &&
            interval[high].end + 1 == interval[high + 1].start) {
          interval[high].end = interval[high + 1].end;
          interval.erase(interval.begin() + high + 1);
        }
      } else {
        interval.insert(interval.begin() + low, Interval(val, val));
      }
    }
  }

  vector<Interval> getIntervals() { return interval; }
  vector<Interval> interval;
  int maximam;
  int mini;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */