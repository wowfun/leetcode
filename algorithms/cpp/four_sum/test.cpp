#include"solution.cpp"

int main() {
  vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
  auto *s1 = new Solution();
  auto res = s1->fourSum(nums, -11);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j]<<',';
    }
    cout<<endl;
  }
}