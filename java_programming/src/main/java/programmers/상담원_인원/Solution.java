//package programmers.상담원_인원;
//
//import java.util.ArrayList;
//import java.util.HashMap;
//import java.util.List;
//import java.util.Map;
//import java.util.PriorityQueue;
//
//public class Solution {
//  public static void main(String[] args) {
//    Solution solution = new Solution();
//    int k = 3;
//    int n = 5;
//    int[][] reqs =
//        new int[][] {{10, 60, 1}, {15, 100, 3}, {20, 30, 1}, {30, 50, 3}, {50, 40, 1}, {60, 30, 2},
//            {65, 30, 1}, {70, 100, 2}};
//    int answer = solution.solution(k, n, reqs);
//    System.out.println(answer);
//  }
//
//  public int solution(int k, int n, int[][] reqs) {
//    int answer = Integer.MAX_VALUE;
//    // get All cases.
//    List<int[]> cases = findAllCases(k, n);
//    // divideReqsByCase
//    Map<Integer, List<int[]>> caseReqs = divideReqsByCase(k, reqs);
//    // tryConsulting
//    for (int[] caseItem : cases) {
//      int waitTime = tryConsulting(k, n, caseItem, caseReqs);
//      answer = Math.min(answer, waitTime);
//    }
//    return answer;
//  }
//
//  private Map<Integer, List<int[]>> divideReqsByCase(int k, int[][] reqs) {
//    Map<Integer, List<int[]>> reqsByCase = new HashMap<>();
//    for (int i = 1; i <= k; i++) {
//      reqsByCase.put(i, new ArrayList<>());
//    }
//    for (int[] req : reqs) {
//      int caseNum = req[2];
//      reqsByCase.get(caseNum).add(new int[] {req[0], req[1]});
//    }
//    return reqsByCase;
//  }
//
//  private int tryConsulting(int k, int n, int[] caseItem, Map<Integer, List<int[]>> caseReqs) {
//    int waitTime = 0;
//    for (int i = 1; i <= k; i++) {
//      waitTime += tryConsultingByType(caseItem[i - 1], caseReqs.get(i));
//    }
//    return waitTime;
//  }
//
//  private int tryConsultingByType(int mentorNum, List<int[]> reqsOnlyOneType) {
//    int waitTime = 0;
//    PriorityQueue<Integer> pq = new PriorityQueue<>();
//    for (int[] req : reqsOnlyOneType) {
//      int time = req[0];
//      int duration = req[1];
//      if (pq.size() < mentorNum) {
//        pq.add(time + duration);
//      } else {
//        int availableTime = pq.poll();
//        waitTime += availableTime - time;
//        pq.add(availableTime + duration);
//      }
//    }
//    return waitTime;
//  }
//
//  private List<int[]> findAllCases(int k, int n) {
//    int remain = n - k;
//    List<int[]> cases = new ArrayList<>();
//    for (int i = 0; i <= remain; i++) {
//      findCase(cases, new ArrayList<>(List.of(i)), remain - i, k);
//    }
//    return cases;
//  }
//
//  private void findCase(List<int[]> cases, List<Integer> selected, int remain, int k) {
//    // cases : 경우의 수 인자. 여기에 답을 추가.
//    // selected : 지금 까지 선택된 숫자들 리스트. 오름차순의 무언가.
//    // remain : 남은 숫자값. 이 안에서 숫자를 뽑아야 함.
//    // k : 선택해야 하는 숫자의 갯수. 이것이 재귀호출의 한계를 정함.
//    if (selected.size() == (k - 1)) {
//      // 마지막을 선택할 차례.
//      List<Integer> selectedFinal = new ArrayList<>(selected);
//      selectedFinal.add(remain);
//      cases.add(selectedFinal.stream().mapToInt(x -> x + 1).toArray()); // 기본값 1명씩 추가.
//      return;
//    }
//    for (int i = 0; i <= remain; i++) {
//      List<Integer> selectedNew = new ArrayList<>(selected);
//      selectedNew.add(i);
//      findCase(cases, selectedNew, remain - i, k);
//    }
//  }
//}