package mytest.example;

interface Food {
}

class Pizza implements Food {
}

class Hamburger implements Food {
}

class Fruit {

}

interface FunctionTest {
  void test(String s);

  void test(Integer i);
}


public class Main {

  public static void main(String[] args) {
//    Pizza pizza = new Pizza();
//    if (pizza instanceof Food) {
//      System.out.println("This is a Food.");
//    }
//    m1(pizza);
    FunctionTest functionTest = new FunctionTest() {
      @Override
      public void test(String s) {
        System.out.println("s = " + s);
      }

      @Override
      public void test(Integer i) {
        System.out.println("i = " + i);
      }
    };

//    FunctionTest functionTest = (String s) -> System.out.println("s = " + s);
  }

  public static void m1(Food food) {
    System.out.println("food = " + food);
  }        // 성공해야 한다.

}
