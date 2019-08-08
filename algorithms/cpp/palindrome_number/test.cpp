#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)return false;
    int xs[64];
    int i = 0;
    while (x > 0) {
      xs[i++] = x % 10;
      x = x / 10;
    }
    i--;
    for (int left = 0; left < i; left++, i--) {
      if (xs[left] != xs[i])return false;
    }
    return true;
  }
};

int main() {
  Solution *s1 = new Solution();
  std::cout << s1->isPalindrome(1210);
  return 0;
}