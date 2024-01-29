package leetcode.permu_comb_test;

public class Duplication_Permutation {
  public static void permutation(int[] arr, int[] out, int depth, int r) {
    if (depth == r) {
      for (int num : out) {
        System.out.print(num);
      }
      System.out.println();
      return;
    }
    for (int i = 0; i < arr.length; i++) {
      out[depth] = arr[i];
      permutation(arr, out, depth + 1, r);
    }
  }

  public static void main(String[] args) {
    int[] arr = {1, 2, 3};
    int r = 2;
    permutation(arr, new int[r], 0, r);
  }
}
