import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
 
public class Main {
 
    private static int n, m, v;
    private static int[][] map;
    private static boolean[] visit;
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] temp = br.readLine().trim().split(" ");
            n = Integer.parseInt(temp[0]);
            m = Integer.parseInt(temp[1]);
            v = Integer.parseInt(temp[2]);
            map = new int[n+1][n+1];
            visit = new boolean[n+1];
            while(m-->0) {
                temp = br.readLine().trim().split(" ");
                int x = Integer.parseInt(temp[0]);
                int y = Integer.parseInt(temp[1]);
                map[x][y] = map[y][x] = 1;
            }
            
            // dfs 시작
            dfs(v, n);
            
            System.out.println("");
            visit = new boolean[n+1];
            
            // bfs 시작
            bfs(v, n);
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        } 
    
    }
    
    private static void bfs(int k, int n) {
        Queue<Integer> queue = new <Integer> LinkedList();
 
        queue.offer(k);// k를 탐사.
        while(!queue.isEmpty()) {
            int temp = queue.poll(); //  k를 빼보고
            visit[temp] = true; // k is visited..
            System.out.print(temp + " ");
            for(int i=1; i<=n; i++) {
                if(map[temp][i] == 1 && !visit[i]) {
                	//map[temp][i] ==1 
                    queue.offer(i);
                    visit[i]= true;
                }
            }
        }
    }
    
    private static void dfs(int k, int n) {
        // 방문한 경우 빠져나옴
        if(visit[k]) {
            return;
        }
        
        // 방문
        visit[k] = true;
        System.out.print(k+" ");
        
        for(int i=1; i<=n; i++) {
            if(map[k][i] == 1) {
                dfs(i, n);
            }
        }
        
    }
}