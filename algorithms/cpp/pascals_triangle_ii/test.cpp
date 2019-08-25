#include"solution.cpp"

int main() {
  auto s1 = new Solution();  // or Solution2 by recursion
  auto res = s1->getRow(3);
  for (auto it: res) cout << it << ',';

  return 0;
}

