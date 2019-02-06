import java.text.DecimalFormat;
import java.util.Scanner;

public class Taxicab_Geometry_3053 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		double result1;
		double result2;
		result1 = N*N*Math.PI;
		result2 = 2*N *N;
		DecimalFormat df = new DecimalFormat("0.000000");
		//출처: https://mygumi.tistory.com/56 [마이구미의 HelloWorld]
		//System.out.printf("%.6f\n",(float)result1);
		//System.out.printf("%.6f",(float)result2);
		System.out.println(df.format(result1));
		System.out.println(df.format(result2));
	}

}
