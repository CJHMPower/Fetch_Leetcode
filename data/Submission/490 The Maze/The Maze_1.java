// -*- coding:utf-8 -*-
// Generated by the Fetch-Leetcode project on the Github
// https://github.com/CJHMPower/Fetch-Leetcode/

// 490 The Maze
// https://leetcode.com//problems/the-maze/description/
// Fetched at 2018-07-24
// Submitted 3 months, 1 week ago
// Runtime: 13 ms
// This solution defeats 20.43% java solutions

public class Solution {
  public boolean hasPath(int[][] maze, int[] start, int[] destination) {
    // dfs
    if (maze == null || start == null || destination == null) {
      return false;
    }
    boolean[][] visited = new boolean[maze.length][maze[0].length];
    return hasPath(maze, start, destination, visited);
  }

  private boolean hasPath(int[][] maze, int[] start, int[] dest, boolean[][] visited) {
    int y = start[0];
    int x = start[1];
    if (visited[y][x]) return false;
    visited[y][x] = true;
    if (x == dest[1] && y == dest[0]) {
      return true;
    }
    // left
    if (x > 0 && maze[y][x - 1] != 1) {
      int i = x - 1;
      while (i > 0 && maze[y][i - 1] != 1) i--;
      if (hasPath(maze, new int[] {y, i}, dest, visited)) return true;
    }
    // right
    if (x < maze[0].length - 1 && maze[y][x + 1] != 1) {
      int i = x + 1;
      while (i < maze[0].length - 1 && maze[y][i + 1] != 1) i++;
      if (hasPath(maze, new int[] {y, i}, dest, visited)) return true;
    }
    // up
    if (y > 0 && maze[y - 1][x] != 1) {
      int i = y - 1;
      while (i > 0 && maze[i - 1][x] != 1) i--;
      if (hasPath(maze, new int[] {i, x}, dest, visited)) return true;
    }
    // down
    if (y < maze.length - 1 && maze[y + 1][x] != 1) {
      int i = y + 1;
      while (i < maze.length - 1 && maze[i + 1][x] != 1) i++;
      if (hasPath(maze, new int[] {i, x}, dest, visited)) return true;
    }
    return false;
  }
}
