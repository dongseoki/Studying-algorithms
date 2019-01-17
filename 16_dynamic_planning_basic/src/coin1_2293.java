import java.util.Scanner;
 
public class coin1_2293 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
 
        int n = in.nextInt();
        int s = in.nextInt();
        
        int[] coin = new int[n];
        int[] dp = new int[s+1];
        
        for(int i = 0 ; i < n ; i++) {
            coin[i] = in.nextInt();
        }
        
        dp[0] = 1; //최초 시작점
        for(int i = 0 ; i < n ; i++) {
            for(int j = 1 ; j <= s ; j++) {
                if(j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
            }
        }
        System.out.println(dp[s]);
    }
}
//http://extracold.tistory.com/5
//https://www.acmicpc.net/board/view/10754
