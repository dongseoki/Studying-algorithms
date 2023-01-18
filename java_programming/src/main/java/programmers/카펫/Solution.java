package programmers.카펫;

public class Solution {
  public int[] solution(int brown, int yellow) {
    int[] answer = {};
    answer = findAnswer(brown, yellow);
    return answer;
  }

  private int[] findAnswer(int brown, int yellow) {
    int[] answer = new int[2];
    for (int i = 1; i < 2502; i++) {
      int h = i;
      int w = brown / 2 + 2 - h;
      if((w-2)*(h-2) == yellow){
        answer[0] = w;
        answer[1] = h;
        break;
      }
    }
    return answer;
  }
}
