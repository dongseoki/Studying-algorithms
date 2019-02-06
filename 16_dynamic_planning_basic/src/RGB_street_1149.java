import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RGB_street_1149 {
	public static int[][] house;
	public static int[][] dp;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			StringTokenizer st;
			int sum;
			int n = Integer.parseInt(br.readLine());
			house = new int[n][3]; //use 0index in row.
			dp = new int[n][3]; //use 0index in row.
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				house[i][0] = Integer.parseInt(st.nextToken());
				house[i][1] = Integer.parseInt(st.nextToken());
				house[i][2] = Integer.parseInt(st.nextToken());
			}
			
			if(n ==1) {
				sum = 2000; // 비용은 천보다 작거나 같은 자연수니까. 초기화는 불가능한 큰값으로.
				int temp;
				for(int i=0;i<3;i++) {
					temp = house[0][i];
					if(sum >temp)
						sum = temp;
				}
				System.out.println(sum);
				return ;
			}
			
			// n is bigger than 1.
			for(int i=0;i<3;i++) {
				dp[0][i] = house[0][i];
			}
			
			int x = 0;
			int y = 0;
			for(int i=1;i<n;i++) {
				for(int j=0;j<3;j++) {
					switch(j) {
					case 0:
						x = dp[i-1][1];
						y = dp[i-1][2];
						break;
					case 1:
						x = dp[i-1][0];
						y = dp[i-1][2];
						break;
					case 2:
						x = dp[i-1][0];
						y = dp[i-1][1];
						break;
					}
					dp[i][j] = Math.min(x, y) + house[i][j];
				}
			}
			sum = dp[n-1][0];
			sum = Math.min(sum, dp[n-1][1]);
			sum = Math.min(sum, dp[n-1][2]);
			System.out.println(sum);
			
			
//			
//			//test
//			for(int i=0;i<n;i++) {
//				System.out.println(house[i][0]+" "+house[i][1]+" "+house[i][2]+" ");
//			}
		}catch(Exception e) {
			System.out.println("problem");
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}

}
