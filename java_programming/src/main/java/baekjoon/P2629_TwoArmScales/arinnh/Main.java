package baekjoon.P2629_TwoArmScales.arinnh;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int N, M, question, max=15000, arr[];
    static boolean dp[][];

    public static void main(String [] args) throws IOException {

        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

        N= Integer.parseInt(br.readLine());
        arr= new int[N+1];
        dp= new boolean[31][max+1];

        StringTokenizer st= new StringTokenizer(br.readLine());
        for(int i=1; i<=N; i++) {
            arr[i]= Integer.parseInt(st.nextToken());
        }

        find_dp(0,0);

        StringBuilder sb= new StringBuilder();
        M= Integer.parseInt(br.readLine());
        st= new StringTokenizer(br.readLine());
        for(int i=0; i<M; i++) {
            question= Integer.parseInt(st.nextToken());
            if(question>15000)  sb.append("N ");
            else sb.append(dp[N][question]?"Y ":"N ");
        }
        System.out.println(sb);
        br.close();
    }


    // find_dp(idx, weight)의 해석. 아 지금까지 인덱스가 0이상 idx이하인 추들을 활용해서  weight라는 무게를 잴수 있었어! 그리고 다음은 뭐가 있을까?
    public static void find_dp(int idx, int weight) {
        System.out.printf("called find_dp(%2d, %2d)\n", idx, weight);
        if(dp[idx][weight]) {
            System.out.printf("True return find_dp(%2d, %2d)\n", idx, weight);
            return;
        }
        dp[idx][weight]=true;
        if(idx==N) {
            System.out.printf("N return find_dp(%2d, %2d)\n", idx, weight);
            return;
        }

        find_dp(idx+1, weight+arr[idx+1]);
        find_dp(idx+1, weight);
        find_dp(idx+1, Math.abs(weight-arr[idx+1]));
    }
}