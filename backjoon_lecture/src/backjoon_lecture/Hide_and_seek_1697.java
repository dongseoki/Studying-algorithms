package backjoon_lecture;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Hide_and_seek_1697 {
	public static int[] map;
	public static boolean[] visited;
	public static int[] dr;
	public static int[] dc;
	public static int[]dist;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//point convert need.
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q =new LinkedList<Integer>();
		int N = sc.nextInt();
		int K = sc.nextInt();
		map = new int[101000];
		visited = new boolean[101000];
		dist = new int[101000];
		
		dr = new int[]{-1,0,+1,0};
		dc = new int[]{0,+1,0,-1};
		
		
		
		q.offer(N);
		visited[N] = true;
		dist[N] = 0;
		int cp=0;
		int sp=0;
		while(!q.isEmpty()) {
			 cp= q.poll();
			 
			 if(cp == K) {
				//System.out.println("hi");
				break;
			 }
			 
			for(int i=0;i<3;i++) {
				switch(i) {
				case 0:
					sp = cp*2;
					break;
				case 1:
					sp = cp+1;
					break;
				case 2:
					sp = cp-1;
				}
				if(0<=sp && sp<=100000 && visited[sp] ==false) {
					visited[sp] = true;
					q.offer(sp);
					dist[sp]= dist[cp]+1;
				}
			}
		}
		
		//System.out.println(count);
		System.out.println(dist[K]);
	}

}	

