import java.util.Scanner;

public class baby_shark_16236 {

	public static int[][] map;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		//StringTokenizer st = new StringTokenizer();
		int num = sc.nextInt();
		map = new int[num][num];
		String[] strarr;
		for(int i=0;i<num;i++) {
			strarr = sc.next().split(" ");
			for(int k=0;k<strarr.length;k++) {
				System.out.print(strarr[k]+ " ");
			}
			System.out.println();
			
			for(int j=0;j<strarr.length;j++)
				map[i][j] = Integer.parseInt(strarr[j]);
		}
		
		for(int i=0;i<num;i++) {
			for(int j=0;j<num;j++) {
				System.out.print(map[i][j]+ " ");
			}
			System.out.println();
		}

	}

}
