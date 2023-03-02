package programmers.N으로_표현;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Solution {
  public int solution(int N, int number) {
    Map<Integer, Set<Integer>> cntToExpMap = makeExpressionSet(N);
    for (int i = 1; i <= 8; i++) {
      Set<Integer> candidate = cntToExpMap.get(i);
      if(candidate.contains(number))
        return i;
    }
    return -1;
  }

  private Map<Integer, Set<Integer>> makeExpressionSet(int numCard) {
    Map<Integer, Set<Integer>> cntToExpMap = new HashMap<>();
    Set<Integer> allNumSet = new HashSet<>();
    for (int i = 1; i <= 8; i++) {
      cntToExpMap.put(i, new HashSet<>());
    }

    for (int i = 1; i <= 8; i++) {
      cntToExpMap.get(i).add(concatNum(numCard, i));
      allNumSet.add(concatNum(numCard, i));
      for (int j = 1; j < i; j++) {
        Set<Integer> targetSet = cntToExpMap.get(i);
        for (int ele1 : cntToExpMap.get(j)
          ) {
          for (int ele2 :
            cntToExpMap.get(i - j)) {
            List<Integer> results = new ArrayList<>();
            results.add(ele1 - ele2);
            results.add(ele2 - ele1);
            results.add(ele1 * ele2);
            results.add(ele1 + ele2);
            if (ele1 >= ele2 && ele2 != 0){
              results.add(ele1 / ele2);
            } else if (ele1 != 0){
              results.add(ele2 / ele1);
            }
            for (int result :
              results) {
              if (!allNumSet.contains(result)) {
                targetSet.add(result);
                allNumSet.add(result);
              }
            }
          }
        }
      }
    }
    return cntToExpMap;
  }

  private Integer concatNum(int number, int i) {
    StringBuilder sb = new StringBuilder();
    for (int j = 0; j < i; j++) {
      sb.append(number);
    }
    return Integer.valueOf(sb.toString());
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int result = solution.solution(5, 12);
    System.out.println("result = " + result);
  }
}
