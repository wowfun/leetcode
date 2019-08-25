#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    for (int i = 0; i <= rowIndex; i++) {
      res.push_back(1);
      for (int j = i - 1; j > 0; j--) {
        res[j] = res[j - 1] + res[j];
      }
    }
    return res;
  }
};

// recursion
class Solution2 {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex == 0) return {1};
    vector<int> v = getRow(rowIndex - 1);
    int n = v.size();
    for (int i = n - 1; i > 0; i--)
      v[i] = v[i - 1] + v[i];
    v.push_back(1);
    return v;
  }
};