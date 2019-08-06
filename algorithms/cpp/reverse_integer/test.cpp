#include <iostream>

class Solution {
 public:
  int reverse(int x) {
    long long rev_x = 0;
    int sign = 1;
    long long base = 1;
    if (x == INT_MIN) return 0;
    if (x < 0) {
      sign = -1;
      x = x * sign;
    }
    int x_copy = x;
    while (x_copy >= 10) {
      x_copy = x_copy / 10;
      base = base * 10;
    }
    while (x > 0) {
      rev_x = rev_x + (x % 10) * base;
      x = x / 10;
      base = base / 10;
    }
    rev_x = sign * rev_x;
    if (rev_x < INT_MIN || rev_x > INT_MAX) return 0;
    return rev_x;
  }
};

int main() {
  Solution *s1 = new Solution();
  std::cout << s1->reverse(10);
  return 0;
}