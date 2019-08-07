#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int sign = 1;
    long long base = 1;
    int loc_start;

    for (int i = 0; i < str.length(); i++) {
      if (str[i] == ' ') continue;
      else if (str[i] == '-') {
        if (str[i+1]<'0'||str[i+1]>'9') return 0;
        sign = -1;
        continue;
      } else if (str[i] == '0' || str[i] == '+') {
        if (str[i+1]<'0'||str[i+1]>'9') return 0;
        continue;
      } else if ('0' < str[i] && str[i] <= '9') {
        loc_start = i;
        for (; i < str.length(); i++) {
          if (base > LONG_LONG_MAX / 10) break;
          if ('0' <= str[i] && str[i] <= '9') {
            base = base * 10;
            continue;
          } else break;
        }
        long long num = 0;
        for (int j = loc_start; j < i; j++) {
          base = base / 10;
          num = num + (str[j] - '0') * base;
        }
        num = sign * num;
        if (num < INT32_MIN)return INT32_MIN;
        else if (num > INT32_MAX)return INT32_MAX;
        else return num;
      } else return 0;
    }
    return 0;
  }
};

int main() {
  Solution *s1 = new Solution();
  cout << s1->myAtoi("-+2");
  return 0;
}