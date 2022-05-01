package josepus2_11866;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Integer> L = new LinkedList<Integer>();
		int temp;
		int N;
		int M;
		Scanner sc =new Scanner(System.in);
		 N = sc.nextInt();
		 M = sc.nextInt();
		for(int i=1;i<=N;i++)
			L.offer(i);
		
		System.out.println(josepus(L, M));
		
			
	}
	public static String josepus(Queue<Integer> L, int M) {
		String str = "<";
		int temp=0;
		
		if(!L.isEmpty()) {
			for(int i=0;i<M-1;i++) {
				L.offer(L.poll());
			}
			
			//L.offer(L.poll());
			temp = L.poll();
			str +=temp;
		}
			
		
		while(!L.isEmpty()) {
			str+=", ";
			for(int i=0;i<M-1;i++) {
				L.offer(L.poll());
			}
			temp = L.poll();
			str +=temp;
			
			//System.out.println(temp);
		}
		return str+">";
	}

}
