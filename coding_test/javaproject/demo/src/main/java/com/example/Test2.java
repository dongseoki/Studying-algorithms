package com.example;

import java.io.*;
import java.util.*;
public class Test2 {
    static int n,m,k;
    static boolean visited[][][];
    static int map[][];
    static int dx[] = {0,0,1,-1};
    static int dy[] = {1,-1,0,0};
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String [] t = br.readLine().split(" ");
        n = Integer.parseInt(t[0]);
        m = Integer.parseInt(t[1]);
        k = Integer.parseInt(t[2]);
        
        map = new int[n+1][m+1];
        visited = new boolean[n+1][m+1][k+1];
        for(int i=1; i<=n; i++) {
            String[] map_input = br.readLine().split("");
            for(int j=1; j<=m; j++) {
                map[i][j] = Integer.parseInt(map_input[j-1]);
            }
        }
        bfs();
        if(ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        }
        else {
            System.out.println(ans+1);
        }
        
    }
    public static void bfs() {
        PriorityQueue<Node>pq = new PriorityQueue<>();
        pq.add(new Node(1,1,0,0));
        visited[1][1][0] = true;
        
        while(!pq.isEmpty()) {
            Node a = pq.poll();
            if(a.x ==n && a.y==m) {
                ans = Math.min(ans, a.dist);
                break;
            }
            for(int i=0; i<4; i++) {
                int nx = a.x+dx[i];
                int ny = a.y+dy[i];

                if(isRange(nx,ny)) {
                    if(map[nx][ny]==0 && !visited[nx][ny][a.cnt]) {
                        pq.add(new Node(nx,ny,a.dist+1,a.cnt));
                        visited[nx][ny][a.cnt] = true;
                    }
                    else if(a.cnt+1<=k &&map[nx][ny]==1 && !visited[nx][ny][a.cnt+1]) {
                        pq.add(new Node(nx,ny,a.dist+1,a.cnt+1));
                        visited[nx][ny][a.cnt+1] = true;
                    }
                }
            }
        }
        
    }
    public static boolean isRange(int x, int y) {
        if(x>=1 && y>=1 && x<=n && y<=m) {
            return true;
        }
        return false;
    }
}
class Node implements Comparable<Node>{
    int x, y,dist,cnt;
    Node(int x, int y, int dist, int cnt){
        this.x=x;
        this.y=y;
        this.dist = dist;
        this.cnt =cnt;
    }
    public int compareTo(Node o) {
        return this.dist-o.dist;
    }
}