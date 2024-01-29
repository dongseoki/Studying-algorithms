package programmers.압축;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
  public int[] solution(String msg) {
    List<Integer> ansList = new ArrayList<>();
    Map<String, Integer> numberByWord = initDictionary();
    while (true) {
      String w = getLongestString(msg, numberByWord);
      int index = getNumberByWord(w, numberByWord);
      ansList.add(index);
      msg = removeWordFromMsg(w, msg);
      if (stillHaveWord(msg)) {
        String c = String.valueOf(msg.charAt(0));
        numberByWord.put(w + c, numberByWord.size() + 1);
      } else {
        break;
      }
    }
    return ansList.stream().mapToInt(x -> x).toArray();
  }

  private boolean stillHaveWord(String msg) {
    return msg != null && msg.length() > 0;
  }

  private String removeWordFromMsg(String w, String msg) {
    return msg.substring(w.length());
  }

  private int getNumberByWord(String w, Map<String, Integer> numberByWord) {
    return numberByWord.get(w);
  }

  private String getLongestString(String msg, Map<String, Integer> numberByWord) {
    String w = "";
    for (int i = 0; i < msg.length(); i++) {
      String c = String.valueOf(msg.charAt(i));
      if (numberByWord.containsKey(w + c)) {
        w += c;
      } else {
        break;
      }
    }
    return w;
  }


  private Map initDictionary() {
    Map<String, Integer> numberByWord = new HashMap<>();
    for (int i = 0; i < 26; i++) {
      numberByWord.put(String.valueOf((char) (i + 65)).toUpperCase(), i + 1);
    }
    return numberByWord;
  }
}