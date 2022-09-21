package baekjoon.P1931;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] met = new int[N][2];
        for (int i = 0; i < N; i++) {
            met[i][0] = scanner.nextInt();
            met[i][1] = scanner.nextInt();
        }

        Arrays.sort(met, (c1,c2)->{
           if(c1[1] ==c2[1])
               return c1[0] - c2[0];
           return c1[1] - c2[1];
        });

        int end = 0;
        int cnt= 0;
        for (int[] item :
                met) {
            if(end<=item[0]){
                end = item[1];
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}
