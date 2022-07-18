package leetcode.Sort_Colors;

class Solution {
    public void sortColors(int[] nums) {

        
        
        // for test
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