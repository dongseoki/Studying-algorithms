package baekjoon.P16768_MooyoMooyo;

import java.io.File;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.function.Function;
import java.util.function.ToIntFunction;
import java.util.stream.Stream;

public class Main {
    static int REMOVED = -1;
    static int EMPTY_VALUE = 0;
    static int[] dRow = {-1,+1,0,0};
    static int[] dCol = {0,0,-1,+1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        File testFile = new File("./src/main/java/baekjoon/P16768_MooyoMooyo/input2.txt");
//        Scanner scanner;
//        try{
//            scanner = new Scanner(testFile, StandardCharsets.UTF_8);
//        }catch(Exception e){
//            System.out.println("exception occured");
//            return;
//        }
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int[][] hayMap = new int[N][10];


        for (int[] row :
                hayMap) {
            Arrays.fill(row, 0);
        }
        scanner.nextLine();
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            hayMap[i] = Stream.of(line.split("")).mapToInt(Integer::parseInt).toArray();
        }
        hayMap = mooyomooyo(hayMap, K);

        for (int[] row :
                hayMap) {
            for (int item :
                    row) {
                System.out.print(item);
            }
            System.out.println();
        }

//        System.out.println("hayMap = " + Arrays.deepToString(hayMap));
    }

    private static int[][] mooyomooyo(int[][] hayMap, int K) {
        while(true){
            int removeCnt = removing(hayMap,K);
            if(removeCnt>0){
                hayMap = falling(hayMap);
            }else {
                break;
            }
        }
        return hayMap;
    }

    private static int[][] falling(int[][] hayMap) {
        // 내려오기.
        int[][] tempMap = new int[hayMap.length][hayMap[0].length];

        // fill 0.
        for (int[] row :
                tempMap) {
            Arrays.fill(row, EMPTY_VALUE);
        }

        for (int colNum = 0; colNum < hayMap[0].length; colNum++) {
            columnFalling(colNum, hayMap, tempMap);
        }

        return tempMap;
    }

    private static void columnFalling(int colNum, int[][] hayMap, int[][] tempMap) {
        int top = hayMap.length-1;
        for (int rowVal = hayMap.length-1; rowVal >= 0; rowVal--) {
            if (hayMap[rowVal][colNum] != EMPTY_VALUE && hayMap[rowVal][colNum] != REMOVED){
                tempMap[top][colNum] = hayMap[rowVal][colNum];

                top -=1;
            }
        }
    }

    private static int removing(int[][] hayMap, int K) {

        // visitedMap 을 이용함.

        // 만약 방문하지 않은 점에 대해서 bfs 방문함.
        // bfs 방문을 끝마치고, K개 이상 되었을 경우, 방문했점 점들에 대해서 -1 (REMOVED)표시를 함. 그리고 방문했던 점의 개수르 반환함.

        boolean[][] visitedMap = new boolean[hayMap.length][hayMap[0].length];

        for (boolean[] visitRow :
                visitedMap) {
            Arrays.fill(visitRow, false);
        }

        int removeCnt = 0;
        for (int rowVal = 0; rowVal < hayMap.length; rowVal++) {
            for (int colVal = 0; colVal < hayMap[0].length; colVal++) {
                if(visitedMap[rowVal][colVal]==false && hayMap[rowVal][colVal] != EMPTY_VALUE){
                    visitedMap[rowVal][colVal] = true;
                    removeCnt += bfs(hayMap, rowVal, colVal, visitedMap, K);
                }
            }
        }
        return removeCnt;
    }

    private static int bfs(int[][] hayMap, int rowVal, int colVal, boolean[][] visitedMap, int k) {
        List<int[]> connectedRegionPoints = new ArrayList<>();
        Queue<int[]> queue = new LinkedList<int[]>();

        //  초기화.
        queue.add(new int[]{rowVal, colVal});
        connectedRegionPoints.add(new int[]{rowVal, colVal});
        final int CUR_COLOR = hayMap[rowVal][colVal];
        int result = 0;

        // 진입
        while(queue.isEmpty()==false){
            int[] here = queue.poll();
            // 탈출
            // 필요 없음.
            //

            //탐색
            for (int idx = 0; idx < dRow.length; idx++) {
                int searchRow = here[0] + dRow[idx];
                int searchCol = here[1] + dCol[idx];
                if (0<= searchRow && searchRow<hayMap.length && 0<=searchCol && searchCol<hayMap[0].length
                    && visitedMap[searchRow][searchCol]==false && hayMap[searchRow][searchCol] == CUR_COLOR){
                    visitedMap[searchRow][searchCol] = true;
                    queue.add(new int[]{searchRow, searchCol});
                    connectedRegionPoints.add(new int[]{searchRow, searchCol});
                }
            }
        }


        if(connectedRegionPoints.size() >= k){
            result = connectedRegionPoints.size();
            for (int[] point :
                    connectedRegionPoints) {
                hayMap[point[0]][point[1]] = REMOVED;
            }
        }

        return result;
    }
}
