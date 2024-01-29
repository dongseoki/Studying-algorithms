package mytest;


import java.util.WeakHashMap;

public class Caller {
  public static void main(String[] args) throws Exception {
    // 1
//    Callback callback = new Callback() {
//      @Override
//      public void qrCheck(boolean check) {
//        if (check) {
//          System.out.println("QRCode Checked!!");
//        } else {
//          System.out.println("Waiting for Check QRCode...");
//        }
//      }
//    };
//    Callee callee = new Callee(callback);
//    callee.execute();


    //2
    WeakHashMap<Callback, String> weakHashMap = new WeakHashMap<>();
    Callback callback = new Callback() {
      @Override
      public void qrCheck(boolean check) {
        if (check) {
          System.out.println("QRCode Checked!!");
        } else {
          System.out.println("Waiting for Check QRCode...");
        }
      }
    };
    weakHashMap.put(callback, "test");

    Callee callee = new Callee(callback);
    callee.execute();
  }

}