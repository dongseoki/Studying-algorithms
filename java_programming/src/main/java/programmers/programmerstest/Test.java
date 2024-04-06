package programmers.programmerstest;

public class Test {
  public static void main(String[] args) {
    try {
      System.out.println("Hello Java");
      int[] answer = {};
      if (true) {
        throw new NullPointerException();
      }

      System.out.println("Hello Java");

      return;
    } catch (Exception e) {
      e.printStackTrace();
      String[] stackTraceStrings = convertStackTraceToStringArray(e);
      // 변환된 스택 트레이스 출력
      for (String trace : stackTraceStrings) {
        System.out.println(trace);
      }
    }
    return;

  }

  public static String[] convertStackTraceToStringArray(Exception e) {
    // Exception에서 StackTraceElement 배열을 가져옵니다.
    StackTraceElement[] stackTraceElements = e.getStackTrace();

    // 문자열 배열로 변환합니다.
    String[] stackTraceStrings = new String[stackTraceElements.length];
    for (int i = 0; i < stackTraceElements.length; i++) {
      stackTraceStrings[i] = stackTraceElements[i].toString();
    }

    return stackTraceStrings;
  }
}
