import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int numOfOrder;
		String order;
		Scanner sc = new Scanner(System.in);
		// TODO Auto-generated method stub
		//ArrayStack stack = new ArrayStack();
		numOfOrder = sc.nextInt();
		ArrayQueue aq = new ArrayQueue(numOfOrder);
		for (int i = 0; i < numOfOrder; i++) {

			order = sc.next();
			if (order.equals("push")) {
				aq.push(sc.nextInt());
			} else if (order.equals("pop")) {
				System.out.println(aq.pop());
			} else if (order.equals("size")) {
				System.out.println(aq.size());
			} else if (order.equals("empty")) {
				System.out.println(aq.empty());
			} else if (order.equals("back")) {
				System.out.println(aq.back());
			} else if (order.equals("front")) {
				System.out.println(aq.front());
			}  
		}
//		for(int i=0;i<aq.array.length;i++)
//			System.out.print(aq.array[i]);
//		System.out.println();
//		System.out.println(aq.size());
//		System.out.println(aq.empty());
//		aq.push(1);
//		System.out.println(aq.front());
//		System.out.println(aq.back());
//		System.out.println(aq.size());
//		System.out.println(aq.empty());
//		
//		for(int i=0;i<9;i++) {
//			aq.push(i);
//		}
//		System.out.println(aq.size());
//		System.out.println(aq.back());
//		System.out.println(aq.front());
//		
//		for(int i=0;i<aq.array.length;i++)
//			System.out.print(aq.array[i]);
	}
	

}

class ArrayQueue{
	public int array[];
	private int rear;
	private int front;
	private int sizeOfQueue;
	public ArrayQueue(int num) {
		array = new int[num];
		rear = 0;
		front = 0;
		sizeOfQueue = 0;
	}
//	public void resize(int newSize) {
//		int[] t= new int[newSize];
//		for(int i=0;i<size();i++) {
//			t[i] = array[i];
//			
//		}
//		array = t; // page49
//	}
	public void push(int num) {
//		if(front == (rear +1)%array.length) // if array.lenth =8 then full is 7.
////			resize(array.length +1);
//		
		// if it is not full then..
		rear = (rear +1);
		array[rear] = num;
		sizeOfQueue++;
		//else if it is full
	}
	public int size() {
		
		return sizeOfQueue;
		}
	
	public int empty() {
		if(sizeOfQueue ==0)
			return 1;
		else 
			return 0;
	}
	public int front() {
		if(sizeOfQueue == 0)
			return -1;
		else {
			return array[(front+1)];// always front is empty. so..
		}
	}
	public int back() {
		if(sizeOfQueue == 0)
			return -1;
		else {
			return array[rear];// always front is empty. so..
		}
	}
	public int pop() {
		if(sizeOfQueue == 0)
			return -1; // empty..
		else {
			int temp = array[(array.length+front+1)%array.length];
			front = (array.length+front+1)%array.length;
			sizeOfQueue--;
			return temp;
		}
			
	}
}

//front = (front + 1)%array.length;