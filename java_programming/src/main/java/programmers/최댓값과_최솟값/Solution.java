package programmers.최댓값과_최솟값;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
  public String solution(String s) {
    String answer = "";
    List<Integer> integers = Arrays.stream(s.split(" ")).mapToInt(Integer::valueOf).boxed().collect(
        Collectors.toList());
    return Collections.min(integers) + " " + Collections.max(integers);
  }
}