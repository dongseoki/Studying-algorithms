package samsungproblem;

import java.util.Scanner;

public class research_center_14502 {
    private static int[][] map;
    private static int[][] map2;
    private static int[][] map3;
    private static int[][] map4;
    private static int[][] originalmap;
    private static int[][] ansMap;
    private static boolean[][] visited;
    static int n;
    static int m;
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int safeMax =0;
		n=0;
		m=0;
		// 값을 입력받는다.
		//String[] temp;
        n = sc.nextInt();
        m = sc.nextInt();
        int area = n*m;
        map = new int[n][m]; // we will not use index 0.
        map2 = new int[n][m];
        map3 = new int[n][m];
        map4 = new int[n][m];
        originalmap = new int[n][m];
        ansMap = new int[n][m];
        visited = new boolean[n][m];
       // visit = new boolean[n+1];
        //x = n;
        for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
            	map[x][y] = sc.nextInt();
            }
        }
        copy(map, map2);

        try {
        int temp =0;
        for(int i=0;i<(area-2);i++) {
        	temp = map[i/m][i%m];
        	if( temp==2 || temp ==1)
        		continue;
        	// if ..temp ==0;...
        	map[i/m][i%m] = 1;
        	for(int j=i+1;j<(area-1);j++) {
        		temp = map[j/m][j%m];
            	if( temp==2 || temp ==1)
            		continue;
            	// if ..temp ==0;...
            	map[j/m][j%m] = 1;
            	for(int k=j+1;k<(area);k++) {
            		temp = map[k/m][k%m];
                	if( temp==2 || temp ==1)
                		continue;
                	// if ..temp ==0;...
                	map[k/m][k%m] = 1;
                	copy(map,map3);// real important
//                	if(i==1) {
//                    	System.out.println("i,j,k, count: " + " "+i +" "+j+ " "+k + " ");
//                    	System.out.println(i/m +" "+i%7+" " + map[i/m][i%m]);
//                    	System.out.println(j/m +" "+j%7+" " + map[j/m][j%m] );
//                    	System.out.println(k/m +" "+k%7+" " + map[k/m][k%m] );
//                    } // for test
                		

                	finalStage();
                	
                	int count =0;
                    for(int x=0;x<n;x++) {
                        for(int y=0;y<m;y++) {
                        	if(map[x][y] == 0)
                        		count++;
                        }
                    }
                    
                    if(safeMax<count) {
                    	safeMax = count;
                    	copy(map,ansMap);
                    }
                    
                    copy(map3, map);//initialization.
                    visitedInitialization();//initialization.
                	map[k/m][k%m] = 0;// initialization.
            	}
            	map[j/m][j%m] = 0;// initialization.
        	}
        	map[i/m][i%m] = 0; // initialization.
        }
        
        }catch(Exception e) {
        	e.getStackTrace();
        } // try end.
        
       // finalStage();
       // printMap(map);
        
        //System.out.println(1/7 +" "+ 1%7);
        
        //for test.
		// 벽을 정한다.
        
        
        System.out.println(safeMax);
        //printMap(ansMap);
        
		
	}
	
	public static void finalStage() {
		for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
            	if(map[x][y] == 2)
            		spread(x,y);
            }
        }
	}
	public static void printMap(int[][] map) {
		for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
            	System.out.print(map[x][y] + " ");
            }
            System.out.println();
        }
	}
	public static void spread(int x, int y) {
		if((0<=x && x<n) == false)
			return;
		if((0<=y && y<m) == false)
			return;
		if(visited[x][y] == true)
			return;
		// x,y 가 범위 가 아닐 경우도 빼야 한다.
		if(map[x][y] == 1)
			return;
		// case.. map[x][y] ==0 or map[x][y] ==2
		// and not visited..
		map[x][y] = 2;
		visited[x][y] = true;
		spread(x+1, y);
		spread(x,y+1);
		spread(x-1,y);
		spread(x,y-1);
	}
	
	public static void copy(int[][] map, int[][] map2) {
        for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
            	map2[x][y] = map[x][y];
            }
        }
	}
	
	public static void visitedInitialization() {
        for(int x=0;x<n;x++) {
            for(int y=0;y<m;y++) {
            	visited[x][y] =false;
            }
        }
	}

}

//
//for(int i=1;i<=62;i++) {
//	a+=i;
//	sum+=a;
//}
//System.out.println(sum);
//// test.
//// 벽을 정한다.
