package com.example;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    static class Pair {
        private int x; // 여기까지 올때 뚫은 벽 개수
        private int y; // 경로의 길이.
    
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    
        public int getX(){
            return x;
        }
    
        public int getY(){
            return y;
        }
    }
    public static void main( String[] args )
    {
        Scanner sc = new Scanner(System.in);
        int N =sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        ArrayList<ArrayList<Integer>> datas = new ArrayList<ArrayList<Integer>>();
        sc.nextLine();
        for(int i=0;i<N;i++){
            String line = sc.nextLine();
            String[] strarr =line.split("");
            ArrayList<Integer> intAL = new ArrayList<Integer>();
            for (String item : strarr){
                intAL.add(Integer.parseInt(item));
            }
            datas.add(intAL);
        }

        // System.out.println(datas.toString());
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                System.out.print(datas.get(i).get(j)+ " ");
            }
            System.out.println();
        }

        ArrayList<ArrayList<Integer>> vMap = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<N;i++){
            ArrayList<Integer> tempList = new ArrayList<>();
            for(int j=0;j<M;j++){
                tempList.add(0);
            }
            vMap.add(tempList);
        }



        // bfs 수도 코드.
        // 현재 위치를 큐에 넣음.
        // 아래를 반복함.
        // while(큐가 비어있지 않아)
        // 하나를 뺀다.
        // 근처 가보지 않은 점들을 탐색한다.
        // 탐색 한 점을 큐에 넣는다. 종료한다.

        int[] dr = {+1,0,-1,0};
        int[] dc = {0,+1,0,-1};

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(0, 0));
        while(!queue.isEmpty()){
            Pair here = queue.poll();
            for(int i=0;i<4;i++){
                int srchX = here.getX() + dr[i];
                int srchY = here.getY() + dr[i];
                // if(0<=srchX && srchX<)
            }

        }

    }
}
