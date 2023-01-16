package baekjoon.P_1285;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.valueOf(scanner.nextLine());
        String[][] c2Arr = new String[N][N];
        for (int i = 0; i < N; i++) {
            c2Arr[i] = scanner.nextLine().split("");
        }
        int currentTCnt = 0;
        int[] xRowTCntArr = new int[N];
        int[] xColTCntArr = new int[N];
        Arrays.fill(xRowTCntArr,0);
        Arrays.fill(xColTCntArr,0);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                String item = c2Arr[r][c];
                if(item.equals("T")){
                    currentTCnt+=1;
                    xRowTCntArr[r]+=1;
                    xColTCntArr[c]+=1;
                }
            }
        }
//        int lineMaxTCnt =Math.max(Arrays.stream(xColTCntArr).max().getAsInt(),
//                Arrays.stream(xRowTCntArr).max().getAsInt());
//        System.out.println(currentTCntlineMaxTCnt);


//        System.out.println("c2Arr = " + Arrays.deepToString(c2Arr));
    }
}
