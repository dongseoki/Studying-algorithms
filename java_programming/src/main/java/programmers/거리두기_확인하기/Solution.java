package programmers.거리두기_확인하기;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
  public int[] solution(String[][] places) {
    List<Integer> ansList = new ArrayList<>();
    for (String[] placeItem : places) {
      ansList.add(checkKeepDistance(placeItem));
    }
    return ansList.stream().mapToInt(x -> x).toArray();
  }

  public int checkKeepDistance(String[] placeItem) {
    int result = 1;
    int rowLen = placeItem.length;
    int colLen = placeItem[0].length();
    for (int row = 0; row < rowLen; row++) {
      for (int col = 0; col < colLen; col++) {
        if (isItPerson(row, col, placeItem)) {
          if (!checkMenhatenDistanceForThisPerson(row, col, placeItem)) {
            result = 0;
            break;
          }
        }
      }
    }
    return result;
  }

  public boolean isItPerson(int row, int col, String[] placeItem) {
    return "P".equals(String.valueOf(placeItem[row].charAt(col)));
  }

  public boolean checkMenhatenDistanceForThisPerson(int row, int col, String[] placeItem) {
    //visited 초기화.
    boolean result = true;

    // 멘헤튼 거리 2 이내의 모든 점을 방문해본다.
    // 벽으로 막혀있으면 못가는거.
    // 방문 한 점중에 사람이 있다면
    // false를 리턴한다.
    // 일단 기본은 true를 리턴한다.

    //bfs
    int[] dirRow = new int[] {+1, -1, 0, 0};
    int[] dirCol = new int[] {0, 0, +1, -1};
    boolean[][] visited = new boolean[placeItem.length][placeItem[0].length()];
    Queue<int[]> queue = new LinkedList();
    visited[row][col] = true;
    queue.add(new int[] {row, col, 0}); // search node row, col, distance.
    while (!queue.isEmpty()) {
      int[] here = queue.poll();
      if ((here[0] != row || here[1] != col) && isItPerson(here[0], here[1], placeItem)) {
        result = false;
        break;
      }
      for (int dir = 0; dir < dirRow.length; dir++) {
        int seaRow = here[0] + dirRow[dir];
        int seaCol = here[1] + dirCol[dir];
        if (carItBeSearched(seaRow, seaCol, placeItem)
            && visited[seaRow][seaCol] == false
            && (here[2] + 1) <= 2
            && !isItWall(seaRow, seaCol, placeItem)) {
          visited[seaRow][seaCol] = true;
          queue.add(new int[] {seaRow, seaCol, here[2] + 1});
          queue.poll();
        }
      }
    }

    return result;
  }

  public void printCalendar(String name) {

  }

  public boolean isItWall(int row, int col, String[] placeItem) {
    return "X".equals(String.valueOf(placeItem[row].charAt(col)));
  }

  public boolean carItBeSearched(int row, int col, String[] placeItem) {
    int rowMax = placeItem.length;
    int colMax = placeItem[0].length();
    return (0 <= row
        && row < rowMax
        && 0 <= col
        && col < colMax);
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] solution1 = solution.solution(
        new String[][] {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
            {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
            {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
            {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
            {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"},
            {"OOOOO", "OOOOO", "OOOOO", "OOOOO", "OOOOO"},
            {"PXXXX", "XPXXX", "XXXPP", "XXXXX", "XXXXX"},
            {"PXXXX", "XPXXX", "XXXXP", "XXXXX", "XXXXX"},
            {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
            {"PPPPP", "PPPPP", "PPPPP", "PPPPP", "PPPPP"},
            {"OOPOO", "OOXOO", "PXPXP", "OOXOO", "OOPOO"},
            {"OOPOO", "OOOOO", "PXPXP", "OOXOO", "OOPOO"},
            {"OOOOO", "OPXPO", "OXPXO", "OPXPO", "OOOOO"},
            {"OOOOO", "OPOPO", "OXPXO", "OPXPO", "OOOOO"}});
    System.out.println("Arrays.toString(solution1) = " + Arrays.toString(solution1));
  }
}