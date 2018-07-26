//-*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 690 Employee Importance
// https://leetcode.com//problems/employee-importance/description/
// Fetched at 2018-07-24
// Submitted 6 months ago
// Runtime: 249 ms

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
 public:
  map<int, int> Hash(vector<Employee*> employees) {
    map<int, int> index;
    for (int i = 0; i < employees.size(); i++) {
      index[employees[i]->id] = i;
    }
    return index;
  }
  int getImportance(vector<Employee*> employees, int id) {
    map<int, int> index = Hash(employees);

    int ret = employees[index[id]]->importance;
    if (employees[index[id]]->subordinates.size() == 0) {
      return ret;
    } else {
      for (int i = 0; i < employees[index[id]]->subordinates.size(); i++) {
        ret += getImportance(employees, employees[index[id]]->subordinates[i]);
      }
    }
    return ret;
  }
};