package programmers.더_맵게;

import java.util.PriorityQueue;

public class Solution {
  public int solution(int[] scoville, int K) {
    int answer = 0;
    PriorityQueue<Integer> scovilllePriorityQueue = new PriorityQueue<>();
    // 초기화
    for (int scovilleItem:
        scoville){
      scovilllePriorityQueue.add(scovilleItem);
    }

    // 차근 차근 빼서, K 이상 지 확인하고, 그 횟수를 리턴하자.
    answer = calculateMinMixValue(scovilllePriorityQueue, K);

    return answer;
  }

  private int calculateMinMixValue(PriorityQueue<Integer> scovilllePriorityQueue, int k) {
    int mixCount  = 0;
    int initialFoodCount = scovilllePriorityQueue.size();
    while(scovilllePriorityQueue.size()>=2){
      int sco1 = scovilllePriorityQueue.poll();
      int sco2 = scovilllePriorityQueue.poll();
      if(sco1 >= k){
        break;
      }
      scovilllePriorityQueue.add(sco1  + sco2 * 2);
      mixCount++;
    }

    // 예외 -1 처리.
    if (initialFoodCount - 1 == mixCount && scovilllePriorityQueue.poll()<k) {
      // 이러한 상태는 음식 1개가 남을때까지 다 섞은 것.
      mixCount = -1;
    }

    return mixCount;
  }
}
