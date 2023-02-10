package programmers.마법의_엘리베이터;

public class Solution {
  public static int answer;
  public int solution(int storey) {
      answer = Integer.MAX_VALUE;
      recursiveFind(storey, 0, 0);
      return answer;
    }

  private void recursiveFind(int leftNum, int idx, int curMove) {
    System.out.println(String.format("called : %d %d %d", leftNum, idx, curMove));
    String leftNumStr = String.valueOf(leftNum);
    if(idx == leftNumStr.length()-1) {
      // last point.
      curMove += Integer.valueOf(leftNumStr.substring(0,1));
      System.out.println(String.format("last point : %d %d %d", leftNum, idx, curMove));
      if (curMove < answer) {
        answer = curMove;
      }
      return;
    }
    // up
    int[] result;
    result = up(leftNum, leftNumStr.length(),idx);
    recursiveFind(result[0], idx+1, result[1] + curMove);

    // down
    result = down(leftNum, leftNumStr.length(),idx);
    recursiveFind(result[0], idx+1, result[1] + curMove);
  }

  private int[] up(int leftNum, int length, int numIdx) {
    int moveNum = 10 - getNumIdxValue(leftNum, length, numIdx);
    leftNum = (int)(leftNum * Math.pow(0.1, numIdx+1) + 1) * (int)Math.pow(10, numIdx+1);
    return new int[]{leftNum, moveNum};
  }

  private int[] down(int leftNum, int length, int numIdx) {
    int moveNum = getNumIdxValue(leftNum,length,numIdx);
    leftNum = (int)(leftNum * Math.pow(0.1, numIdx+1)) * (int)Math.pow(10, numIdx+1);
    return new int[]{leftNum, moveNum};
  }

  public int getNumIdxValue(int target, int length, int numIdx){
    return Integer.valueOf(String.valueOf(target).substring(length - numIdx-1, length - numIdx));
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] inputList = new int[] {16, 2554};
    int[] outList = new int[]{6, 16};

    for (int i = 0; i < inputList.length; i++) {
      int storey = inputList[i];
      int expect = outList[i];
      int result = solution.solution(storey);
//      assert expect == result : "not answer";
      if(expect != result){
        throw new RuntimeException(String.format("no way, expected : %s, result : %s", expect, result));
      }
      System.out.println("success");
    }
  }
}