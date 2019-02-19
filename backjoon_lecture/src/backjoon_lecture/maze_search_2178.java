package backjoon_lecture;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class maze_search_2178 {
	public static char[][] charmap;
	public static boolean[][] visited;
	public static int[] dr;
	public static int[] dc;
	public static int[][] dist;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//point convert need.
		Scanner sc = new Scanner(System.in);
		Queue<Pair> q =new LinkedList<Pair>();
		int N = sc.nextInt();
		int M = sc.nextInt();
		charmap = new char[N][M];
		visited = new boolean[N][M];
		dist = new int[N][M];
		
		dr = new int[]{-1,0,+1,0};
		dc = new int[]{0,+1,0,-1};
		
		for(int i=0;i<N;i++) {
			charmap[i] = sc.next().toCharArray(); 
		}
		
		q.offer(new Pair(0,0));
		visited[0][0] = true;
		dist[0][0] = 1;
		int sr;
		int sco;
		Pair point;
		int count =0;
		while(!q.isEmpty()) {
			count++;
			 point= q.poll();
			 
			 if(point.r ==N-1 && point.c ==M-1) {
				//System.out.println("hi");
				break;
			 }
			 
			for(int i=0;i<4;i++) {
				sr= point.r + dr[i];
				sco = point.c + dc[i];
				if(0<=sr && sr<N && 0<=sco&&sco<M && charmap[sr][sco]=='1' && visited[sr][sco] == false) {
					visited[sr][sco] = true;
					q.offer(new Pair(sr,sco));
					dist[sr][sco] = dist[point.r][point.c]+1;
				}
			}
		}
		
		//System.out.println(count);
		System.out.println(dist[N-1][M-1]);
		
		
		
		
		
		
		// test
//		for(int i =0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				System.out.print(charmap[i][j]);
//			}
//			System.out.println();
//		}
	}

}

class Pair{
	int r;
	int c;
	public Pair(int r, int c) {
		super();
		this.r = r;
		this.c = c;
	}
	
	
}
