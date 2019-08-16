#include<iostream>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.size() % 2 != 0)
      return false;
    stack<char> parentheses;
    for (char& c: s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          parentheses.push(c);
          break;
        case ')':
          if (parentheses.empty() || parentheses.top() != '(')return false;
          parentheses.pop();
          break;
        case ']':
          if (parentheses.empty() || parentheses.top() != '[')return false;
          parentheses.pop();
          break;
        case '}':
          if (parentheses.empty() || parentheses.top() != '{')return false;
          parentheses.pop();
          break;
        default:;
      }
    }
    return parentheses.empty();
  }
};
