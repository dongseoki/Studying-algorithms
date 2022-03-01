package samsungproblem;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;


public class baby_shark_16236 {
	public static int[] dr;
	public static int[] dc;
	public static int[][] map;
	public static int num;
	public static int sum;
	public static Shark shark;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		dr = new int[]{-1,0,0,+1};
		dc = new int[]{0,-1,+1,0};
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
		StringTokenizer st;
		Queue<Pair> q =new LinkedList<Pair>();
		try {
			num = Integer.parseInt(br.readLine());
			map = new int[num][num];
			
			//System.out.println(num);
			for(int i=0;i<num;i++) {
				st= new StringTokenizer(br.readLine());
				for(int j=0;j<num;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			
			//System.out.println("hi");
			//처음 상어의 위치를 찾는다.
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					if(map[i][j] ==9) {
						shark = new Shark(i,j,2,0);
						map[i][j] = 0; // 자신의 위치는 빈칸으로 간주하자.
						break;
					}
						
				}
			}
			
			
			while(true){
				//System.out.println("while1");
				if(eatFish() ==false)
					break;
			}
			System.out.println(sum);
			
			
			
			
		} catch (Exception e) {
			System.out.println("problem");
			e.printStackTrace();
			// TODO: handle exception
		}
		
		

	}
	
	public static void printmap() {
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				System.out.print(map[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static boolean eatFish() {
		boolean[][] visited= new boolean[num][num];
		int[][] dist= new int[num][num];
		
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		Queue<Pair> q =new LinkedList<Pair>();
		
		q.offer(new Pair(shark.r,shark.c)); // bfs 탐색.
		visited[shark.r][shark.c] = true;
		dist[shark.r][shark.c] = 0;
		
		int sr;
		int sco;
		
		boolean endState = false;
		Pair point;
		int mindist = 0;
		
		while(!q.isEmpty()) {
			 point= q.poll();
			 
			 if(endState ==true) {
				 if(mindist<dist[point.r][point.c]) {
					 break;
				 }
					 
				 if(map[point.r][point.c] <shark.size && map[point.r][point.c]!=0  && mindist == dist[point.r][point.c]) {
					 pq.offer(point);
				 }
			 }
			 else 
				 if(map[point.r][point.c] <shark.size && map[point.r][point.c]!=0) {
				 endState = true;
				 mindist = dist[point.r][point.c];
				 pq.offer(point);
			 }
			 
			for(int i=0;i<4;i++) {
				sr= point.r + dr[i];
				sco = point.c + dc[i];
				if(0<=sr && sr<num && 0<=sco&&sco<num && map[sr][sco] <=shark.size  && visited[sr][sco] == false) {
					visited[sr][sco] = true;
					q.offer(new Pair(sr,sco));
					dist[sr][sco] = dist[point.r][point.c]+1;
				}
			}
		}
		
		if(pq.isEmpty())
			return false;
		else {
			 point = pq.peek();
			 sum+=dist[point.r][point.c];
			 //이동거리 계산
			 shark.r = point.r;
			 shark.c = point.c;
			 //이동
			 shark.count++;
			 //먹었다.
			 map[point.r][point.c] = 0;
			 //먹은 칸은 빈칸이 된다.
			 if(shark.count >= shark.size) {
				 shark.size++;
				 shark.count = 0;
			 }
			 //아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
			 //먹은 좌표//상어크기//상어카운트					 
			 return true;
		}
	}

}
class Pair implements Comparable{
	int r;
	int c;
	public Pair(int r, int c) {
		super();
		this.r = r;
		this.c = c;
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		Pair op;
		if(o instanceof Pair) {
			op = (Pair)o;
			if(this.r> op.r)
				return 1;
			else if(this.r == op.r) {
				if(this.c>op.c)
					return 1;
				else
					return -1;
			}
			else
				return -1;
		}
		return 0;
	}
}
class Shark{
	int r;
	int c;
	int size;
	int count;
	public Shark(int r, int c, int size, int count) {
		super();
		this.r = r;
		this.c = c;
		this.size = size;
		this.count = count;
	}
}