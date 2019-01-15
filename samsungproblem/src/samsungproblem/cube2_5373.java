package samsungproblem;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class cube2_5373 {
	public static char[][] cube;
	public static char[] intarr;
	public static ArrayDeque<Character> dq;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		dq = new ArrayDeque<Character>();
		try {
			// ť�� ����
			cube = new char[12][9];
			intarr = new char[12];
			// ä��� �Լ�.

			// printcube();
			// ���̽� ���Է¹ޱ�
			int T = Integer.parseInt(br.readLine());

			// for ��.

			for (int i = 0; i < T; i++) {
				// ť�� �ʱ�ȭ�ϱ�
				resetcube();
				// resetintarr();
				// ���̽� �� ���� �Է� �ޱ�
				int n = Integer.parseInt(br.readLine()); // ���� Ƚ�� n
				String[] strarr = (br.readLine().split(" "));

				System.out.println("end0");
				// ���̽��� ���� ������
				rolling(strarr, strarr.length);

				System.out.println("end1");
				// ���̽��� ���� �ٷιٷ� ����ϱ�
				for (int j = 3; j < 6; j++) {
					for (int k = 3; k < 6; k++) {
						System.out.print(cube[j][k]);
					}
					System.out.println();
				}
				printcube();

				System.out.println("end2");
//				System.out.println(n);
//				int length =strarr.length;
//				for(int j=0;j<length;j++)
//					System.out.print(strarr[j]+ "()");
//				System.out.println("--------------"); // test
			}
		} catch (Exception e) {
			System.out.println("problem");
			e.getStackTrace();
		}

	}

	public static void printcube() {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 9; j++)
				System.out.print(cube[i][j] + " ");
			System.out.println();
		}
	}

	public static void fillcube(int x, int y, char ch) {
		for (int a = x; a < x + 3; a++) {
			for (int b = y; b < y + 3; b++)
				cube[a][b] = ch;
		}
		return;
	}

	public static void resetcube() {
		fillcube(0, 3, 'o');
		fillcube(3, 0, 'g');
		fillcube(3, 3, 'w');
		fillcube(3, 6, 'b');
		fillcube(6, 3, 'r');
		fillcube(9, 3, 'y');
	}

	public static void rolling(String[] strarr, int length) {

		// ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
		Point startpoint;
		for (int i = 0; i < length; i++) {
			System.out.println("hi");
			// printcube(); // test..
			System.out.println(strarr[i] + "result");// test
			dq.clear(); // �ʱ�ȭ.
			char ch = strarr[i].charAt(0);
			startpoint = findstart(ch);
			copytodeque(startpoint);
			
			System.out.println(dq.size());//test
			ArrayDeque<Character> dq2 = new ArrayDeque<Character>();
			for(int j=0;j<12;j++) {
				ch = (dq.pollFirst());
				System.out.println(ch);
				dq2.addLast(ch);
			}
			dq = dq2;
			System.out.println("dq2problem"); //test
			

			int ch2 = strarr[i].charAt(1);
			switch (ch2) {
			case '+':
				spin('+');
				break;
			case '-':
				spin('-');
				break;
			}

			copytocube(startpoint);

			// cube �� �ٿ��ֱ�.

			System.out.println("hiend");

		}
	}

	public static void spin(char ch) {
		if (ch == '+') {
			for (int i = 0; i < 3; i++)
				dq.addFirst(dq.pollLast());
		} else if (ch == '-') {
			for (int i = 0; i < 3; i++)
				dq.addLast(dq.pollFirst());
		}

	}

	public static void copytodeque(Point startpoint) {
		Point point = new Point(startpoint.x, startpoint.y);
		Point temp = null;
		try {
			int count = 0;
			while (true) {
				count++;
				temp = finduppoint(point);
				dq.addLast(cube[temp.x][temp.y]);
				if (count == 3)
					break;
				point.y += 1;
			}

			count = 0;
			while (true) {
				count++;
				temp = findrightpoint(point);
				dq.addLast(cube[temp.x][temp.y]);
				if (count == 3)
					break;
				point.x += 1;
			}
			count = 0;
			while (true) {
				count++;
				temp = finddownpoint(point);
				dq.addLast(cube[temp.x][temp.y]);
				if (count == 3)
					break;
				point.y -= 1;
			}
			count = 0;
			while (true) {
				count++;
				temp = findleftpoint(point);
				dq.addLast(cube[temp.x][temp.y]);
				if (count == 3)
					break;
				point.x -= 1;
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void copytocube(Point startpoint) {
		Point point = new Point(startpoint.x, startpoint.y);
		Point temp = null;
		
		char ch;
		try {
			int count = 0;
			while (true) {
				count++;
				temp = finduppoint(point);
				ch= dq.pollFirst();
				cube[temp.x][temp.y]= ch;
				if (count == 3)
					break;
				point.y += 1;
			}

			count = 0;
			while (true) {
				count++;
				temp = findrightpoint(point);
				ch= dq.pollFirst();
				cube[temp.x][temp.y]= ch;
				if (count == 3)
					break;
				point.x += 1;
			}
			count = 0;
			while (true) {
				count++;
				temp = finddownpoint(point);
				ch= dq.pollFirst();
				cube[temp.x][temp.y]= ch;
				if (count == 3)
					break;
				point.y -= 1;
			}
			count = 0;
			while (true) {
				count++;
				temp = findleftpoint(point);
				ch= dq.pollFirst();
				cube[temp.x][temp.y]= ch;
				if (count == 3)
					break;
				point.x -= 1;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static Point finduppoint(Point point) {
		Point uppoint = null;
		if (point.x == 0)
			uppoint = new Point(11, point.y);
		else
			uppoint = new Point(point.x - 1, point.y);
		return uppoint;
	}

	public static Point finddownpoint(Point point) {
		Point targetpoint = null;
		if (point.x == 11)
			targetpoint = new Point(0, point.y);
		else
			targetpoint = new Point(point.x + 1, point.y);
		return targetpoint;
	}

	public static Point findleftpoint(Point point) {
		Point targetpoint = null;
		if (point.y == 0)
			targetpoint = new Point(point.x, 8);
		else
			targetpoint = new Point(point.x, point.y - 1);
		return targetpoint;
	}

	public static Point findrightpoint(Point point) {
		Point targetpoint = null;
		if (point.y == 8)
			targetpoint = new Point(point.x, 0);
		else
			targetpoint = new Point(point.x, point.y + 1);
		return targetpoint;
	}

	public static Point findstart(char ch) {
		Point startpoint = null;
		switch (ch) {
		case 'B'://
			startpoint = new Point(0, 3);
			break;
		case 'L'://
			startpoint = new Point(3, 0);
			break;
		case 'U'://
			startpoint = new Point(3, 3);
			break;
		case 'R'://
			startpoint = new Point(3, 6);
			break;
		case 'F'://
			startpoint = new Point(6, 3);
			break;
		case 'D'://
			startpoint = new Point(9, 3);
			break;

		}
		return startpoint;
	}

}

class Point {
	public int x;
	public int y;

	public Point(int x, int y) {
		this.x = y;
		this.x = y;
	}
}