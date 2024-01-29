package leetcode.rotate_array;

public class Solution {
  static int BACKUP_DATA_IDX = 0;

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] nums = {1, 2, 3, 4, 5, 6, 7};
//    int[] nums = {-1, -100, 3, 99};
    int k = 2;
    solution.rotate(nums, k);
    for (int num : nums) {
      System.out.print(num + " ");
    }
  }

  public void rotate(int[] nums, int k) {
    int temp = backupData(nums, k);
    int idx = 0;
    for (int i = 0; i < nums.length; i++) {
      int nextIdx = getNextIdx(nums, k, idx);
      if (nextIdx == BACKUP_DATA_IDX) {
        nums[idx] = temp;
        break;
      } else {
        idx = rotateOneNumber(nums, k, idx);
      }
    }
  }

  private int getNextIdx(int[] nums, int k, int idx) {
    return (idx - k + nums.length) % nums.length;
  }

  private int backupData(int[] nums, int k) {
    return nums[0];
  }

  private int rotateOneNumber(int[] nums, int k, int idx) {
    int nextIdx = getNextIdx(nums, k, idx);
    nums[idx] = nums[nextIdx];
    return nextIdx;
  }
}