#include"solution.cpp"

int main() {
  auto s1 = new Solution();  // or Solution2
  vector<char> s = {};
  s1->reverseString(s);
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it;
  return 0;
}

