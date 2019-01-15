import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class fibonacci_fuction_1003 {

	public static int[] called0;
	public static int[] called1;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int max = 0;
		int count = 0;
		// int[] intarr = new int[50];
		;
		try {
			count = Integer.parseInt(br.readLine());
			// count = sc.nextInt();
			int[] intarr = new int[count];
			int n = 0;
			for (int i = 0; i < count; i++) {
				n = Integer.parseInt(br.readLine());
				// n = sc.nextInt();
				intarr[i] = n;
				if (max < n)
					max = n;
			}

			called0 = new int[50];// to save index n..
			called1 = new int[50];// to save index n..
			called0[0] = 1;
			called1[0] = 0;
			called0[1] = 0;
			called1[1] = 1;

			for (int i = 2; i <= max; i++) {
				called0[i] = called0[i - 1] + called0[i - 2];
				called1[i] = called1[i - 1] + called1[i - 2];
			}

			int temp = 0;
			for (int i = 0; i < count; i++) {
				temp = intarr[i];
				System.out.println(called0[temp] + " " + called1[temp]);
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
