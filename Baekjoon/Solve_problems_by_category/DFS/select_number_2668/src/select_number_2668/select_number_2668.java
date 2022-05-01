package select_number_2668;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class select_number_2668 {
	public static boolean[] visited;
	public static PriorityQueue<Integer> pq;
	public static ArrayList<Integer> al;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		al = new ArrayList<Integer>();
		pq = new PriorityQueue<Integer>();
		int numOfnum = sc.nextInt();
		visited = new boolean[numOfnum+1];
		al.add(0);
		for(int i=0;i<numOfnum;i++) {
			al.add(sc.nextInt());
		} // al.get(0) is.. empty
		for(int i=1;i<=numOfnum;i++) {
			visited[i] = true;// Check in advance
			Dfs(i, i);
			visited[i] = false;
		}
		
		System.out.println(pq.size());
		//System.out.println("value");
		while(!pq.isEmpty()) {
			System.out.println(pq.poll());
		}
		
	}
	
	public static void Dfs(int i, int first) {
		
			// 1   2   3   4    <- i
			// 2   3   1   4   <- al.get(i)
			
		if (visited[al.get(i)] != true) {
			visited[al.get(i)] = true;
			Dfs(al.get(i), first);
			visited[al.get(i)] = false;
		}
		if (al.get(i) == first) {
			pq.offer(first);
		}
	}

}
