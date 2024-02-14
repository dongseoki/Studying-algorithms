package leetcode.single_number;

import java.util.Arrays;

public class Solution {
  public int singleNumber(int[] nums) {
    Arrays.sort(nums);
    int length = nums.length;
    final int EMPTY = 9999999;
    int dupNum = EMPTY;
    for (int i = 0; i < length; i++) {
      if (i == length - 1) {
        return nums[i];
      }
      if (i == 0) {
        if (nums[i] != nums[i + 1]) {
          return nums[i];
        }
        continue;
      }
      if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
        return nums[i];
      }
    }
    return 0;
  }

  public static void main(String[] args) {

  }
}