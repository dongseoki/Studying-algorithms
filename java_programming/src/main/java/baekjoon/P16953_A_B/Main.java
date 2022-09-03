package baekjoon.P16953_A_B;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        System.out.println(solution(A,B));
    }
    public static  int solution(int A, int B) {
        int cur = B;
        int result = 1;
        while(true){
            if (cur == A){
                break;
            }
            if (cur <A){
                result = -1;
                break;
            }



            if(cur%2==0){
                result +=1;
                cur/=2;
            }
            else if(cur%10==1){
                result +=1;
                cur /=10;
            }else{
                result = -1;
                break;
            }
        }

        return result;
    }
}
