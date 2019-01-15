package samsungproblem;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class cube_5373 {
	public static char[][] cube;
	public static char[] intarr;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			// 큐브 생성
			cube = new char[12][9];
			intarr = new char[12];
			// 채우기 함수.
			

			//printcube();
			//케이스 수입력받기
			int T = Integer.parseInt(br.readLine());
			
			
			// for 문.
			
			for(int i=0;i<T;i++) {
				// 큐브 초기화하기
				resetcube();
				//resetintarr();
				// 케이스 에 따라 입력 받기
				int n = Integer.parseInt(br.readLine()); // 돌린 횟수 n
				String[] strarr =(br.readLine().split(" "));
				
				System.out.println("end0");
				// 케이스에 의해 돌리기
				rolling(strarr, strarr.length);
				
				System.out.println("end1");
				// 케이스에 따라 바로바로 출력하기
				for(int j=3;j<6;j++) {
					for(int k=3;k<6;k++) {
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
		}catch(Exception e) {
			System.out.println("problem");
			e.getStackTrace();
		}

	}
	public static void resetintarr() {
		for(int i=0;i<12;i++) {
			intarr[i] = 0;
		}
	}
	public static void resetcube() {
		fillcube(0,3,'o');
		fillcube(3,0,'g');
		fillcube(3,3,'w');
		fillcube(3,6,'b');
		fillcube(6,3,'r');
		fillcube(9,3,'y');
	}
	
	public static void rolling(String[] strarr, int length) {
		for(int i=0;i<length;i++) {
			System.out.println("hi");
			printcube();
			System.out.println(strarr[i] + "result");//test
			resetintarr();
			int ch = strarr[i].charAt(0);
			switch(ch) {
			case 'B'://
				System.out.println("B입니다.2");//test
				copyintarr('D',3,'R',1,'U',1,'L',1);
				System.out.println("B입니다.3");//test
				break;
			case 'L'://
				//printintarr();
				//System.out.println("hi");//test
				copyintarr('B',4,'U',4, 'F',4,'D',4);
				//printintarr();
				break;
			case 'U'://
				System.out.println("Hello");//test
				copyintarr('L',2,'B',3, 'R',4,'F',1);
				break;
			case 'R'://
				copyintarr('B',2,'D',2,'F',2,'U',2);
				break;
			case 'F'://
				copyintarr('L',3,'U',3, 'R',3,'D',1);
				break;
			case 'D'://
				copyintarr('F',3, 'R',2,'B',1,'L',4);
				break;
		
			}
			
			
			int ch2 = strarr[i].charAt(1);
			switch(ch2) {
			case '+':
				spin('+');
				break;
			case '-':
				spin('-');
				break;
			}
			
			switch(ch) {
			case 'B'://
				System.out.println("B입니다.");//test
				copytocube('D',3,'R',1,'U',1,'L',1);
				break;
			case 'L'://
				copytocube('B',4,'U',4, 'F',4,'D',4);
				break;
			case 'U'://
				copytocube('L',2,'B',3, 'R',4,'F',1);
				break;
			case 'R'://
				copytocube('B',2,'D',2,'F',2,'U',2);
				break;
			case 'F'://
				copytocube('L',3,'U',3, 'R',3,'D',1);
				break;
			case 'D'://
				copytocube('F',3, 'R',2,'B',1,'L',4);
				break;
			}
		
			
			
			System.out.println("hi");
			
			
		}
	}
	public static void printintarr() {
		System.out.println("--------------------");
		for(int i=0;i<12;i++)
			System.out.print(intarr[i]+" ");
		System.out.println("\n--------------------");
	}
	public static void copytocube(char ch, int num, char ch2, int num2, char ch3, int num3, char ch4, int num4) {
		copybydirectioncube(ch,num,0);
		copybydirectioncube(ch2,num2,3);
		copybydirectioncube(ch3,num3,6);
		copybydirectioncube(ch4,num4,9);
	}
	
	public static void spin(char ch) {
		char[] temp = new char[3];
		if (ch == '+') {
			for(int i=0;i<3;i++)
				temp[i] = intarr[i+9];
			
			for(int i=8;i>=0;i--) {
				intarr[i+3] = intarr[i];
			}
			
			for(int i=0;i<3;i++) {
				intarr[i] = temp[i];
			}
		}
		else if(ch == '-') {
			for(int i=0;i<3;i++)
				temp[i] = intarr[i];
			
			for(int i=3;i<12;i++) {
				intarr[i-3] = intarr[i];
			}
			
			for(int i=0;i<3;i++) {
				intarr[i+9] = temp[i];
			}
		}
			
	}
	public static void copyintarr(char ch, int num, char ch2, int num2, char ch3, int num3, char ch4, int num4) {
		copybydirection(ch,num,0);
		copybydirection(ch2,num2,3);
		copybydirection(ch3,num3,6);
		copybydirection(ch4,num4,9);
	}
	public static void copybydirection(char ch, int direction, int indexOfintarr) {
		int x=0;
		int y=0;
		switch(ch) {
		case 'B':
			//System.out.println("niceB");//test
			x=0;
			y=3;
			break;
		case 'L':
			x=3;
			y=0;
			break;
		case 'U':
			//System.out.println("niceU");//test
			x=3;
			y=3;
			break;
		case 'R':
			x=3;
			y=6;
			break;
		case 'F':
			//System.out.println("niceF");//test
			x=6;
			y=3;
			break;
		case 'D':
			//System.out.println("niceD");//test
			x=9;
			y=3;
			break;
		}
		
		int a=0;
		switch(direction) {
		case 1:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					intarr[i] = cube[x][y+2-a];
					a++;
				}

			break;
		case 2:
			
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					intarr[i] = cube[x+2-a][y+2];
					a++;
				}
			break;
		case 3:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					intarr[i] = cube[x+2][y+a];
					a++;
				}
			
			break;
		case 4:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					intarr[i] = cube[x+a][y];
					a++;
				}
			break;
		}
		//printintarr();
	}
	
	public static void copybydirectioncube(char ch, int direction, int indexOfintarr) {
		int x=0;
		int y=0;
		switch(ch) {
		case 'B':
			//System.out.println("niceB");//test
			x=0;
			y=3;
			break;
		case 'L':
			x=3;
			y=0;
			break;
		case 'U':
			//System.out.println("niceU");//test
			x=3;
			y=3;
			break;
		case 'R':
			x=3;
			y=6;
			break;
		case 'F':
			//System.out.println("niceF");//test
			x=6;
			y=3;
			break;
		case 'D':
			//System.out.println("niceD");//test
			x=9;
			y=3;
			break;
		}
		
		int a=0;
		switch(direction) {
		case 1:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					cube[x][y+2-a] = intarr[i];
					a++;
				}

			break;
		case 2:
			
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					cube[x+2-a][y+2] = intarr[i];
					a++;
				}
			break;
		case 3:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					cube[x+2][y+a] = intarr[i];
					a++;
				}
			
			break;
		case 4:
				for(int i = indexOfintarr;i<indexOfintarr+3;i++) {
					cube[x+a][y] = intarr[i];
					a++;
				}
			break;
		}
		//printintarr();
	}
	
	public static void printcube() {
		for(int i=0;i<12;i++) {
			for(int j=0;j<9;j++)
				System.out.print(cube[i][j]+" ");
			System.out.println();
		}
	}
	
	public static void fillcube(int x, int y, char ch) {
		for(int a=x;a<x+3;a++) {
			for(int b=y;b<y+3;b++)
				cube[a][b] = ch;
		}
		return;
	}

}
