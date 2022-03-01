package samsungproblem;
import java.util.Scanner;
 
public class robot_others {
    static int[][] map = new int[50][50];   //û���ϴ� ���
    static int count=1; //û���ϴ� ĭ�� ��
    static int dx[] = {-1,0,1,0};   //�� �̵��� ���� �迭   //��, ��, ��, ��
    static int dy[] = {0,1,0,-1};   //�� �̵��� ���� �迭
    static int N,M;
     
    static void dfs(int x, int y, int d){
        int cx, cy, cd=d;   //���� �Լ� ���� x,y,d �� ������ ���� ����
        System.out.println("x/y         d:" + x + "/" + y+"        "+d);
         
        for(int i=0;i<4;i++){    //�� 4�������� �̵��� �� �����Ƿ� 4�� ����
            cd=(cd+3)%4;    //������ �ٲٱ� ���� ��  // ��,��,��,��(0,3,2,1) ������ ����
            cx=x+dx[cd];   
            cy=y+dy[cd];    // �Ӹ��� �� �������� ��ĭ �̵�
             
            if(cx>N-2 || cx<1 || cy>M-2 || cy<1 || map[cx][cy]==1)  //�̵��� ĭ�� ���̸�
                continue;   //���� ���ư��� ���� �ٲ�
            if(x ==9 && y==2 && d==1&& map[cx][cy]==0)
            	System.out.println("yes"+cx+" "+cy);
            if(map[cx][cy]==0){ //û�� ���� ĭ�̸�
                count++;    //û���ϰ� ī��Ʈ ����
                map[cx][cy]=2;  //û���ߴٰ� ǥ�� 
                dfs(cx,cy,cd);  //����ĭ �湮�� ���� dfs�Լ� ȣ��
                return;
            }
        }
        //4������ ĭ �� �湮�� ĭ�� ������
        cd=(d+2)%4;     // ������ ���� ���� ����
        // ����
        cx=x+dx[cd];   
        cy=y+dy[cd];
        if(map[cx][cy]==1)  //������ ���� ���̸� ����
            return;
        else    //�ƴϸ�
            dfs(cx,cy,d);   //���� ��ġ�� ������ �������� dfs�Լ� ȣ��
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int d,x,y;
         N=sc.nextInt();
         M=sc.nextInt();
          
         x=sc.nextInt();
         y=sc.nextInt();
         d=sc.nextInt();
          
         for(int i=0;i<N;i++)    //�迭 �Է¹���
         {
             for(int j=0;j<M;j++)
             {
                 map[i][j]=sc.nextInt();
             }
         }
         map[x][y]=2;   //ó�� ��ġ�� ���� û���ϹǷ� û���ߴٰ� ǥ��
        dfs(x,y,d);
        System.out.println(count);
 
    }
 
}


//��ó: https://haloworld.tistory.com/59 [Halo World:)]