package programmers.가장_먼_노드;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
  static final int NO_DATA = -1;
  final
  public int solution(int n, int[][] edge) {
    int answer = 0;

    // 사전준비, 길이 배열과 인접 행렬 리스트.
    int[] distances = new int[n+1];
    Arrays.fill(distances, NO_DATA);
    List<Integer>[] adjMatrix = makeAdjMatrix(n, edge);
    return bfs(distances, adjMatrix);
  }

  private int bfs(int[] distances, List<Integer>[] adjMatrix) {
    // bfs를 해서 1부터 해당 노드까지의 거리를 배열에 따로 담음.
    Queue<Integer> queue = new LinkedList<>();
    queue.add(1);
    distances[1] = 0;
    int maxDistance = NO_DATA;
    int count = 0;
    
    while(!queue.isEmpty()){
      int nodeNum = queue.poll();
      int currentDisstance = distances[nodeNum];
      if(maxDistance < currentDisstance){
        maxDistance = currentDisstance;
        count = 1;
      } else if (maxDistance == currentDisstance) {
        count++;
      }
      for (int searchNode :
          adjMatrix[nodeNum]) {
        if(distances[searchNode] == NO_DATA){
          distances[searchNode] = currentDisstance +1;
          queue.add(searchNode);
        }
      }
    }

    return count;
  }

  private static List<Integer>[] makeAdjMatrix(int n, int[][] edge) {
    List<Integer>[] adjMatrix = new List[n +1];
    int length = adjMatrix.length;
    for (int i = 0; i < length; i++) {
      adjMatrix[i] = new LinkedList<>();
    }
    for (int[] edgeInfo: edge
         ) {
      adjMatrix[edgeInfo[0]].add(edgeInfo[1]);
      adjMatrix[edgeInfo[1]].add(edgeInfo[0]);
    }
    return adjMatrix;
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    solution.solution(2, new int[][]{{1,2}});
  }
}