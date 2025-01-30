package baekjoon.P13144;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {
//    List<List<Integer>> testCases = new ArrayList<>();
//    testCases.add(List.of(1, 2, 3, 4, 5));
//    testCases.add(List.of(1, 2, 3, 1, 2));
//    testCases.add(List.of(1, 1, 1, 1, 1));
//    testCases.forEach(caseItem -> {
//      long answer = getCase(new ArrayList<>(caseItem));
//      System.out.println(answer);
//      printOutSpecial("answer = " + answer);
//    });

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    br.readLine();
    String numLine = br.readLine();
//    List<Integer> list = Arrays.stream(numLine.split(" ")).map(data -> Integer.valueOf(data))
//        .collect(toList());
    int[] list = Arrays.stream(numLine.split(" ")).mapToInt(Integer::valueOf).toArray();
    long aCase = getCase(list);
    System.out.println(aCase);

  }

  // 숫자를 정렬한다.
  // 숫자가 12312의 경우를 가정해보자.
  // start = 0
  // end = 0 둘다 1을 가리키고
  // 하나씩 증가시킨다.
  // 이런케이스에서 카운트 배열에 값을 넣는다.
  // 010000
  // end 다음에 올 값 확인 아 2이고 카운트 배열에 없다.
  // 카운트 배열 새로고침한다.
  // s 0, e 1
  // 011000

  // e next, ah, next 3 and is not in cArr
  // refresh
  // s0 e2
  // 011100
  // e next try, ah, nextVal is 1 is in cArr
  // stop
  // calculate case. eIdx- sIdx +1 -> 3
  // answer +=cCase
  // answer 0->3

  // nextStep
  // s move
  // s1
  // e2
  // refresh Case
  // 00110000

  // e move try . sufficient
  // s1
  // e3
  // ref
  // cArr 01110000

  // e move try. next value is in cArr
  // stop
  // calculate case -> 3-1+1 = 3
  // answer ->3->6

  // s move
  // s2
  // e3
  // ref cArr
  // 010100

  // emoveTry ok
  // s2
  // e4
  // refre cArr
  // 011100
  //

  // emoveTry -> false. end of list
  // stop
  // calculate
  // 4-2 +1 = 3
  // ans 9

  // s ->
  // s3 e4

  // ref..

  // e move try -> stop -> endofllist
  // ca
  // ans 11

  // s->
  // s4 e4

  // etry -> endofline
  //
  // ans 12

  //s

  //
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
      printOutSpecial("countArr : " + Arrays.toString(countArr));
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
