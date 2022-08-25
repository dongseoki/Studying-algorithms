package leetcode.MajorityElement;

import java.util.Arrays;

class Solution {
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        int count = 0;
        int base = -1;
        boolean isItInitialized = false;
        int answer = 0;

        int idx = 0;
        while(true){
//            System.out.println("idx = " + idx);
//            System.out.println("base = " + base);
//            System.out.println("count = " + count);
//            System.out.println("isItInitialized = " + isItInitialized);
//            System.out.println();
            if (idx<nums.length){
                int numItem = nums[idx];
                if (isItInitialized == false){
                    base = numItem;
                    count = 1;
                    isItInitialized = true;
                }else{
                    if(base == numItem){
                        count++;
                    }else if(base != numItem ){
                        if(count > nums.length /2){
                            answer = base;
                            break;
                        }
                        base = numItem;
                        count = 1;
                        isItInitialized = true;
                    }
                }
            }else{
                if(count > nums.length /2){
                    answer = base;
                    break;
                }
                break;
            }


            idx++;
        }

        return answer;
    }

    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int result = solution.maximumGap(new int[]{2,2,1,1,1,2,2});
        System.out.println("result = " + result);
    }
}