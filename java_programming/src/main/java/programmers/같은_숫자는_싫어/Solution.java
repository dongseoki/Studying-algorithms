package programmers.같은_숫자는_싫어;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Solution {
  public int[] solution(int []arr) {
    int[] answer = {};
    int preValue = -1;
    Stack<Integer> stack = new Stack<>();
    for (int item :
        arr) {
      if(item!=preValue){
        stack.push(item);
        preValue = item;
      }
    }
    List<Integer> newArrList = stack.stream().collect(Collectors.toList());

    return newArrList.stream().mapToInt(x->x).toArray();
  }
}