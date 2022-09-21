package baekjoon.P2629_TwoArmScales;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {
    static boolean[][] memo = new boolean[31][40000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int wNum = Integer.parseInt(br.readLine());

        int[] wArr =Stream.of(("0 "+br.readLine()).split(" ")).mapToInt(Integer::parseInt).toArray();
        // 0인 추가 있다고 가정.

        wNum++;
        // 0인 추도 세자.

        int tNum = Integer.parseInt(br.readLine());
        int[] tArr = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

//        System.out.println("Arrays.toString(tArr) = " + Arrays.toString(tArr));

        final int maxBallWeight = 15000;

        find_dp(0,0,wNum,wArr);

        StringBuilder sb = new StringBuilder();
        for (int target :
                tArr) {
            sb.append((target<=maxBallWeight && memo[wNum-1][target]) ? "Y ":"N ");
            // wNum -1  이 가장 마지막추의 idx이다.
        }
        System.out.println(sb.toString());
    }

    private static void find_dp(int curIdx, int cWeight, int wNum, int[] wArr) {
        //System.out.printf("called find_dp(%2d, %2d)\n ", curIdx,cWeight);
        if(memo[curIdx][cWeight]){
            return;
        }
        memo[curIdx][cWeight] = true;

        if(curIdx==(wNum-1))
            return;
        find_dp(curIdx+1, cWeight, wNum, wArr);
        find_dp(curIdx+1, cWeight+wArr[curIdx+1], wNum, wArr);
        find_dp(curIdx+1, Math.abs(cWeight-wArr[curIdx+1]) , wNum, wArr);
    }
}
