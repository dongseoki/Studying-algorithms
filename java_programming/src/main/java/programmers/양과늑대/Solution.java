package programmers.양과늑대;

//canVisitCandidateSet(특정 비시티드상태) 그때 그때 사전 갱신.
//
//maxShip(X, visted(except X))
//= (isItXShip(X) ? 1 : 0) + maxShip(W, visited(included X,except W))
//
//        maxShip(X, visted(except X)) 이것의 의미
//        나는 지금 X에 있고, X를 제외하여 방문해온 점 목록이 있을때, 현 지점을 포함하여 앞으로 얻게 될 최대 양의 수.
//
//W의 조건 :
//        1.canVisitCandidateSet(visted(included X))에 포함되면서
//2. visited로 계산된 양과 늑대수 에 W분의 동물을 더해도, 양이 늑대보다 많을 경우


import java.util.*;

class Solution {
    ArrayList<ArrayList<Integer>> adjMatList;
    Map<String, Integer> memoMaxShipMap;
    //key (X한칸 뛰고visited)의 형태를 가진 문자열. value : key조건에서의 위 점화식의 값.
    Map<Integer, Integer> visitedConnectNodeMap;
    int[] infoData;

    // key : visited 비트마스크 값.  value : visited로부터 연결된 접근가능한 노드들의 bitMasking값.
    public int solution(int[] info, int[][] edges) {
        memoMaxShipMap = new HashMap<>();
        visitedConnectNodeMap = new HashMap<>();
        infoData = info;
        int answer = 0;
        adjMatList =  makeAdjMatList(info.length, edges);
        visitedConnectNodeMap.put(0,0);
        answer = maxShip(0, 0);
        return answer;
    }

    private ArrayList<ArrayList<Integer>> makeAdjMatList(int size, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjMatList = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            adjMatList.add(new ArrayList<Integer>());
        }

        for (int edgeIdx = 0; edgeIdx < edges.length; edgeIdx++) {
            int[] edgeItem = edges[edgeIdx];
            adjMatList.get(edgeItem[0]).add(edgeItem[1]);
            adjMatList.get(edgeItem[1]).add(edgeItem[0]);
        }

        return adjMatList;
    }

    private int maxShip(int X, int visited) {
//        System.out.println("maxShip called "+ X + " "+visited) ;
        if(memoMaxShipMap.containsKey(""+X+" "+visited))
            return memoMaxShipMap.get(""+X+" "+visited);

        Set<Integer> canVisitSet = new HashSet<>();
        canVisitSet.addAll(getCanVisitSet(visited));

        ArrayList<Integer> nodeConnectFromXList = adjMatList.get(X);
        for (int nodeConnectFromX:nodeConnectFromXList
             ) {
            if (isItVisted(nodeConnectFromX, visited) == false){
                canVisitSet.add(nodeConnectFromX);
            }
        }
        visitedConnectNodeMap.put(visited | (1<<X), convertSetToBinary(canVisitSet) & ~(visited | (1<<X)));

        int maxSubShip = 0;
        for (int canVisitNode:canVisitSet
             ) {
            if (canVisitNode==X)
                continue;
            int[] predictData = {0,0};
            getShipWoolfNum(predictData, visited | (1<<X));
            int predictShipNum = predictData[0];
            int predictWoolfNum = predictData[1];
            if (isItShip(canVisitNode)){
                predictShipNum +=1;
            }else
                predictWoolfNum +=1;

            if(predictShipNum >predictWoolfNum){
                maxSubShip = Math.max(maxSubShip, maxShip(canVisitNode, visited | (1<<X)));
            }

        }

        int returnValue = (isItShip(X) ? 1:0)+ maxSubShip;
        memoMaxShipMap.put(""+X+" "+visited, returnValue);

//        System.out.println("maxShip return "+ X + " "+visited + " "+ returnValue) ;
        return returnValue;
    }

    private Integer convertSetToBinary(Set<Integer> canVisitSet) {
        int result = 0;
        for (int item:canVisitSet
             ) {
            result = result | (1<<item);
        }

        return result;
    }

    private boolean isItShip(int X) {
        if(infoData[X] == 0)
            return true;
        else
            return false;
    }

    private void getShipWoolfNum(int[] predictData,int visited) {
        for (int i = 0; i < infoData.length; i++) {
            if((visited & (1<<i))!=0){
                predictData[(infoData[i] == 0 ? 0:1)]++;
            }
        }
    }

    private boolean isItVisted(int nodeConnectFromX, int visited) {
        if((visited &(1<<(nodeConnectFromX))) != 0){
            return true;
        }
        else
            return false;
    }

    private ArrayList<Integer> getCanVisitSet(int visited) {
        ArrayList<Integer> canVisitList = new ArrayList<>();
        int canVistedBitMask = visitedConnectNodeMap.get(visited);
        for (int i = 0; i < adjMatList.size(); i++) {
            if((canVistedBitMask & (1<<i))!=0){
                canVisitList.add(i);
            }

        }

        return canVisitList;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] info = {0,0,1,1,1,0,1,0,1,0,1,1};
        int[][] edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};

        System.out.println(solution.solution(info, edges));

    }
}