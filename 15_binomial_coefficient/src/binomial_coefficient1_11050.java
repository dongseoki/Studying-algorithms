import java.util.Scanner;

public class binomial_coefficient1_11050 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		System.out.println(fac(N) / fac(K) / fac(N-K));
	}
	
	public static int fac(int n) {
		int result =1;
		for(int i=1;i<=n;i++)
			result*=i;
		return result;
	}

}
