import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Stack<Character> st = new Stack<Character>();
		Scanner sc = new Scanner(System.in);
		int numOfSentence = sc.nextInt();
		Queue<String> queueInput = new LinkedList<String>();
		for (int i = 0; i < numOfSentence; i++) {
			queueInput.offer(sc.next());
		}
		for (int i = 0; i < numOfSentence; i++) {
			Vps(queueInput.poll());
		}

/*		while (queueInput.isEmpty() != true) {
			System.out.println("-------------");
			System.out.println(queueInput.poll() + "   ");
		}*/
	}

	public static void Vps(String str) {
		Stack<Character> st = new Stack<Character>();
//		System.out.println(str);
//		System.out.println(str.charAt(str.length()-1));
		// System.out.println(str.charAt(0));
		for (int i = 0; i < str.length(); i++) {
			if (!st.isEmpty()) {
				if (st.peek() == '(' && str.charAt(i) == ')') {
					st.pop();
				}else
				st.push(str.charAt(i));
			} 
			else
				st.push(str.charAt(i));

		}
//		while(st.isEmpty() != true) {
//		System.out.println(st.pop());
//		}
		if (st.isEmpty())
			System.out.println("YES");
		else
			System.out.println("NO");

		return;
	}

}
