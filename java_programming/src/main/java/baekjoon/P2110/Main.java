package baekjoon.P2110;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;
    st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    int C = Integer.parseInt(st.nextToken());
    List<Integer> houseXposList = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      String s = br.readLine();
      int xPos = Integer.valueOf(s);
      houseXposList.add(xPos);
    }
    Main main = new Main();
    int maxDistanceCloseSwitch = main.getMaxDistanceCloseSwitch(N, C,
        houseXposList);
    System.out.println("" + maxDistanceCloseSwitch);
//    Main main = new Main();
//    int maxDistanceCloseSwitch = main.getMaxDistanceCloseSwitch(5, 3,
//        new ArrayList<>(List.of(1, 2, 8, 4, 9)));
    printOutSpecial("maxDistanceCloseSwitch = " + maxDistanceCloseSwitch);
  }

  public int getMaxDistanceCloseSwitch(int N, int C, List<Integer> houseXposList) {
    // 1 정렬
    // 2  매개변수 탐색으로 답 도출.
    Collections.sort(houseXposList);
    printOutSpecial("sorted Result = ");
    houseXposList.forEach(x -> printOutSpecial("x = " + x));
    return getMaxDistanceCloseSwitchByParameterSearch(C, houseXposList);
  }

  private int getMaxDistanceCloseSwitchByParameterSearch(int c, List<Integer> houseXposList) {
    int low = 1;
    int high = houseXposList.get(houseXposList.size() - 1);
    int result = 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      boolean itPossibleUseSwitchWithThisDistance = isItPossibleUseSwitchWithThisDistance(c,
          houseXposList, mid);
      printOutSpecial("low = " + low);
      printOutSpecial("high = " + high);
      printOutSpecial("mid = " + mid);
      printOutSpecial(
          "itPossibleUseSwitchWithThisDistance = " + itPossibleUseSwitchWithThisDistance);
      if (itPossibleUseSwitchWithThisDistance) {
        result = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }

  private boolean isItPossibleUseSwitchWithThisDistance(final int C, List<Integer> houseXposList,
      final int dist) {
    printOutSpecial("isItPossibleUseSwitchWithThisDistance start");
    printOutSpecial("dist = " + dist);
    boolean result = false;

    int count = 0;
    int nowIdx = 0;

    while (true) {
      count++;
      printOutSpecial("count = " + count);
      printOutSpecial("nowIdx = " + nowIdx);
      if (count == C) {
        printOutSpecial("count == C return");
        return true;
      }
      int tarXPos = houseXposList.get(nowIdx) + dist;
      printOutSpecial("tarXPos = " + tarXPos);
      int nextXIdx = findNextIdx(nowIdx, tarXPos, houseXposList);
      printOutSpecial("nextXIdx = " + nextXIdx);
      if (nextXIdx == -1) {
        break;
      } else {
        nowIdx = nextXIdx;
      }
    }

    printOutSpecial("isItPossibleUseSwitchWithThisDistance end");
    return false;
  }

  private int findNextIdx(int nowIdx, int tarXPos, List<Integer> houseXposList) {
    int size = houseXposList.size();
    int nextXIdx = -1;
    for (int i = nowIdx + 1; i < size; i++) {
      if (houseXposList.get(i) >= tarXPos) {
        nextXIdx = i;
        break;
      }
    }
    return nextXIdx;
  }

  public static void printOutSpecial(String message) {
    boolean active = false;
    if (active) {
      System.out.println(message);
    }
  }


}
