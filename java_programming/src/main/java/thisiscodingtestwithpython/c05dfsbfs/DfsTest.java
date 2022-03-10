package thisiscodingtestwithpython.c05dfsbfs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DfsTest {
    public static boolean[] visited = new boolean[90];
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();

    public static void dfs(int x){
        visited[x] = true;
        System.out.println("x = " + x);
        for (int i = 0; i < graph.get(x).size(); i++) {
            int y = graph.get(x).get(i);
            if(!visited[y])
                dfs(y);
        }
    }

    public static void main(String[] args) {
        for(int i =0;i<90;i++){
            graph.add(new ArrayList<Integer>());
        }

        // 노드 1에 연결된 노드 정보 저장
//        graph.get(1).add(2);
//        graph.get(1).add(3);
//        graph.get(1).add(8);
        graph.set(1,new ArrayList<>(Arrays.asList(2,3,8)));

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

        dfs(1);

    }




}
