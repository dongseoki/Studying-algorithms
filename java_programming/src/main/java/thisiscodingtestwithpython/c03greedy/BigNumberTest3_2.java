package thisiscodingtestwithpython.c03greedy;


import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class BigNumberTest3_2 {

//    C:\Github\Studying-algorithms\java_programming\src\test\java\thisiscodingtestwithpython\c03greedy
//    5 8 3
//    2 4 5 4 6
    public static void main(String args[]){
        System.out.println("hello world");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
//        System.out.println("k = " + k);
//        System.out.println("m = " + m);
//        System.out.println("n = " + n);
        Integer[] arr = new Integer[n];
        for (int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr,Collections.reverseOrder());

        System.out.println("arr = " + arr);
        int fbnumberCnt = (m/(k+1)) * k + m%(k+1);
        int sbnumberCnt = m - fbnumberCnt;
        int fbNum = arr[0];
        int sbNum = arr[1];
        int answer = fbNum * fbnumberCnt + sbNum * sbnumberCnt;
        System.out.println("answer is  = " +  answer);

    }

}