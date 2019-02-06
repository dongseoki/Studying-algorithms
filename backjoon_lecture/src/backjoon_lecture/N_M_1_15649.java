package backjoon_lecture;

import java.util.Scanner;

public class N_M_1_15649 {
	public static boolean[] c;
	public static int[] a;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		c = new boolean[10];
		a = new int[10];
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		go(0,N,M);
	}
	
	public static void go(int index, int N, int M) {
		if(index ==M) {
			for(int i=0;i<M;i++) {
				System.out.print(a[i]);
				if (i != M-1) System.out.print(' ');
			}
				
			System.out.println();
			return;
		}
		else {
			for(int i=1;i<=N;i++) {
				if(c[i] == true)
					continue;
				c[i] = true;
				a[index] = i;
				go(index+1,N,M);
				c[i] = false;
			}
		}
	}

}
