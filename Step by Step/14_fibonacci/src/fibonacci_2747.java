import java.util.Scanner;

public class fibonacci_2747 {
	public static int[] intarr;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		intarr = new int[n+1];// to save index n..
		System.out.println(fibo(n));
	}
	public static int fibo(int n) {
		int temp = intarr[n];
		if(n==0)
			return 0;
		if(n==1)
			return 1;
		if(temp != 0)
			return temp;
		else{
			intarr[n] = fibo(n-1)+fibo(n-2);
			return intarr[n];
		}
	}

}
