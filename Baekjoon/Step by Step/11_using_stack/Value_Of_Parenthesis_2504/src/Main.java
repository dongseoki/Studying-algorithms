
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Stack<String> stack = new Stack<String>();
		String str = sc.next();
		for (int i = 0; i < str.length(); i++) {
			try {
				if(str.charAt(i) == ')') {
					if(stack.peek().equals("(")) {
						stack.pop();
						stack.push("2");
					}
					else {
						int temp2=0;
						while(true) {
							if(stack.peek().equals("(")) {
								stack.pop();
								stack.push(temp2 * 2 + "");
								break;
							}
							else {
								temp2 += Integer.parseInt(stack.pop());
								
							}
						}
							
					}
				}else if(str.charAt(i) == ']') {
					if(stack.peek().equals("[")) {
						stack.pop();
						stack.push("3");
					}
					else {
						int temp2=0;
						while(true) {
							if(stack.peek().equals("[")) {
								stack.pop();
								stack.push(temp2 * 3 + "");
								break;
							}
							else {
								temp2 += Integer.parseInt(stack.pop());
								
							}
						}
							
					}
				}
				else if(str.charAt(i) == '(' || str.charAt(i) == '['){
					stack.push(str.charAt(i)+"");
				}
					
				
			}catch(Exception e) {
				//System.out.println("hello");// for test
				System.out.println(0);
//				while(!stack.isEmpty()) {
//					System.out.println(stack.pop());
//				} //test
				return; // ���ڿ� �̻�. �����Ѵ�. parseint ���� 0�̰ų� emptystack �� ����ε� ������ �ִ�
			}
		}
//		while(!stack.isEmpty()) {
//			System.out.println(stack.pop());
//			
//		}//test
		
		int sum = 0;
		try {
			while(!stack.isEmpty()) {
				sum += Integer.parseInt(stack.pop());
				
			}
			//System.out.println("hi");//test
		}
		catch(Exception e) {
			System.out.println(0);
			System.out.println("hi");//for test
//			while(!stack.isEmpty()) {
//				System.out.println(stack.pop() + "hi");
//			}
			return;
		}
		
		System.out.println(sum);
	}

}
