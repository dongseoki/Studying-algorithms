import java.util.Scanner;



import java.util.Queue;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int bigOfSequence = sc.nextInt();
		// ���� �ް�
		// ���� ũ�⸸ŭ �迭�� ��������.
		// �޴� ���� ���� �迭�� �ְ�
		// ����.
		// �׸��� �ϳ��� �غ���.
		// �Ǵٸ� �迭�� ����� + , -�� �����Ѵ�.
		// �ϴٰ� �Ұ����� �߸� No
		// �Ϸ��ϸ�
		// ������ ������� �迭�� ���.

		// ���� ũ�⸸ŭ �迭�� ��������.
		Queue<Integer> queueInput = new LinkedList<Integer>();

		// �޴� ���� ���� �迭�� �ְ�
		for (int i = 0; i < bigOfSequence; i++) {
			queueInput.offer(sc.nextInt());
		}

		ArrayStack stack = new ArrayStack();
		Queue<String> queuepm = new LinkedList<String>();
		int bignumber = 0;// bignumber = 0 �ʱⰪ.
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
				//   ���ÿ� ���� ������ ����.
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
