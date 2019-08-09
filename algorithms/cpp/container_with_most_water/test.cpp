#include <iostream>
#include <vector>

using namespace std;

// slower solution
class Solution1 {
public:
  int maxArea(vector<int> &height) {
    int i_right = height.size() - 1;
    int max_area = 0;
    int curr_area;
    for (int i_left = 0; i_left < i_right; i_left++) {
      for (int i_right_tmp = i_right; i_left < i_right_tmp; i_right_tmp--) {
        curr_area = height[i_left] > height[i_right_tmp] ?
                    height[i_right_tmp] * (i_right_tmp - i_left) : height[i_left] * (i_right_tmp - i_left);
        if (curr_area > max_area) max_area = curr_area;
      }
    }
    return max_area;
  }
};

// faster solution
class Solution2 {
public:
  int maxArea(vector<int> &height) {
    int i_left = 0, i_right = height.size() - 1;
    int max_area = 0;
    int curr_area;
    while (i_left < i_right) {
      curr_area = height[i_left] > height[i_right] ?
                  height[i_right] * (i_right - i_left) : height[i_left] * (i_right - i_left);
      if (curr_area > max_area) max_area = curr_area;
      if (height[i_left] > height[i_right])
        i_right--;
      else i_left++;
    }
    return max_area;
  }
};

int main() {
  vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution1 *s1 = new Solution1();
  cout << s1->maxArea(vec)<<endl;
  Solution2 *s2 =new Solution2 ();
  cout << s2->maxArea(vec);
  return 0;
}