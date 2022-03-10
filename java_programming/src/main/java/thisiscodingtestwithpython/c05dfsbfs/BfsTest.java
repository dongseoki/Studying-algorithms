package thisiscodingtestwithpython.c05dfsbfs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BfsTest {
    public static boolean[] visited = new boolean[99999];
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    // BFS 함수 정의.
    public static void bfs(int start){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        // 현재 노드 방문 처리.
        visited[start] = true;
        while(!q.isEmpty()){
            // 큐에서 하나의 원소를 뽑아 출력
            int x = q.poll();
            System.out.println("x = " + x);
            for (int i = 0; i < graph.get(x).size(); i++) {
                int y = graph.get(x).get(i);
                if(!visited[y]){
                    q.offer(y);
                    visited[y] = true;
                }
            }
        }
    }


    public static void main(String[] args) {
        for (int i = 0; i < 9; i++) {
            graph.add(new ArrayList<Integer>());
        }

        // 노드 1에 연결된 노드 정보 저장
        graph.get(1).add(2);
        graph.get(1).add(3);
        graph.get(1).add(8);

        // 노드 2에 연결된 노드 정보 저장
        graph.get(2).add(1);
        graph.get(2).add(7);

        // 노드 3에 연결된 노드 정보 저장
        graph.get(3).add(1);
        graph.get(3).add(4);
        graph.get(3).add(5);

        // 노드 4에 연결된 노드 정보 저장
        graph.get(4).add(3);
        graph.get(4).add(5);

        // 노드 5에 연결된 노드 정보 저장
        graph.get(5).add(3);
        graph.get(5).add(4);

        // 노드 6에 연결된 노드 정보 저장
        graph.get(6).add(7);

        // 노드 7에 연결된 노드 정보 저장
        graph.get(7).add(2);
        graph.get(7).add(6);
        graph.get(7).add(8);

        // 노드 8에 연결된 노드 정보 저장
        graph.get(8).add(1);
        graph.get(8).add(7);

        bfs(1);
    }


}
