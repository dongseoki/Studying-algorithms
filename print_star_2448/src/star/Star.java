package star;

import java.util.Scanner;

public class Star {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long beforeTime = System.currentTimeMillis();
		char[][] stararr = new char[3][6];

		stararr[0][2] = '*';
		stararr[1][1] = '*';
		stararr[1][3] = '*';
		for (int i = 0; i < 5; i++) {
			stararr[2][i] = '*';
		}
//		for (int i = 0; i < stararr.length; i++) {
//			for (int j = 0; j < stararr[0].length; j++) {
//				System.out.print(stararr[i][j]);
//			}
//			System.out.println();
//		}
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		char[][] stararr2 = null;
		int result = num;
		int k = 0;
		while (true) {
			if (result == 3)
				break;
			else {
				result /= 2;
				k++;
			}
		}
		// char[][] stararr2 = new char[1][1];
		// stararr2 = charcopy(stararr, 3,5,6,11,0);

		if (num == 3) {
			stararr2 = new char[3][6];
			stararr2 = stararr;
		} else {
			for (int i = 1; i <= k; i++) {
				stararr2 = new char[stararr.length * 2][stararr.length * 2 - 1];
				stararr2 = charcopy2(stararr, i);
				stararr = stararr2;
			}
		}

		printarr2(stararr2);
		long afterTime = System.currentTimeMillis();
		//System.out.println(afterTime-beforeTime);	
	}

	public static void printarr(char[][] chararr) {
		int height = chararr.length;
		int width = height * 2;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				System.out.print(chararr[i][j]);
			}
			System.out.println();
		}
	}

	public static void printarr2(char[][] chararr) {
		int height = chararr.length;
		int width = height * 2 - 1;
		for (int i = 0; i < height-1; i++) {
			System.out.println(chararr[i]);
		}
		char[] finalarr = new char[width];
		for(int i=0;i<width;i++) {
			finalarr[i]= chararr[height-1][i];
		}
		System.out.println(finalarr);
	}

	// , int width, int height2, int width2, int k
	public static char[][] charcopy(char[][] chararr, int height) {
		char[][] newarr = new char[height * 2][height * 2 * 2 - 1];
		int width = height * 2 - 1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i][j + 3] = chararr[i][j];
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i + 3][j] = chararr[i][j];
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i + 3][j + 6] = chararr[i][j];
			}
		}
		return newarr;
	}

	public static char[][] charcopy2(char[][] chararr, int k) {
		int X = 3; // X= 3 * 2^k will be..
		for (int i = 0; i < k; i++) {
			X *= 2;
		}
		int height = X / 2;

		char[][] newarr = new char[height * 2][height * 2 * 2];
		int width = height * 2 - 1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i][j + height] = chararr[i][j];
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i + height][j] = chararr[i][j];
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				newarr[i + height][j + X] = chararr[i][j];
			}
		}
		return newarr;
	}

}
