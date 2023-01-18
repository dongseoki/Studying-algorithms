package programmers.가장_큰_수;

import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Stream;

public class Solution {
  public String solution(int[] numbers) {
    String answer = "";

    String[] strNumbers = Arrays.stream(numbers).mapToObj(String::valueOf).toArray(String[]::new);
    Arrays.sort(strNumbers, new Comparator<String>() {
      @Override
      public int compare(String o1, String o2) {
//        int idx = 0;
//        if( o1.length() == idx || o2.length()==idx){
//
//        }
//        int num1 = Integer.valueOf(o1.charAt(idx));
//        int num2 = Integer.valueOf(o2.charAt(idx));
//        if(num1> num2){
//          return -1;
//        } else if (num1<num2) {
//          return 1;
//        }else{
//          idx++;
//        }
//
//        return 0;
//      }
//    });
//
//    return answer;
        return (o2 + o1).compareTo(o1 + o2);
      }
    });
    answer = String.join("",strNumbers);
    return answer.charAt(0)=='0' ? "0":answer;
  }

}