//package leetcode.snakes_and_ladders;
//
//public class Solution {
//  private int a = 1; // OuterClass 클래스의 멤버 변수
//
//  public void localMethod() { // OuterClass 클래스의 멤버 메소드
//    int b = 10;  // 메소드의 지역 변수
//    // b = 30; <- 컴파일 오류
//
//    class LocalClass { // 메소드 내부에서 정의된 Local inner class
//      private int c = 100;
//
//      public void displayNum() {
//        System.out.println("a = " + a); // 외부 클래스의 멤버 변수
//        System.out.println("b = " + b); // 내부 클래스와 동일 스코프 내의 지역 변수
//        System.out.println("c = " + c); // 내부 클래스의 멤버 변수
//      }
//    }
//
//    LocalClass loc = new LocalClass();
//    b = 50; //<- 컴파일 오류
//
//    loc.displayNum();
//  }
//}