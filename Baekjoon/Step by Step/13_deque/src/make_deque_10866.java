import java.util.Scanner;

public class make_deque_10866 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		Deque dq = new Deque();
		String order;
		int numOfOrder = sc.nextInt();
		for (int i = 0; i < numOfOrder; i++) {
			order = sc.next();
			if (order.equals("push_front")) {
				dq.push_front(sc.nextInt());
			} else if (order.equals("push_back")) {
				dq.push_back(sc.nextInt());
			} else if (order.equals("pop_front")) {
				dq.pop_front();
			} else if (order.equals("pop_back")) {
				dq.pop_back();
			} else if (order.equals("size")) {
				dq.size();
			} else if (order.equals("empty")) {
				dq.empty();
			} else if (order.equals("front")) {
				dq.front();
			} else if (order.equals("back")) {
				dq.back();
			}
		}
	}

}

class Deque {
	int[] intarr;
	int front_index;
	int back_index;
	int size;
	int length;

	public Deque() {
		intarr = new int[10200];
		front_index = 0;
		back_index = 0;
		size = 0;
		length = intarr.length;
	}

	public void size() {
		System.out.println(size);
	}

	public void empty() {
		if (size == 0)
			System.out.println(1);
		else
			System.out.println(0);
	}

	public void front() {
		if (size == 0)
			System.out.println(-1);
		else
			System.out.println(intarr[front_index]);
	}

	public void back() {
		if (size == 0)
			System.out.println(-1);
		else
			System.out.println(intarr[back_index]);
	}

	public void push_front(int x) {
		if (size == 0) {
			intarr[front_index] = x;
			size++;
		} else {
			front_index = (front_index + length - 1) % length;
			intarr[front_index] = x;
			size++;
		}
	}

	public void push_back(int x) {
		if (size == 0) {
			intarr[back_index] = x;
			size++;
		} else {
			back_index = (back_index + 1) % length;
			intarr[back_index] = x;
			size++;
		}
	}

	public void pop_front() {
		if (size == 0)
			System.out.println(-1);
		else {
			if (size == 1) {
				// front_index and back index will not be changed.
				System.out.println(intarr[front_index]);
				size = 0;
			} else {
				System.out.println(intarr[front_index]);
				front_index = (front_index + 1) % length;
				size--;
			}
		}
	}

	public void pop_back() {
		if (size == 0)
			System.out.println(-1);
		else {
			if (size == 1) {
				// front_index and back index will not be changed.
				System.out.println(intarr[back_index]);
				size = 0;
			} else {
				System.out.println(intarr[back_index]);
				back_index = (back_index + length - 1) % length;
				size--;
			}
		}
	}

}