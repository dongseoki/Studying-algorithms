package programmers.완주하지_못한_선수;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Solution {
  public String solution(String[] participant, String[] completion) {
    String answer = "";
    Map<String, Integer> joinPeopleMap = new HashMap<>();
    for (String name :
        participant) {
      joinPeopleMap.put(name, joinPeopleMap.getOrDefault(name, 0) +1);
    }
    for (String name :
        completion) {
     int nameNum =  joinPeopleMap.getOrDefault(name, 0);
     if (nameNum>1){
       joinPeopleMap.put(name, nameNum-1);
     }else{
       joinPeopleMap.remove(name);
     }
    }
    answer= joinPeopleMap.keySet().stream().collect(Collectors.toList()).get(0);
    return answer;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    String answer = solution.solution(new String[]{"mislav", "stanko", "mislav", "ana"}, new String[]{"stanko", "ana", "mislav"});
    System.out.println("answer = " + answer);
  }
}
