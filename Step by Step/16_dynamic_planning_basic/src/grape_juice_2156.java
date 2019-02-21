import java.util.ArrayList;
import java.util.Scanner;

public class grape_juice_2156 {

	public static int[] memo;
	public static int[] dp;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> grape = new ArrayList<Integer>();
		ArrayList<Integer> maxGrape = new ArrayList<Integer>();
		ArrayList<Integer> maxGrapeState = new ArrayList<Integer>();
		int num = sc.nextInt();
		grape.add(0);// start index is one.
		for (int i = 0; i < num; i++) {
			grape.add(sc.nextInt());
		}
		
		dp = new int[num + 1];
		for (int i = 0; i < num + 1; i++) {
			dp[i] = -1;
		}

		int length = grape.size() - 1;

		System.out.println(drinkingALot_TopDown(grape, length));
		

	}

	public static int drinkingALot_TopDown(ArrayList<Integer> grape, int length) {
		// 최대를 마시는 경우를 저장할 것이다.
		// state true : you can drink grape juice 연달아.
		// end term.
		
		if(length ==0)
			return 0;
		if(length ==1)
			return grape.get(1);
		if(length ==2)
			return grape.get(1)+ grape.get(2);
		
		if (dp[length] != -1)
			return dp[length];
		for (int i = 1; i <= 3; i++) {
			if (dp[length - i] == -1)
				dp[length - i] = drinkingALot_TopDown(grape, length - i);
		}

		int temp = Math.max(dp[length - 3] + grape.get(length - 1) + grape.get(length),
				dp[length - 2] + grape.get(length));
		temp = Math.max(temp, dp[length - 1]);
		return temp;
	}

}
