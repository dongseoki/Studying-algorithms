import java.util.Scanner;

public class Tournament_1057 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int L = sc.nextInt();
		int count = 0;
		int min = Math.min(K, L);
		int max = Math.max(K, L);

		while (true) {
			count++;
			min = (int) Math.ceil((float) min / 2);
			max = (int) Math.ceil((float) max / 2);
			if (min == max) {
				// System.out.println(count);
				break;
			}
			N = (int) Math.ceil((float) N / 2);

		}
		System.out.println(count);
	}

}
