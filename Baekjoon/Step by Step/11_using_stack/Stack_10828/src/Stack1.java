import java.util.*;

public class Stack1 {

	public static void main(String[] args) {
		int numOfOrder;
		String order;
		Scanner sc = new Scanner(System.in);
		// TODO Auto-generated method stub
		ArrayStack stack = new ArrayStack();
		numOfOrder = sc.nextInt();
		for (int i = 0; i < numOfOrder; i++) {

			order = sc.next();
			if (order.equals("push")) {
				stack.push(sc.nextInt());
			} else if (order.equals("pop")) {
				System.out.println(stack.pop());
			} else if (order.equals("size")) {
				System.out.println(stack.size());
			} else if (order.equals("empty")) {
				System.out.println(stack.empty());
			} else if (order.equals("top")) {
				System.out.println(stack.top());
			}
		}
	}

}
