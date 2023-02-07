package programmers.튜플;

import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class Test {
  public static void printEvenWithDebug() {
    Set<Integer> testSet= new HashSet<>();

    List.of("1","2", "3").stream().map((item)->{
      testSet.add(Integer.valueOf(item));
      return Integer.valueOf(item);
    }).collect(Collectors.toList());

    System.out.println("testSet ------");
    testSet.forEach((item)-> System.out.println("item = " + item));

  }

  public static void main(String[] args) {
    printEvenWithDebug();
  }
}
