package programmers.튜플;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Solution {
  public int[] solution(String s) {
    // tupleInfo 초기화
    Map<Integer, Set<Integer>> tupleInfo = initailizeTupleInfo(s);

    int length = tupleInfo.size();
    int[] answer = new int[length];
    // 각각 순회해서, 정답을 채운것을 반환한다.
    ArrayList<Integer> arrayList = new ArrayList<>();
    for (int num = 1; num <=  length; num++) {
      findItemByOneBaseIndex(num, arrayList,tupleInfo);
    }
    return arrayList.stream().mapToInt(x->x).toArray();
  }

  private void findItemByOneBaseIndex(int num, ArrayList<Integer> arrayList,Map<Integer, Set<Integer>> tupleInfo) {
      tupleInfo.get(num).removeAll(arrayList);
      int result = tupleInfo.get(num).stream().mapToInt(x->x).toArray()[0];
      arrayList.add(result);
  }

  private Map<Integer, Set<Integer>> initailizeTupleInfo(String s) {
//    Arrays.stream(s.substring(2, s.length()-2).split("\\}\\,\\{"))
//        .peek((item)->{
//      String[] elementArr = item.split(",");
//      tupleInfo.put(elementArr.length,
//          Arrays.stream(elementArr).map(Integer::valueOf).collect(Collectors.toCollection(HashSet::new)));
//          System.out.println("item = " + item);
//    })
//        .close();

    Map<Integer, Set<Integer>> tupleInfo = Arrays.stream(s.substring(2, s.length()-2).split("\\}\\,\\{"))
        .collect(Collectors.toMap((String item)-> item.split(",").length,
                  (String item) -> Arrays.stream(item.split(","))
                    .map(Integer::valueOf)
                    .collect(Collectors.toCollection(HashSet::new)))
                );
    System.out.println("hello");
    return tupleInfo;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] result = solution.solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    System.out.println("result = " + Arrays.toString(result));
  }
}