package samsungproblem;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Robot_Cleaner_14503 {
	public static int[][] map;
	public static int[] dr;
	public static int[] dc;
	public static int sum;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			StringTokenizer st= new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int M=Integer.parseInt(st.nextToken());
			map = new int[N][M];
			
			dr =new int[]{-1,0,1,0};
			dc =new int[]{0,1,0,-1};
			sum =0;
			//dx= {1,2,3,4} .. error..
			//Array constants can only be used in initializers
			//��ó: https://resup.tistory.com/15 [RESUP]
			
			int[] dz= new int[]{1,2,3,4};
			
			st= new StringTokenizer(br.readLine());
			int r=Integer.parseInt(st.nextToken());
			int c=Integer.parseInt(st.nextToken());
			int d=Integer.parseInt(st.nextToken());
			
			for(int i=0;i<N;i++) {
				st= new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			
			
			
//			for(int i=0;i<N+2;i++) {
//				map[i][0] =1;
//			}
//			for(int i=0;i<N+2;i++) {
//				map[i][M+1] =1;
//			}
//			for(int j=0;j<M+2;j++) {
//				map[0][j] =1;
//			}
//			for(int j=0;j<N+2;j++) {
//				map[N+1][j] =1;
//			}
//			System.out.println(9+dr[(1+2)%4]);
//			System.out.println(3+dc[(1+2)%4]);
			
			runcleaner(r,c,d);
			System.out.println(sum);
//			System.out.println("-----------");
			
//			r = r+dr[(d+2)%4];//
//			c = c+dc[(d+2)%4];//
			//test
//			System.out.println();
//			for(int i=0;i<N;i++) {
//				//st= new StringTokenizer(br.readLine());
//				for(int j=0;j<M;j++) {
//					System.out.print(map[i][j]+" ");
//				}
//				System.out.println();
//			}
			
		}catch(Exception e){
			System.out.println("problem");
			System.out.println(e.getMessage());
		}

	}
	
	public static void runcleaner(int r,int c,int d) {
		//cleaned area is 2.
		// 1. clean here.
		if(map[r][c] !=2 && map[r][c] != 1) {
			map[r][c] = 2;
			sum++;
		}
		//System.out.println("r/c/d" + r + " "+c + " "+d + " ");
		
		int searcharea;
		int x;
		int y;
		int sd;//search direction
		int count =0;
		while(true) {
			//2.���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
			sd=(d+3)%4;
			x = r+dr[sd];
			y = c+dc[sd];
			searcharea = map[x][y];
			//System.out.println("x/y/d"+ r+" "+c+" "+d);
			if(searcharea == 0) {
//				System.out.println("hi2");
				//2.1
				//���� ���⿡ û������ ���� ������ ����.
				//ȸ�� �ϰ�.
				runcleaner(x,y,sd);
				return;//
			}
			else { // 1or 2.. then..
				count++;
				if(count ==4) {
					//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, 
					//�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���
					count=0;// �ʱ�ȭ.
					//System.out.println("hi");
					//System.out.println("");
					d= (d+3)%4; // 1���� �����̴�. // ������ ���� ����.
					r = r+dr[(d+2)%4];//
					c = c+dc[(d+2)%4];//
					if(map[r][c] == 1)
						return; // 4. �۵��� �����.
					continue;
				}
				d= sd;
				continue;
			}
				
		}
	}

}
