import java.util.Scanner;

public class fibonacci3_2749_pisano_period {
	static long[] longlist;
	static long mod;
	static int period;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long m = scan.nextLong();
		mod = 1000000;
		
		
		//전처리과정
		period = getPeriod(mod);
		
		longlist = new long[period+1];
		
		longlist[0] = 0;
		longlist[1] = 1;
		
		for(int i=2; i<period; i++) {
			longlist[i] = (longlist[i-2] + longlist[i-1])%mod;
		}
		
		
		int q = (int)(m%period);
		System.out.println(longlist[q]);
		
	}
	
	public static int getPeriod(long m) {
		int period = 0;
		
		long number1 = 1;
		long number2 = 1;
		
		do {
			long tmp = number1;
			number1 = number2;
			number2 = (tmp+number1)%m;
			
			period++;
		}while(!(number1==1 && number2==1));
		
		return period;
	}
	
	public static long fibomode(int n) {
		long temp = longlist[n];
		if(n==0)
			return 0L;
		if(n==1)
			return 1L;
		if(temp != 0L)
			return temp;
		else{
			longlist[n] = (fibomode(n-1)+fibomode(n-2))%period;
			return longlist[n];
		}
	}	
}

