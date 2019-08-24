#include<iostream>
#include <vector>

using namespace std;

// 3 solutions:

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    vector<int> curr_row;
    for (int i = 0; i < numRows; i++) {
      curr_row.push_back(1);
      for (int j = i - 1; j > 0; j--) {
        curr_row[j] = curr_row[j - 1] + curr_row[j];
      }
      res.push_back(curr_row);
    }
    return res;
  }
};

// dp
class Solution2 {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int>> res(numRows);
    for (int i = 0; i < numRows; i++) {
      res[i].resize(i + 1);
      res[i][0] = res[i][i] = 1;
      for (int j = 1; j < i; j++)
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    return res;
  }
};

// recursion
class Solution3 {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows <= 0) return res;
    generate(res, 0, numRows);
    return res;
  }

  void generate(vector<vector<int>> &v, int curr_row, int numRows) {
    if (curr_row > numRows - 1) return;
    vector<int> lvl;
    for (int col = 0; col <= curr_row; col++) {
      if (col == 0 || col == curr_row) {
        lvl.push_back(1);
        continue;
      }
      lvl.push_back(v[curr_row - 1][col] + v[curr_row - 1][col - 1]);
    }
    v.push_back(lvl);
    generate(v, curr_row + 1, numRows);
  }
};