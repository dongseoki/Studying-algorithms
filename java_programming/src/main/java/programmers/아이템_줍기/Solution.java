package programmers.아이템_줍기;


// 1. 캐릭터 위치부터 테두리를 따라 1바퀴를 돈다.
// 1-1.한바퀴를 다돌았다고 판단되는 경우, 그 거리-후보 리스트에 있는 거리값 을 후보리스트에 넣고 반복문을 종료한다.()
// 1-2. 중간지점 방문시 그 거리를 거리 후보 리스트에 담기.

// 테두리를 따라 1바퀴를 도는 것을 확인하는 방법
// 갔던 점선은 일단 방문 리스트로 관리한다. 해쉬 맵에 넣자. 점선 정렬해서.
// 일단 (4방향)후보지점에 대해서 가능성을 판단한다.
// 시간 복잡도를 슥 계산해봤는데, 최대 방문한 점들이 20 * 20 사각형을 그린다고 가정했을때, 지점 80개, 그리고 방향 4개. 그리고 각각에 대해서 사각형 확인 4개.
// 1280 충분히 작다 가능성.

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    Set<String> visitedEdgeSet  = new HashSet<String>();
    List<Integer> candidateAnswerList = new ArrayList<>();
    // 데이터 (X1 Y1) 와 (X2 Y2)  에 대해서
    // 단순 문자열 정렬한 것들중 우선순위의 점을 이용하여
    // (X1 Y1|X2 Y2) 를 문자열로 저장.(괄호 는 뺴고 생각.)
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        List<String> availableEdgeList = findAvailableEdgeList(characterX, characterY);
        String nextPosStr = getNextPos(availableEdgeList.get(0));
        visitedEdgeSet.add(availableEdgeList.get(0));
        tryOneCircleVisit(Integer.parseInt(nextPosStr.split(" ")[0]),Integer.parseInt(nextPosStr.split(" ")[1]));

        return answer;
    }

    private void tryOneCircleVisit(int curX, int curY) {
        tryOneCircleVisit(s, );
    }

}