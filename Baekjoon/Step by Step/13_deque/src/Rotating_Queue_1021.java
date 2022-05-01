import java.util.*;
public class Rotating_Queue_1021 {
	public static int sum;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
		Queue<Integer> q = new LinkedList<Integer>();
		int N =0;
		int M=0;
		sum=0;
		int target=0;
		
		N = sc.nextInt();
		M = sc.nextInt();
		for(int i=0;i<N;i++)
			dq.offerLast(i+1);
		
		for(int i=0;i<M;i++)
			q.offer(sc.nextInt());
		
		for(int i=0;i<M;i++) {
			target = q.poll();
			findlowvalueandpoll(dq, target);
		}
		System.out.println(sum);
	}
	public static void findlowvalueandpoll(ArrayDeque<Integer> dq, int target) {
		int count =0;
		if(dq.peekFirst() == target) {
			//sum will be not changed.
			dq.pollFirst();
		}
		else {
			while(true) {
				//System.out.println("hi");// for test
				count++;
				dq.offerLast(dq.pollFirst());//right move.
				if(dq.peekFirst() == target) {
					if(count>(dq.size()-count)) {
						count = dq.size()-count;
					}
					sum +=count;
					dq.pollFirst();
					break;
				}
			}
		}
	}
	public static void rightmove(ArrayDeque<Integer> dq) {
		dq.offerLast(dq.pollFirst());
	}
	
	public static void leftmove(ArrayDeque<Integer> dq) {
		dq.offerFirst(dq.pollLast());
	}
}
