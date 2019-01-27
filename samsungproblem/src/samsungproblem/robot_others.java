package samsungproblem;
import java.util.Scanner;
 
public class robot_others {
    static int[][] map = new int[50][50];   //청소하는 장소
    static int count=1; //청소하는 칸의 수
    static int dx[] = {-1,0,1,0};   //행 이동을 위한 배열   //북, 동, 남, 서
    static int dy[] = {0,1,0,-1};   //열 이동을 위한 배열
    static int N,M;
     
    static void dfs(int x, int y, int d){
        int cx, cy, cd=d;   //현재 함수 내의 x,y,d 값 저장을 위한 변수
        System.out.println("x/y         d:" + x + "/" + y+"        "+d);
         
        for(int i=0;i<4;i++){    //총 4방향으로 이동할 수 있으므로 4번 돌림
            cd=(cd+3)%4;    //방향을 바꾸기 위한 식  // 북,서,남,동(0,3,2,1) 순서로 변경
            cx=x+dx[cd];   
            cy=y+dy[cd];    // 머리를 둔 방향으로 한칸 이동
             
            if(cx>N-2 || cx<1 || cy>M-2 || cy<1 || map[cx][cy]==1)  //이동한 칸이 벽이면
                continue;   //위로 돌아가서 방향 바꿈
            if(x ==9 && y==2 && d==1&& map[cx][cy]==0)
            	System.out.println("yes"+cx+" "+cy);
            if(map[cx][cy]==0){ //청소 안한 칸이면
                count++;    //청소하고 카운트 증가
                map[cx][cy]=2;  //청소했다고 표시 
                dfs(cx,cy,cd);  //다음칸 방문을 위해 dfs함수 호출
                return;
            }
        }
        //4방향의 칸 중 방문할 칸이 없으면
        cd=(d+2)%4;     // 후진을 위한 방향 설정
        // 후진
        cx=x+dx[cd];   
        cy=y+dy[cd];
        if(map[cx][cy]==1)  //후진한 곳이 벽이면 리턴
            return;
        else    //아니면
            dfs(cx,cy,d);   //현재 위치와 기존의 방향으로 dfs함수 호출
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int d,x,y;
         N=sc.nextInt();
         M=sc.nextInt();
          
         x=sc.nextInt();
         y=sc.nextInt();
         d=sc.nextInt();
          
         for(int i=0;i<N;i++)    //배열 입력받음
         {
             for(int j=0;j<M;j++)
             {
                 map[i][j]=sc.nextInt();
             }
         }
         map[x][y]=2;   //처음 위치는 먼저 청소하므로 청소했다고 표시
        dfs(x,y,d);
        System.out.println(count);
 
    }
 
}


//출처: https://haloworld.tistory.com/59 [Halo World:)]