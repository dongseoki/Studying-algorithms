import java.io.BufferedReader;
import java.io.InputStreamReader;

public class LCS_9251 {
	public static char[] chararr1;
	public static char[] chararr2;
	public static int[][] map;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String str1 = br.readLine(); // 행.
			String str2 = br.readLine(); // 열.
			int length1 = str1.length();
			int length2 = str2.length();
			int max =0;
			chararr1 = new char[length1+1];
			chararr2 = new char[length2+1];
			map = new int[length1+1][length2+1];
			for(int i=1;i<length1+1;i++) {
				chararr1[i] = str1.charAt(i-1);
			}
			
			for(int i=1;i<length2+1;i++) {
				chararr2[i] = str2.charAt(i-1);
			}
			//System.out.println("hi");
			//printchararr(chararr1,chararr1.length);
			//printchararr(chararr2,chararr1.length);

			for(int j=0;j<length2+1;j++) {
				map[0][j] =0; // 000000000000000000
			}
			for(int i=0;i<length1+1;i++) {
				map[i][0] =0; // 000000000000000000
			}
			
			//printmap(length1, length2);
			
			for(int i=1;i<length1+1;i++) {
				for(int j=1;j<length2+1;j++) {
					if(chararr1[i] == chararr2[j])
						map[i][j] = map[i-1][j-1]+1;
					else {
						if(map[i-1][j] >= map[i][j-1])
							map[i][j] = map[i-1][j];
						else
							map[i][j] = map[i][j-1]; 
					}
					if(map[i][j] >max)
						max = map[i][j];
				}
				
			}
			System.out.println(max);
			//printmap(length1, length2);
			
			//System.out.println("hi2");
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("problem");
		}
	}
	
	public static void printchararr(char[] chararr, int length) {
		for(int i=0;i<length;i++) {
			System.out.print(chararr[i]+" ");
		}
		System.out.println();
	}
	public static void printmap(int length1, int length2) {
		for(int i=0;i<length1+1;i++) {
			for(int j=0;j<length2+1;j++) {
				System.out.print(map[i][j]+" ");
			}
			System.out.println();
		}
	}

}

//http://twinw.tistory.com/126 참고.
