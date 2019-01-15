package samsungproblem;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class dragon_curve_15685 {

	public static int[][] mainMap;
	public static int[][] map1;
	public static int[][] map2;
	public static ArrayList<Pair> pl;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		pl= new ArrayList<Pair>();
		try {
			mainMap = new int[101][101];
			map1 = new int[101][101];
			map2 = new int[101][101];
			int N = Integer.parseInt(br.readLine());
			int x;
			int y;
			int d;
			int g;
			//System.out.println("N is : "+ N);
			for(int i=0;i<N;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				x =Integer.parseInt(st.nextToken());
				y =Integer.parseInt(st.nextToken());
				d =Integer.parseInt(st.nextToken());
				g =Integer.parseInt(st.nextToken());
				pl.clear(); // reset
				resetmap(map1);
				dragoncurve(0,d,x,y,0,0,g);
				
			}
			
			System.out.println(findsquare());
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	public static int findsquare() {
		int sum=0;
		for(int i=0;i<=99;i++) {
			for(int j=0;j<=99;j++) {
				if(mainMap[i][j]==1 && mainMap[i+1][j]==1 && mainMap[i+1][j+1]==1 && mainMap[i][j+1]==1)
					sum++;
			}
		}
		return sum;
	}
	public static void printmap(int[][] map, int height,int width) {
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++)
				System.out.print(map[i][j]+" ");
			System.out.println();
		}
	}

	public static void dragoncurve(int g, int d, int startx, int starty, int endx, int endy, int goal){
		Pair next = null;
		//System.out.println("g : " + g);// test
		if(g == 0) {
			map1[starty][startx] = 1;
			pl.add(new Pair(startx, starty));
			//System.out.println("d :" + d); //test
			switch(d) {
			case 0:
				endx =startx+1;
				endy = starty;
				break;
			case 1:
				endx =startx;
				endy = starty-1;
				break;
			case 2:
				endx =startx-1;
				endy = starty;
				break;
			case 3:
				endx =startx;
				endy = starty+1;
				break;
			}
			map1[endy][endx]= 1;
			pl.add(new Pair(endx, endy));
			next = new Pair(endx,endy);
		}
		else {// g!=0.. in case..
			int size =pl.size();
			int num1;
			int num2;
			int xchange;
			int ychange;
			int tgx;
			int tgy;
			for(int i=0;i<size;i++) {
				Pair temp = pl.get(i);
				num1 = temp.num1;
				num2 = temp.num2;
				xchange = Math.abs(endy -temp.num2);
				ychange = Math.abs(endx -temp.num1);
				//System.out.println("hi...");//test
				if(endx <=num1 && endy <= num2) {// 1->2
					tgx=endx - xchange;
					tgy=endy + ychange;	
					//System.out.println("1");//test
				}else if(endx <=num1 && endy >= num2) { // 4->1
					tgx=endx + xchange;
					tgy=endy + ychange;	
					//System.out.println("2");//test
				}else if(endx >=num1 && endy <= num2) { // 2->3
					tgx=endx - xchange;
					tgy=endy - ychange;	
					//System.out.println("3");//test
				}else {//endx >=temp.num1 && endy >= temp.num2 3->4
					tgx=endx + xchange;
					tgy=endy - ychange;	
					//System.out.println("4");//test
				}
				map1[tgy][tgx] =1;
				pl.add(new Pair(tgx, tgy));
				if(i ==0) {
					next = new Pair(tgx,tgy);
				}
			}
		}	
		if(g == goal) {
			copyonlyone(map1,mainMap);
			
		}// 그림 그리기
		else // g!= goal
			dragoncurve(g+1,d, startx,starty,next.num1,next.num2,goal); // 다음세대 드래곤 호출
	}
	
	public static void copyonlyone(int[][] map1, int[][] map2) {
		int temp;
		Pair tp;
		int size = pl.size();
		int num1;
		int num2;
		for(int i=0;i<size;i++) {
			tp = pl.get(i);
			num1 = tp.num1;
			num2 = tp.num2;
//			if(map1[num2][num1] ==1) {
//				//map2[num2][num1] = map1[num2][num1];
//				map2[num2][num1] = 1;
//			}
			map2[num2][num1] = 1;
					
		}
	}
	public static void resetmap(int[][] map1) {
		int temp;
		for(int i=0;i<=100;i++) {
			for(int j=0;j<=100;j++) {
					map1[i][j] = 0;
			}
		}
	}

}

class Pair{
	public int num1;
	public int num2;
	public Pair(int num1, int num2) {
		this.num1 = num1;
		this.num2 = num2;
	}
	
}
