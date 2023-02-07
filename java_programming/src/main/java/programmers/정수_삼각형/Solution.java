package programmers.정수_삼각형;

import java.util.Arrays;

public class Solution {
  public int solution(int[][] triangle) {
    int answer = 0;

    // exception case
    if(triangle.length == 1)
      return triangle[0][0];

    // find answer by bottom up
    // fill new data with numPathMax(r, c)
    //
    for (int rowIdx = 1; rowIdx < triangle.length; rowIdx++) {
      for (int colIdx = 0; colIdx < triangle[rowIdx].length; colIdx++) {
        if(colIdx == 0)
          triangle[rowIdx][colIdx] += triangle[rowIdx - 1][colIdx];
        else if (colIdx == rowIdx) {
          triangle[rowIdx][colIdx] += triangle[rowIdx - 1][colIdx - 1];
        }else
          triangle[rowIdx][colIdx] +=
              Math.max(triangle[rowIdx -1 ][colIdx - 1]
                  , triangle[rowIdx -1][colIdx]);
      }
    }

    // and Find numMaxPath with last rows.
    answer = Arrays.stream(triangle[triangle.length - 1]).max().getAsInt();
    return answer;
  }
}
