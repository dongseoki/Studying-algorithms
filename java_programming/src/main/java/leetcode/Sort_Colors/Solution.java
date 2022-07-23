package leetcode.Sort_Colors;

class Solution {
    public void sortColors(int[] nums) {

        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if(nums[i]>nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        
        
//         for test
        for (int item:nums
             ) {
            System.out.println("item = " + item);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.sortColors(new int[]{2, 0, 2, 1, 1, 0});
    }
}