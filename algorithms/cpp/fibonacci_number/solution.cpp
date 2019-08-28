#include<iostream>
#include <memory.h>

using namespace std;

class Solution {
public:
  int fib(int N) {
    if (N < 2)
      return N;
    int a = 0, b = 1, c;
    for (int i = 1; i < N; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};

// recursion
class Solution2 {
public:
  int fib(int N) {
    int *fibmemo = new int[N + 1]();
    return fib(N, fibmemo);
  }

  int fib(int N, int *memo) {
    if (N < 2)return N;
    if (memo[N] != 0)return memo[N];
    memo[N] = fib(N - 1, memo) + fib(N - 2, memo);
    return memo[N];
  }
};