package mytest;

// Callee.java
public class Callee {

  Callback callback;

  public Callee(Callback callback) {
    this.callback = callback;
  }

  public void execute() throws InterruptedException {
    for (int i = 1; i <= 5; i++) {
      callback.qrCheck(false);
//      Thread.sleep(1000);
    }
    callback.qrCheck(true);
  }
}