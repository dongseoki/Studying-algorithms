import java.util.Scanner;

public class fibonacci2_2748 {
	public static long[] longarr;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		longarr = new long[n+1];// to save index n..
		System.out.println(fibo(n));
	}
	public static long fibo(int n) {
		long temp = longarr[n];
		if(n==0)
			return 0L;
		if(n==1)
			return 1L;
		if(temp != 0L)
			return temp;
		else{
			longarr[n] = fibo(n-1)+fibo(n-2);
			return longarr[n];
		}
	}

}
