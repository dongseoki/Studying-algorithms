package baekjoon.P24416;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws  Exception{
        
//        Scanner scanner = new Scanner(System.in);
//        int n = scanner.nextInt();
        int[] inputs = {5,30};
        int[][] outputs = {{5,3},{832040,28}};
        for (int idx = 0; idx < inputs.length; idx++) {
            int n = inputs[idx];
            int[] outputItem = outputs[idx];
            if(methodRecursive(n)!=outputItem[0] || methodDP(n) != outputItem[1]){
                throw new Exception();
            }
        }
        System.out.println("success");
        
//        System.out.printf("%d %d", methodRecursive(n), methodDP(n));
    }

    private static int methodDP(int n) {
        int methodDPCnt = 0;
        int[] memo = new int[n+1];
        if(n ==1 || n==2)
            return 1;
        for (int i = 3; i <= n; i++) {
            methodDPCnt++;
            memo[i] = memo[i-1]+memo[i-2];
        }
        return methodDPCnt;
    }

    private static int methodRecursive(int n) {
        int[] methodRecursiveCnt = {0};
        fibo(n, methodRecursiveCnt);
        return methodRecursiveCnt[0];
    }

    private static int fibo(int n, int [] methodRecursiveCnt){
        if(n==1 || n==2){
            methodRecursiveCnt[0]++;
            return 1;
        }
        else return (fibo(n-1,methodRecursiveCnt) + fibo(n-2,methodRecursiveCnt));
    }
}
