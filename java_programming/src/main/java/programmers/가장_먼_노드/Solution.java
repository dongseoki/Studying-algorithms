package programmers.가장_먼_노드;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
  final
  public int solution(int n, int[][] edge) {
    int answer = 0;

    // 사전준비, 길이 배열과 인접 행렬 리스트.
    int[] distances = new int[n+1];
    Arrays.fill(distances, -1);

    List<Integer>[] adjMatrix = new LinkedList<>[n+1];
    int length = adjMatrix.length;
    for (int i = 0; i < length; i++) {
      adjMatrix[i] = new LinkedList<>();
    }
    for (int[] edgeInfo:edge
         ) {
      adjMatrix[edgeInfo[0]].add(edgeInfo[1]);
      adjMatrix[edgeInfo[1]].add(edgeInfo[0]);
    }


    // bfs를 해서 1부터 해당 노드까지의 거리를 배열에 따로 담음.
    Queue<int[]> queue = new LinkedList<>();

    // 0번 인덱스 무시하고 담을 예정.
    // 다 담은 후, 최대값 찾고, 최대값의 개수를 구해서 리터.
    return answer;
  }
}