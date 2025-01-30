package baekjoon.P13144.test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    br.readLine();
    String numLine = br.readLine();
    int[] list = Arrays.stream(numLine.split(" ")).mapToInt(Integer::valueOf).toArray();
    long aCase = getCase(list);
    System.out.println(aCase);

  }

  public static long getCase(int[] list) {
    long answer = 0;
    int startIdx = 0;
    int endIdx = 0;
    int[] countArr = new int[list.length + 1];
    countArr[list[endIdx]] = 1;
    while (true) {
      // 탈출조건 필요.
      if (startIdx == list.length) {
        break;
      }
      boolean stepEIsAvailable = stepEIsAvailable(countArr, list, endIdx + 1);
//      printOutSpecial("countArr : " + Arrays.toString(countArr));
      printOutSpecial("startIdx : " + startIdx);
      printOutSpecial("endIdx : " + endIdx);
      printOutSpecial("stepEIsAvailable : " + stepEIsAvailable);
      if (stepEIsAvailable) {
        // stepE
        endIdx++;
        // refreshArr
        countArr[list[endIdx]] = 1;
      } else {
        // e stop
        // calculateCase;
        int caseCount = endIdx - startIdx + 1;

        printOutSpecial("caseCount = " + caseCount);
        answer += caseCount;
        // refresh
        countArr[list[startIdx]] = 0;
        startIdx++;
      }
    }

    return answer;
  }

  private static boolean stepEIsAvailable(int[] countArr, int[] numList, int idx) {
    return 0 <= idx
        && idx < numList.length
        && countArr[numList[idx]] == 0;
  }

  public static void printOutSpecial(String message) {
    boolean active = false;
    if (active) {
      System.out.println(message);
    }
  }
}
