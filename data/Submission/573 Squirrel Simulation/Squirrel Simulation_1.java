// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 573 Squirrel Simulation
// https://leetcode.com//problems/squirrel-simulation/description/
// Fetched at 2018-07-24
// Submitted 1 week, 2 days ago
// Runtime: 9 ms
// This solution defeats 33.12% java solutions

class Solution {
  public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
    int total_dist = 0;
    for (int i = 0; i < nuts.length; i++) {
      total_dist += Math.abs(nuts[i][0] - tree[0]) + Math.abs(nuts[i][1] - tree[1]);
    }
    total_dist *= 2;
    int min_dist = Integer.MAX_VALUE, dist = 0;
    for (int i = 0; i < nuts.length; i++) {
      dist =
          Math.abs(nuts[i][0] - squirrel[0])
              + Math.abs(nuts[i][1] - squirrel[1])
              - Math.abs(nuts[i][0] - tree[0])
              - Math.abs(nuts[i][1] - tree[1]);
      if (dist < min_dist) min_dist = dist;
    }
    return total_dist + min_dist;
  }
}
