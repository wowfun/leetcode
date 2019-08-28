#include<iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int one_before = 2, two_before = 1, ways;
    for (int i = 2; i < n; i++) {
      ways = one_before + two_before;
      two_before = one_before;
      one_before = ways;
    }
    return ways;
  }
};

// recursion
class Solution2 {
public:
  int climbStairs(int n) {
    int *memo = new int[n + 1]();
    return climbStairs(n, memo);
  }

  int climbStairs(int n, int *memo) {
    if (n < 2)return 1;
    if (memo[n] != 0)return memo[n];
    memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
    return memo[n];
  }
};
