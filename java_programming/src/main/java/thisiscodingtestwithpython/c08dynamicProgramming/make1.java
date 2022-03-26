package thisiscodingtestwithpython.c08dynamicProgramming;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class make1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int[] m1cArr = new int[X+1];
        for (int i = 0; i < m1cArr.length; i++) {
            m1cArr[i]=0;
        }

        m1cArr[1] = 0;

        List<Integer> candiLi = new ArrayList<>();
        for (int num = 2; num < X+1; num++) {

            if (num % 5 ==0)
                candiLi.add(m1cArr[num/5]+1);
            if (num % 3 ==0)
                candiLi.add(m1cArr[num/3]+1);
            if (num % 2 ==0)
                candiLi.add(m1cArr[num/2]+1);
            candiLi.add(m1cArr[num-1]+1);
            Integer min = candiLi.stream().mapToInt(v->v).min().orElseThrow(NoSuchElementException::new);
            m1cArr[num] = min;

            // 후 처리.
            candiLi.clear();
        }
        for (int val:m1cArr
             ) {
            System.out.println("val = " + val);
        }
        System.out.println("m1cArr[X] = " + m1cArr[X]);

    }
}
