package programmers.다단계칫솔판매;

import java.util.*;

public class Solution {
    // 1 make map, answer initialize.
    Map<String, Integer> enrollIdxMap = new HashMap<String, Integer>();
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = {};


        int idx = 0;
        for (String name:enroll
             ) {
            enrollIdxMap.put(name, idx++);
        }

        List<Integer> temp = new ArrayList<>();
        answer = new int[enroll.length];
        Arrays.fill(answer, 0);

        // 2 execute
        final int sellerSize = seller.length;
        for (int i = 0; i < sellerSize; i++) {
            updateAnswer(enroll, referral, answer, seller[i], amount[i] * 100);
        }

        // 3 return
//        System.out.println("answer = " + Arrays.toString(answer));
        return answer;
    }

    private void updateAnswer(String[] enroll, String[] referral ,int[] answer, String sellerName, int amountValue) {
        //seller 이름으로 부터 부모들에게 문제 주어진 정답 만큼 값을 제공.
//        System.out.println(String.format("updateAnswer called\t\t %10s %10s", sellerName, ""+amountValue));

        String recommenderName = referral[enrollIdxMap.get(sellerName)];

        int recommenderAmount = (int) (amountValue * 0.1);
        answer[enrollIdxMap.get(sellerName)] += amountValue - recommenderAmount;
//        System.out.println("answer status = " + Arrays.toString(answer));

        if ("-".equals(recommenderName) || recommenderAmount==0) {
//            System.out.println(String.format("updateAnswer returned\t %10s %10s", sellerName, ""+amountValue));
            return;
        }
        updateAnswer(enroll, referral, answer, recommenderName, recommenderAmount);

//        System.out.println(String.format("updateAnswer returned\t %10s %10s", sellerName, ""+amountValue));
        return;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solution(new String[]{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, new String[]{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"}, new String[]{"young", "john", "tod", "emily", "mary"}, new int[]{12, 4, 2, 5, 10});
        solution.solution(new String[]{"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, new String[]{"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"}, new String[]{"sam", "emily", "jaimie", "edward"}, new int[]{2, 3, 5, 4});

    }
}
