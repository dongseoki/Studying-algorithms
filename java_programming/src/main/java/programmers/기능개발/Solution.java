package programmers.기능개발;

import java.util.ArrayList;
import java.util.List;

public class Solution {
  public int[] solution(int[] progresses, int[] speeds) {
    int[] answer = {};
    List<Integer> leftDays = getLeftDayList(progresses, speeds);
    List<Integer> ansList = getFeatureCountForDistibution(leftDays);
    return ansList.stream().mapToInt(x -> x).toArray();
  }

  private List<Integer> getLeftDayList(int[] progresses, int[] speeds) {
    List<Integer> leftDays = new ArrayList<>();
    for (int i = 0; i < progresses.length; i++) {
      int leftDay = (100 - progresses[i]) / speeds[i];
      if ((100 - progresses[i]) % speeds[i] != 0) {
        leftDay++;
      }
      leftDays.add(leftDay);
    }
    return leftDays;
  }

  private List<Integer> getFeatureCountForDistibution(List<Integer> leftDays) {
    List<Integer> featureCountList = new ArrayList<>();
    int compareLeftDay = -1;
    int featureCountForDistibution = 0;
    for (int leftDay :
        leftDays) {
      if (compareLeftDay == -1) {
        compareLeftDay = leftDay;
        featureCountForDistibution++;
      } else {
        if (compareLeftDay >= leftDay) {
          featureCountForDistibution++;
        } else {
          featureCountList.add(featureCountForDistibution);
          compareLeftDay = leftDay;
          featureCountForDistibution = 1;
        }
      }
    }
    featureCountList.add(featureCountForDistibution);
    return featureCountList;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] progresses = {93, 30, 55};
    int[] speeds = {1, 30, 5};
    int[] ans = solution.solution(progresses, speeds);
    for (int i = 0; i < ans.length; i++) {
      System.out.println(ans[i]);
    }


  }
}