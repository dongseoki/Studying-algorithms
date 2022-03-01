// package com.example;

// import java.io.*;
// import java.util.*;
// public class Test {
//     static int n,m;
//     static int end_x ,end_y,start_x,start_y;
//     static int map[][];
//     static boolean visited[][][];
//     static int ans = Integer.MAX_VALUE;
//     static int dx[] = {0,0,1,-1};
//     static int dy[] = {1,-1,0,0};
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
//         String [] t = br.readLine().split(" ");
//         n = Integer.parseInt(t[0]);
//         m = Integer.parseInt(t[1]);
        
//         map = new int[n+1][m+1];
//         visited = new boolean[n+1][m+1][2];
        
//         String[] tt = br.readLine().split(" ");
//         start_x = Integer.parseInt(tt[0]);
//         start_y = Integer.parseInt(tt[1]);
        
//         String[] ttt = br.readLine().split(" ");
//         end_x = Integer.parseInt(ttt[0]);
//         end_y = Integer.parseInt(ttt[1]);
        
//         for(int i=1; i<=n; i++) {
//             String [] input = br.readLine().split(" ");
//             for(int j=1; j<=m; j++) {
//                 map[i][j] = Integer.parseInt(input[j-1]);
//             }
//         }
//         bfs();
//         if(ans == Integer.MAX_VALUE) {
//             System.out.println(-1);
//         }
//         else {
//             System.out.println(ans);
//         }
//     }
//     public static void bfs() {
//         PriorityQueue<Node> q = new PriorityQueue<>();
//         q.add(new Node(start_x,start_y,0,0));
//         while(!q.isEmpty()) {
//             Node a=  q.poll();
            
//             if(a.x == end_x && a.y ==end_y) {
//                 ans = a.dist;
//                 break;
//             }
//             for(int i=0; i<4; i++) {
//                 int nx = a.x+dx[i];
//                 int ny = a.y+dy[i];
//                 if(isRange(nx,ny)) {
//                     if(map[nx][ny]==0 && !visited[nx][ny][a.flag]) {
//                         q.add(new Node(nx,ny,a.dist+1,a.flag));
//                         visited[nx][ny][a.flag] = true;
//                     }
//                     else if(a.flag ==0 && map[nx][ny]==1 && !visited[nx][ny][1]) {
//                         q.add(new Node(nx,ny,a.dist+1,1));
//                         visited[nx][ny][1] = true;
//                     }
//                 }
                
//             }
            
//         }
//     }
//     public static boolean isRange(int x, int y) {
//         if(x>=1 && y>=1 && x<=n && y<=m) {
//             return true;
//         }
//         return false;
//     }
// }
// class Node implements Comparable<Node>{
//     int x,y,dist,flag;
//     Node(int x, int y, int dist, int flag){
//         this.x=x;
//         this.y=y;
//         this.dist = dist;
//         this.flag= flag;
//     }
//     public int compareTo(Node o) {
//         return this.dist-o.dist;
//     }
// }