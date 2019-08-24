#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int n=s.size();
    for(int i=0;i<n/2;i++){
      swap(s[i],s[n-1-i]);
    }
  }
};

// recursion
class Solution2 {
public:
  void reverseString(vector<char> &s) {
    recursion(s, 0, s.size() - 1);
  }

  void recursion(vector<char> &s, int begin, int end) {
    if (begin >= end) return;
    swap(s[begin], s[end]);
    recursion(s, begin + 1, end - 1);
  }
};