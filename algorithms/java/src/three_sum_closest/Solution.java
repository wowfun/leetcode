package three_sum_closest;

import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int closestDistance = nums[0] + nums[1] + nums[2] - target;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int distance = nums[i] + nums[left] + nums[right] - target;
                if (distance == 0) {
                    return target;
                } else if (Math.abs(distance) < Math.abs(closestDistance)) closestDistance = distance;
                if (distance < 0) left++;
                else right--;
            }

        }
        return closestDistance + target;
    }
}
