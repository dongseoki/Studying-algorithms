import java.util.Scanner;

public class printing_the_swirls_beautifully_1022 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int r1 = sc.nextInt();
		int c1 = sc.nextInt();
		int r2 = sc.nextInt();
		int c2 = sc.nextInt();
		
		int[][] intarr = new int[r2-r1+1][c2-c1+1];
		
		int height = r2-r1+1;
		int width = c2-c1+1;
		int a = r1;
		int b = c1;
		for(int i=0;i<height;i++) {
			b=c1;
			for(int j=0;j<width;j++) {
				intarr[i][j]=findSwirls(a,b);
				b++;
			}
			a++;
		}
			 
		
		int maxx = Math.max(intarr[0][0], intarr[0][width-1]);
		maxx = Math.max(maxx, intarr[height-1][0]);
		maxx = Math.max(maxx, intarr[height-1][width-1]);
		
		int size = Integer.toString(maxx).length();
		
		//System.out.println();
		int temp;
		String empty;
		int length;
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++) {
				if(j==0) {
					
				}
					
				empty= "";
				temp = Integer.toString(intarr[i][j]).length();
				length = size-temp;
				for(int k=0;k<length;k++) {
					empty +=" ";
				}
				//System.out.printf("%*d", size, intarr[i][j]);
				System.out.print(empty + intarr[i][j]);
				if(j!=width-1) {
					System.out.print(" ");
				}
			}
			if(i !=height-1)
				System.out.println();
		}
		
	}
	
	public static int findSwirls(int a,int b) {
		int n = Math.max(Math.abs(a), Math.abs(b));
		int sum = 0;
		if(n==0) {
			return 1;
		}
		if(-n<=a && a<=(n-1) && (-n+1)<=b &&b<=n) {
			sum = Math.abs(a-(n-1)) + Math.abs(b-n) + aFunction(n);
			return sum;
		}
		else {
			sum =aFunction(n+1) -1 - (Math.abs(a-n) + Math.abs(b-n));
			return sum;
		}
	}
	
	public static int aFunction(int n) {
		return (2+4*n*n-4*n);
	}
}
