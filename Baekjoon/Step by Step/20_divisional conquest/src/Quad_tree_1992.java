import java.util.ArrayList;
import java.util.Scanner;

public class Quad_tree_1992 {
	public static char[][] chararr;
	public static ArrayList<Character> q;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		chararr = new char[N][N];
		q= new ArrayList<Character>();
		
		for(int i =0;i<N;i++) {
			chararr[i] = sc.next().toCharArray();
		}
		
		dc(N,0,0);
		
		for(int i=0;i<q.size();i++)
			System.out.print(q.get(i));
		
		
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				System.out.print(chararr[i][j]);
//			}
//			System.out.println();
//		}
	}
	
	public static void dc(int N, int r, int c) {
		StringBuilder sb= new StringBuilder();
		int[] count = new int[2];
		int rN = r+N;
		int cN = c+N;
		if(N==1) {
			q.add(chararr[r][c]);
			return;
		}
		for(int i=r;i<rN;i++) {
			for(int j=c;j<cN;j++) {
				count[chararr[i][j]-48]++;
				if(count[0]!=0 && count[1] !=0) {
					q.add('(');
					int mN = N/2;
					dc(mN,r,c);
					dc(mN,r,c+mN);
					dc(mN,r+mN,c);
					dc(mN,r+mN,c+mN);
					// function
					q.add(')');
					return ;
				}
			}
		}
		if(count[0]>count[1])
			q.add('0');
		else
			q.add('1');
		
		return ;
	}

}
