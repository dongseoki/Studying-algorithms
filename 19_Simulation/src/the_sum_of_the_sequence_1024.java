import java.util.Scanner;

public class the_sum_of_the_sequence_1024 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N =sc.nextInt();
		int  L = sc.nextInt();
		findlist(N,L);
	}
	
	
	public static void findlist(int N, int L) {
		int a;
		int b;
		int c;
		for(int i=L;i<=100;i++) {
			b = 2 * N + i - i*i;
			c= 2* i;
			//System.out.println("i/b/c: "+i+" "+b+" "+c);
			if(b%c==0) {
				a=b/c;
				if(0<=a) {
					printlist(a,i);
					return;
				}
			}
			
		}
		System.out.println(-1);
		return ;
	}
	
	public static void printlist(int a, int L) {
		System.out.print(a);
		for(int i=a+1;i<=a+L-1;i++)
			System.out.print(" "+i);
		return ;
	}

}
