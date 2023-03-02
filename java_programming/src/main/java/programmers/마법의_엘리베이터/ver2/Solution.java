package programmers.마법의_엘리베이터.ver2;

public class Solution {
  public int solution(int storey) {
    int[] storeyInfo = new int[]{storey, 0}; // storey, moveNum
    try{
      for (int posFR = 0; ; posFR++) { // position from right
        String storeyStr = String.valueOf(storeyInfo[0]);
        if(storeyInfo[0] == 0 || posFR >= storeyStr.length()){
          break;
        }
        int currentNum = getNumValue(storeyInfo[0], posFR);
        if(currentNum <5){
          storeyInfo = down(storeyInfo[0], storeyInfo[1], posFR);
        } else if (currentNum > 5) {
          storeyInfo = up(storeyInfo[0], storeyInfo[1], posFR);
        }else{
          // currentNum == 5

          // 다음 숫자가 없으면 -> 다운처리.
          // 다음 숫자가 있으면 ->
          // 다음 숫자가 5보다 크거나 같으면 up
          // 그렇지 않다면 down.

          if( (posFR+1) < storeyStr.length()){
            int nextNum = getNumValue(storeyInfo[0], posFR + 1);
            if(nextNum >= 5){
              storeyInfo = up(storeyInfo[0], storeyInfo[1], posFR);
            }else{
              storeyInfo = down(storeyInfo[0], storeyInfo[1], posFR);
            }
          }else{
            storeyInfo = down(storeyInfo[0], storeyInfo[1], posFR);
          }
        }
      }
    }catch (Exception e){
      System.out.println("e = " + e);
      e.printStackTrace();
    }

    return storeyInfo[1];
  }

  private int[] down(int storey, int curMoveNum, int posFR) {
    int moveNum = getNumValue(storey, posFR);
    storey = storey - moveNum * (int)Math.pow(10, posFR);
    return new int[]{storey, curMoveNum + moveNum};
  }

  private int[] up(int storey, int curMoveNum, int posFR) {
    int moveNum = 10 - getNumValue(storey, posFR);
    storey = storey + moveNum * (int)Math.pow(10, posFR);
    return new int[]{storey, curMoveNum + moveNum};
  }

  private int getNumValue(int storey, int posFR) {
    String storeyStr = String.valueOf(storey);
    int  result = Integer.valueOf(storeyStr.substring(storeyStr.length() - posFR - 1, storeyStr.length() - posFR));
    return result;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
//    int[] inputList = new int[] {16, 2554, 66, 95};
//    int[] outList = new int[]{6, 16, 8, 6};
    int[] inputList = new int[] {555};
    int[] outList = new int[]{14};

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
