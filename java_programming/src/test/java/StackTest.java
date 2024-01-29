import datastructure.Stack;
import org.junit.jupiter.api.Test;

public class StackTest {
  @Test
  public void putTest() {
    //given
    Stack st = new Stack();

    //when
    st.put(1);

    //then
//        Assert.assertEquals(st.size(), 1);
  }

  @Test
  public void popTest() {
    //given
    Stack st = new Stack();
    st.put(1);
    st.put(2);

    //when
    int data = st.pop();

    //then
//        Assert.assertEquals(data, 2);
//        Assert.assertEquals(st.size(), 1);
  }

  @Test
  public void topTest() {
    //given
    Stack st = new Stack();
    st.put(1);
    st.put(2);

    //when
    int data = st.top();

    //then
//        Assert.assertEquals(data, 2);
//        Assert.assertEquals(st.size(), 2);

  }
}
