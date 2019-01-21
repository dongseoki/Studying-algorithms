package samsungproblem;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class start_and_link_14889 {
	public static int[][] map;
	public static int[] visited;
	public static int N;
	public static int[] start;
	public static int[] link;
	public static int min;
	
	public static int count;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			N = Integer.parseInt(br.readLine());
			map = new int[N+1][N+1];
			start = new int[N/2 +1];
			link = new int[N/2 +1];
			min =99999999;
			for(int i=1;i<=N;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=1;j<=N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			visited = new int[N+1];
			
			count =0;
			findpoint(1, 0);
			
//			printmap();
			//System.out.println("hi");
			
			System.out.println(min);
			
			
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("error occured");
		}
	

	}
	
	public static void printmap() {
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				System.out.print(map[i][j]+ " ");
			}
			System.out.println();
		}
	}
	
	public static void printvisited() {
		for(int i=1;i<=N;i++) {
			System.out.print(visited[i]+" ");
		}
		System.out.println();
	}
	public static void printstart() {
		for(int i=1;i<=N/2;i++) {
			System.out.print(start[i]+" ");
		}
		System.out.println();
	}
	public static void printlink() {
		for(int i=1;i<=N/2;i++) {
			System.out.print(link[i]+" ");
		}
		System.out.println();
	}
	
	public static void findpoint(int index, int num) {
		
		
		for(int i=index;i<=N;i++) {
			visited[i] = 1;
			num++;
			if(num == N/2) {
//				printvisited();
				count++;
				int a=1;
				int b=1;
				for(int j=1;j<=N;j++) {
					//System.out.println("N/j:"+N+"/"+j);
					if(visited[j] ==0) {
						link[b] = j;
						b++;
					}
					else { // visited[i] ==1..
						start[a] = j;
						a++;
					}
				}
//				printstart();
//				printlink();
//				System.out.println("sum(start,N/2):"+ sum(start,N/2));
//				System.out.println("sum(link,N/2):"+ sum(link,N/2));
				int result = Math.abs(sum(start,N/2) - sum(link,N/2));
				
				if(min >result) {
					min = result;
				}
				//printstart(); //for test
				//System.out.println(start.toString());
				//sum(N/2);
				//System.out.println(count);
			}
			else {
				findpoint(i+1, num);	
				//System.out.println("hi");//test
			}
			num--;
			visited[i] = 0;
		}
	}
	
	public static int sum(int[] arr, int length) {
		int result =0;
		int temp =1;
		int temp2 =1;
		temp = arr[1];
		temp2 = arr[length];
		if(length ==2) {
			return map[temp][temp2] +map[temp2][temp];
		}
		for(int i=1;i<=length-1;i++) {
			temp = arr[i];
			result +=map[temp][temp2];
			result +=map[temp2][temp];
		}
		return sum(arr, length-1)+result;
	}
	
	

}
