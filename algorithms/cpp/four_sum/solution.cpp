#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int size_nums = nums.size();
    for (int i = 0; i < size_nums - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;  // Key
      if (nums[i] + nums[size_nums - 3] + nums[size_nums - 2] + nums[size_nums - 1] < target) continue; // Key
      for (int j = i + 1; j < nums.size() - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break; // Key
        if (nums[i] + nums[j] + nums[size_nums - 2] + nums[size_nums - 1] < target) continue; // Key
        int curr_target = target - nums[i] - nums[j];
        int left = j + 1, right = nums.size() - 1;
        while (left < right) {
          if (nums[left] + nums[right] == curr_target) {
            result.push_back({nums[i], nums[j], nums[left], nums[right]});
            left++;
            right--;
            while (left < right && nums[left] == nums[left - 1])left++;
            while (left < right && nums[right] == nums[right + 1])right--;
          } else if (nums[left] + nums[right] > curr_target)right--;
          else left++;
        }
      }
    }
    return result;
  }
};