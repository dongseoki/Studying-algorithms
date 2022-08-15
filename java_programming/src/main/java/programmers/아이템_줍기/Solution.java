package programmers.아이템_줍기;


// 1. 캐릭터 위치부터 테두리를 따라 1바퀴를 돈다.
// 1-1.한바퀴를 다돌았다고 판단되는 경우, 그 거리-후보 리스트에 있는 거리값 을 후보리스트에 넣고 반복문을 종료한다.()
// 1-2. 중간지점 방문시 그 거리를 거리 후보 리스트에 담기.

// 테두리를 따라 1바퀴를 도는 것을 확인하는 방법
// 갔던 점선은 일단 방문 리스트로 관리한다. 해쉬 맵에 넣자. 점선 정렬해서.
// 일단 (4방향)후보지점에 대해서 가능성을 판단한다.
// 시간 복잡도를 슥 계산해봤는데, 최대 방문한 점들이 20 * 20 사각형을 그린다고 가정했을때, 지점 80개, 그리고 방향 4개. 그리고 각각에 대해서 사각형 확인 4개.
// 1280 충분히 작다 가능성.


import java.util.*;
import java.util.List;
class Point implements  Comparable<Point>{
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public int compareTo(Point p) {
        if (this.getX() != p.getX())
            return this.getX() - p.getX();
        else
            return this.getY() - p.getY();
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
class Solution {
    static int[] dRow = {-1,1,0,0};
    static int[] dCol = {0,0,-1,+1};

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        answer = tryOneCircleVisit(rectangle, characterX,characterY,itemX,itemY);
        return answer;
    }

    private int tryOneCircleVisit(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        Set<Point> visitedPointSet  = new HashSet<>();
        List<Integer> candidateAnswerList = new ArrayList<>();
        Queue<Point> queue = new LinkedList<>();

        Point itemPoint = new Point(itemX, itemY);
        Point firstPoint = new Point(characterX, characterY);

        visitedPointSet.add(firstPoint); //
        queue.add(firstPoint);

        while(!queue.isEmpty()){
            Point curPoint = queue.poll();
            if(curPoint.equals(itemPoint)){
                candidateAnswerList.add(visitedPointSet.size()-1);
            }

            List<Point> availablePointList = findAvailablePointList(curPoint);
            for (Point p:availablePointList
                 ) {
                if (visitedPointSet.contains(p) == false && itItFrame(curPoint, p, rectangle)==true){
                    visitedPointSet.add(p);
                    queue.add(p);
                    break;
                }
            }
        }

        // not visted First Point so...
        int frameLength = visitedPointSet.size();
        candidateAnswerList.add(frameLength - candidateAnswerList.get(0));
        return Collections.min(candidateAnswerList);
    }

    private boolean itItFrame(Point p1, Point p2, int[][] rectangle) {
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

    private boolean isItIncluded(int[] recItem, Point p1, Point p2) {
        if(isThisPointInsideFrame(recItem, ((float)p1.getX()+p2.getX())/2, ((float)p1.getY()+p2.getY())/2))
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

    private boolean isItEdgeOfRec(int[] recItem, Point p1, Point p2) {
        if(isThisPointOnFrame(recItem, p1) && isThisPointOnFrame(recItem, p2))
            return true;
        return false;


    }

    private boolean isThisPointOnFrame(int[] recItem, Point p1) {
        if (recItem[0]<= p1.getX() && p1.getX() <=recItem[2]&&
                recItem[1]<=p1.getY() && p1.getY()<=recItem[3]){
            if (p1.getX() == recItem[0] || p1.getX() == recItem[2])
                return true;
            if (p1.getY() == recItem[1] || p1.getY() == recItem[3])
                return true;
        }
        return false;
    }

    private List<Point> findAvailablePointList(Point curPoint) {
        List<Point> aPointList = new ArrayList<>();
        for (int idx = 0; idx < dRow.length; idx++) {
            aPointList.add(new Point(curPoint.getX() + dRow[idx], curPoint.getY() + dCol[idx]));
        }

        return aPointList;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(new int[][]{{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}}, 9, 7, 6, 1));;
    }

}