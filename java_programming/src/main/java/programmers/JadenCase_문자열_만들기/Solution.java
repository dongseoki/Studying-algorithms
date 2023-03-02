package programmers.JadenCase_문자열_만들기;

public class Solution {
  public String solution(String s) {
    StringBuilder sb = new StringBuilder();
    int idx = 0;
    while (true) {
      if (idx >= s.length()) {
        break;
      }
      if (s.charAt(idx) == ' ') {
        sb.append(' ');
        idx++;
        continue;
      } else {
        int lastIndex = getLastletterIdxOfWord(s, idx);
        sb.append(getJadenCaseWord(s.substring(idx, lastIndex)));
        idx = lastIndex;
      }
    }
    return sb.toString();
  }

  private String getJadenCaseWord(String word) {
    StringBuilder sb = new StringBuilder();
    char firstletter = word.charAt(0);
    if ('0' > firstletter || firstletter > '9') {
      sb.append(String.valueOf(firstletter).toUpperCase());
    } else {
      sb.append(firstletter);
    }
    if (word.length() > 1) {
      sb.append(word.substring(1).toLowerCase());
    }

    return sb.toString();
  }

  private int getLastletterIdxOfWord(String s, int idx) {
    int length = s.length();
    int lastIndex = idx + 1;
    for (; lastIndex < length; lastIndex++) {
      char letter = s.charAt(lastIndex);
      if (letter == ' ') {
        break;
      }
    }
    return lastIndex;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    String result = solution.solution("asdf  Assdf");
//    String result = solution.solution("  ");
    System.out.println("result = " + result);
  }
}
