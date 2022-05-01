import java.util.Scanner;
 
public class binomial_coefficient2_11051 {
 
    static int[][] list;
 
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        list = new int[1001][1001];
        list[1][0] = list[1][1] = 1;
 
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if(i == j || j == 0)
                    list[i][j] = 1;
                else
                    list[i][j] = list[i-1][j-1] + list[i-1][j];
                
                list[i][j] %=10007;
            }
        }
        System.out.println(list[n][r]);
    }
}
//http://hellogohn.com/post_one360
//http://nackwon.tistory.com/57