package thisiscodingtestwithpython.c05dfsbfs;

import java.util.Scanner;

public class DrinkIce3_10 {
    static int[] d_r = {-1,0,+1,0};
    static int[] d_c = {0,-1,0,+1};
    static int n;
    static int m;
    static boolean[][] visited = new boolean[999][999];
    static Integer[][] graph;

    public static void dfs(int row,int column){
        visited[row][column] = true;
        for(int dir=0;dir<d_r.length;dir++){
            int s_r = row + d_r[dir];
            int s_c = column + d_c[dir];
            if (0 <=s_r && s_r <n
                    && 0<=s_c && s_c < m
                    && visited[s_r][s_c]==false
                    && graph[s_r][s_c] == 0)
                dfs(s_r, s_c);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine(); // 버퍼 지우기

        graph = new Integer[n][m];
        for (int i=0;i<n;i++){
            String str = sc.nextLine();
            for (int j = 0; j < m; j++) {
                graph[i][j] = str.charAt(j) - '0';
            }
        }


// 1 맵을 만든다.
        for (int i = 0; i < n; i++) {
            for (int m = 0; m < m; m++) {
                visited[i][m] = false;
            }
        }
// 아이스크림 개수를 초기화한다.
        int ice_count = 0;

// 2 가보지 않은 점을 왼쪽 위부터 오른쪽 아래까지 찾는다.
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < m; column++) {
// 2-1 가보지 않은 점 && 구멍이 뚫려 있다면
                if (visited[row][column] == false && graph[row][column]==0){
//   아이스크림 개수 +1 한다.
                    ice_count+=1;
//       그 점으로 dfs 탐색을 한다.
                    dfs(row, column);
                }
            }
        }

// 3 답을 출력한다.
        System.out.println("ice_count = " + ice_count);
    }
}
