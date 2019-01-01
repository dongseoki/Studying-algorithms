import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
public class Finding_routue_11403 {
 
    private static int n, m, v;
    private static int[][] map;
    private static int[][] map2;
    private static boolean[] visit;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
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
//            for(int x=1;x<=n;x++) {
//                for(int y=1;y<=n;y++) {
//                	System.out.print(map[x][y] + " ");
//                }
//                System.out.println();
//            }
            
            // bfs ½ÃÀÛ
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
        visit = new boolean[n+1];// visit[0] will not be used.
        
        queue.offer(k);// k¸¦ Å½»ç.
        while(!queue.isEmpty()) {
            int temp = queue.poll(); //  k¸¦ »©º¸°í.  from 65line. 
            for(int i=1; i<=n; i++) {
                if(map[temp][i] == 1 && !visit[i]) {
                	// can go  && have not visited.
                	map2[k][i] = 1; // new map. we want to know k with others.
                    queue.offer(i); // we will look at it after all.
                    visit[i]= true;
                }
            }
        }
    }
   
}