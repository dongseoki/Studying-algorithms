import java.util.Scanner;



import java.util.Queue;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int bigOfSequence = sc.nextInt();
		// 수를 받고
		// 수의 크기만큼 배열을 생성하자.
		// 받는 값을 전부 배열에 넣고
		// 저장.
		// 그리고 하나씩 해본다.
		// 또다른 배열을 만들어 + , -를 저장한다.
		// 하다가 불가능이 뜨면 No
		// 완료하면
		// 저장한 순서대로 배열을 출력.

		// 수의 크기만큼 배열을 생성하자.
		Queue<Integer> queueInput = new LinkedList<Integer>();

		// 받는 값을 전부 배열에 넣고
		for (int i = 0; i < bigOfSequence; i++) {
			queueInput.offer(sc.nextInt());
		}

		ArrayStack stack = new ArrayStack();
		Queue<String> queuepm = new LinkedList<String>();
		int bignumber = 0;// bignumber = 0 초기값.
		while (true) {
			
			if (queueInput.isEmpty() == true)
				break;
			int pollNumber = queueInput.poll();
			if (pollNumber == stack.top()) {
				stack.pop();
				queuepm.offer("-");
			} else if (pollNumber < stack.top()) {
				System.out.println("NO");
				return; // game over
			} else {
				// pollNumber> stack.top()
				//   스택에 값이 없더라도 통함.
				for(int i = bignumber;i<pollNumber;i++) {
					stack.push(++bignumber);
					queuepm.offer("+");
				}
				stack.pop();
				queuepm.offer("-");
			}

		}
		// while end./
		while (queuepm.isEmpty() != true) {
			System.out.println(queuepm.poll());
		}
		

	}

}
