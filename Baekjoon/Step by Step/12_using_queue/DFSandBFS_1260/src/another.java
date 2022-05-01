import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
public class another {
 
    private static int n, m, v;
    private static int[][] map;
    private static int[][] map2;
    private static boolean[] visit;
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        //int x;
        try {
            String[] temp;
            n = sc.nextInt();
            map = new int[n+1][n+1];
            map2 = new int[n+1][n+1];
            visit = new boolean[n+1];
            //x = n;
            for(int x=1;x<=n;x++) {
                for(int y=1;y<=n;y++) {
                	map[x][y] = sc.nextInt();
                }
            }
//            
//            // dfs 시작
//            //dfs(v, n);
//            
//            System.out.println("good");
//            visit = new boolean[n+1];
//            
//            for(int x=1;x<=n;x++) {
//                for(int y=1;y<=n;y++) {
//                	System.out.print(map[x][y] + " ");
//                }
//                System.out.println();
//            }
            
            // bfs 시작
            for(v=1;v<=n;v++)
            	newbfs(v, n);
            
            //System.out.println("------------------");
            for(int x=1;x<=n;x++) {
                for(int y=1;y<=n;y++) {
                	System.out.print(map2[x][y] + " ");
                }
                System.out.println();
            }
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        } 
    
    }

    private static void newbfs(int k, int n) {
        Queue<Integer> queue = new <Integer> LinkedList();
        visit = new boolean[n+1];
        queue.offer(k);// k를 탐사.
        while(!queue.isEmpty()) {
            int temp = queue.poll(); //  k를 빼보고
            //visit[temp] = true; // k is visited..
            //System.out.print(temp + " ");
            //map[k][]
            for(int i=1; i<=n; i++) {
                if(map[temp][i] == 1 && !visit[i]) {
                	//map[temp][i] ==1 
                	map2[k][i] = 1;
                    queue.offer(i);
                    visit[i]= true;
                }
            }
        }
    }
   
}