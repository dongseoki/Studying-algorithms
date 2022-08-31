package baekjoon.P15651;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
//    static ArrayList<Integer> arrayList = new ArrayList<>();
    static int[] list;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        list = new int[M];

        printPermutation(0,N,M);
        bw.flush();



    }
//   기존에 선택된 수 개수.
    private static void printPermutation(int preNumCnt, int n, int m) throws IOException {
        if(preNumCnt==m){
//            arrayList.forEach(item->System.out.print(""+item+" "));
//            System.out.println();

//            arrayList.forEach(item-> {
//                try {
//                    bw.write(item + " ");
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            });

            for (int item:list
                 ) {
                try {
                    bw.write(item + " ");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            bw.write("\n");
            return;
        }
        for (int j = 1; j <= n; j++) {
//            arrayList.add(j);
            list[preNumCnt] = j;
            printPermutation(preNumCnt+1,n,m);
//            arrayList.remove(arrayList.size()-1);
        }
    }
}