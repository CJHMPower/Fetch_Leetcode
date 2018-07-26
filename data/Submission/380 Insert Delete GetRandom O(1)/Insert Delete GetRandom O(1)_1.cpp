//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 380 Insert Delete GetRandom O(1)
// https://leetcode.com//problems/insert-delete-getrandom-o(1)/description/
// Fetched at 2018-07-24
// Submitted 1 year, 10 months ago
// Runtime: 275 ms

class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (data.find(val) != data.end()) {
      return false;
    } else {
      data.insert(val);
    }
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (data.find(val) == data.end()) {
      return false;
    } else {
      data.erase(val);
    }
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    uniform_int_distribution<int> u(0, data.size() - 1);
    int val = u(e);
    auto it = data.begin();
    for (int i = 0; i < val; i++) {
      it++;
    }
    return *it;
  }
  set<int> data;
  default_random_engine e;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */