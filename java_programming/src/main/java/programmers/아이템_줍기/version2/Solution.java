package programmers.아이템_줍기.version2;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    static int[] dRow = {-1,1,0,0};
    static int[] dCol = {0,0,-1,+1};
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;

        answer = tryBFS(rectangle, characterX, characterY, itemX, itemY);

        return answer;
    }

    private int tryBFS(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {

        // BFS로 먼저 도착하는 것을 반환하게끔 설계한다.
        // 포인트 이용시, 1차원 배열을 활용.
        // 방문여부 처리도, 배열을 활용해보기.
        // 가운데 점을 이용한 처리 시도.

        int[] fP = new int[]{characterX,characterY, 0};
        // x, y, 거리.
        boolean[][] visited = new boolean[51][51];
        for (boolean[] row:visited
             ) {
            Arrays.fill(row, false);
        }

        Queue<int[]> queue = new LinkedList();

        // 초기화.
        queue.add(fP);
        visited[characterX][characterY] = true;

        int answer = 0;
        // 진행
        while(!queue.isEmpty()){
            int[] cur = queue.poll();

            // 탈출 확인.
            if(cur[0]== itemX && cur[1] == itemY){
                answer = cur[2];
                break;
            }

            int[][] pointArr = possiblePoints(cur);
            for (int[] nPoint:pointArr
                 ) {
                if(visited[nPoint[0]][nPoint[1]]==false && isItOnFrame(rectangle, cur, nPoint)){
                    visited[nPoint[0]][nPoint[1]]=true;
                    queue.add(new int[]{nPoint[0], nPoint[1], cur[2]+1});
                }
            }
        }
        // 탈출 및 반환.
        return answer;
    }

    private boolean isItOnFrame(int[][] rectangle,int[] p1,  int[] p2) {
        for (int[] recItem:rectangle
        ) {
            if(isItEdgeOfRec(recItem, p1, p2)){
                for (int[] recItem2:rectangle
                ) {
                    if (isItIncluded(recItem2,p1,p2))
                        return false;
                }
                return true;
            }
        }
        return false;
    }

    private boolean isItIncluded(int[] recItem2, int[] p1, int[] p2) {
        if(isThisPointInsideFrame(recItem2, ((float)p1[0]+p2[0])/2, ((float)p1[1]+p2[1]/2)))
            return true;
        return false;
    }
    private boolean isThisPointInsideFrame(int[] recItem, float mX, float mY) {
        if (recItem[0]< mX && mX <recItem[2]&&
                recItem[1]<mY && mY<recItem[3]){
            return true;
        }
        return false;
    }

    private boolean isItEdgeOfRec(int[] recItem, int[] p1, int[] p2) {
        if(isThisPointOnFrame(recItem, p1))
            return true;
        return false;
    }

    private boolean isThisPointOnFrame(int[] recItem, int[] p1) {
        if (recItem[0]<= p1[0] && p1[0] <=recItem[2]&&
                recItem[1]<=p1[1] && p1[1]<=recItem[3]){
            if (p1[0] == recItem[0] || p1[0] == recItem[2])
                return true;
            if (p1[1] == recItem[1] || p1[1] == recItem[3])
                return true;
        }
        return false;
    }

    private int[][] possiblePoints(int[] cur) {
        int[][] pointArr = new int[dRow.length][2];
        for (int idx = 0; idx < dRow.length; idx++) {
            pointArr[idx][0] = cur[0] + dRow[idx];
            pointArr[idx][1] = cur[1] + dCol[idx];
        }
        return pointArr;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
//        System.out.println(solution.solution(new int[][]{{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}}, 9, 7, 6, 1));
        System.out.println(solution.solution(new int[][]{{1,1,7,4},{3,2,5,5},{4,3,6,9},{2,6,8,8}}, 1, 3, 7, 8));
        System.out.println(solution.solution(new int[][]{{1,1,8,4},{2,2,4,9},{3,6,9,8},{6,3,7,7}}, 9, 7, 6, 1));
        System.out.println(solution.solution(new int[][]{{1,1,5,7}}, 1, 1, 4 ,7));
        System.out.println(solution.solution(        new int[][]{{2,1,7,5},{6,4,10,10}}, 3, 1, 7, 10));
        System.out.println(solution.solution(new int[][]{{2,2,5,5},{1,3,6,4},{3,1,4,6}}, 1, 4, 6, 3));
    }
}