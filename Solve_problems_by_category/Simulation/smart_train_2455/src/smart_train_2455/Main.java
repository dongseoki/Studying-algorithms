package smart_train_2455;

import java.util.Scanner;

public class Main {
	public static void main() {
		Scanner sc = new Scanner(System.in);
		int max=0;
		int sum = 0;
		int num=0;
		for(int i=0;i<8;i++) {
			num = sc.nextInt();
			if(i%2 == 0) { // take off train..
				sum -= num;
			}
			else { // take on train
				sum+=num;
			}
			if(max<sum)
				max = sum;
		}
		System.out.println(max);
		sc.close();
	}
}
