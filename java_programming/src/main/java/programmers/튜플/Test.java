package programmers.튜플;

import java.util.Arrays;
import java.util.List;

public class Test {
  public static void printEvenWithDebug() {
    List<Integer> numbers = Arrays.asList(2, 3, 4, 5);

    numbers.stream()
//        .peek(x -> System.out.println("\nStart Debug"))
//        .peek(x -> System.out.println("from stream : " + x))
        .map(x -> x + 17)
//        .peek(x -> System.out.println("after stream : " + x))
        .filter(x -> x % 2 == 0)
//        .peek(x -> System.out.println("after filter : " + x))
        .limit(3)
//        .peek(x -> System.out.println("after limit : " + x))
        .forEach(System.out::println);
  }

  public static void main(String[] args) {
    printEvenWithDebug();
  }
}
