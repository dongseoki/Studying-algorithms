package programmers.양과늑대.ujone;

import java.util.*;
class Solution {
    private static int MaxCnt;
    private static Map<Integer, List<Integer>> nodes;
    public int solution(int[] info, int[][] edges) {
        MaxCnt = 0;
        nodes = new HashMap<>();
        for(int[] e : edges) {
            if(!nodes.containsKey(e[0])) nodes.put(e[0], new ArrayList<>());
            nodes.get(e[0]).add(e[1]);
        }
        List<Integer> list = new ArrayList<>();
        list.add(0);
        dfs(0, 0, 0, list, info);
        return MaxCnt;
    }
    public void dfs(int idx, int s, int w, List<Integer> list, int[] info) {
        if(info[idx]==0) s+=1;
        else w+=1;
        if(s<=w) return;

        MaxCnt = Math.max(MaxCnt, s);

        List<Integer> next = new ArrayList<>();
        next.addAll(list);
        if(nodes.containsKey(idx)) next.addAll(nodes.get(idx));
        next.remove(Integer.valueOf(idx));

        for(int n : next) {
            dfs(n, s, w, next, info);
        }

        return;
    }
}