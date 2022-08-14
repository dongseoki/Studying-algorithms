package programmers.양과늑대.ellen;


import java.util.*;

class Solution {
    public static int max_sheep;
    public static int[] infos;
    public static boolean[][][] visited;
    public static ArrayList<Integer>[] connect;

    public int solution(int[] info, int[][] edges) {
        int answer = 0;
        infos = info;

        connect = new ArrayList[info.length];
        for(int i=0;i<info.length;i++){
            connect[i] = new ArrayList<Integer>();
        }

        for(int i=0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            connect[a].add(b);
            connect[b].add(a);

        }

        visited = new boolean[info.length][info.length+1][info.length+1];
        dfs(0, 0, 0);
        answer = max_sheep;
        return answer;
    }

    public static void dfs(int s, int w, int now){

        if(infos[now] == 0){
            s++;
        } else if(infos[now] == 1){
            w++;
        }


        if(w >= s) return;

        max_sheep = Math.max(max_sheep, s);


        for(int i=0;i<connect[now].size();i++){
            int next = connect[now].get(i);
            int temp = infos[now];
            if(!visited[next][s][w]){
                infos[now] = -1;
                visited[now][s][w] = true;
                dfs(s, w, next);
                infos[now] = temp;
                visited[now][s][w] = false;
            }
        }

    }
}