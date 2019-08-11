package two_sum;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] s;
        for (int i=0;i<nums.length;i++){
            int b=target-nums[i];
            for (int j=i+1;j<nums.length;j++){
                if(nums[j]==b){
                    return new int[] {i,j};
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

