package exercise230116.BJ_P1260;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] metaInfoArr =  br.readLine().trim().split(" ");
    int numOfPoint = Integer.valueOf(metaInfoArr[0]);
    int numOfEdge = Integer.valueOf(metaInfoArr[1]);
    int startPoint = Integer.valueOf(metaInfoArr[2]);
    ArrayList<ArrayList<Integer>> adjMatrix = new ArrayList<>();
    for (int i = 0; i < (numOfPoint + 1); i++) {
      adjMatrix.add(new ArrayList<>());
    }

    for (int i = 0; i < numOfEdge; i++) {
      String[] lineInfo = br.readLine().trim().split(" ");
      int v1 = Integer.valueOf(lineInfo[0]);
      int v2 = Integer.valueOf(lineInfo[1]);
      adjMatrix.get(v1).add(v2);
      adjMatrix.get(v2).add(v1);
    }

    for (int i = 1; i <= numOfPoint; i++) {
      Collections.sort(adjMatrix.get(i));
    }

//    System.out.println("adjMatrix = " + adjMatrix);
    boolean[] visited = new boolean[numOfPoint+1]; // 1 base index.
    Arrays.fill(visited, false);
    System.out.print(""+startPoint + " ");
    visited[startPoint] = true;

    dfs(adjMatrix, startPoint, visited);
    System.out.println();

    bfs(adjMatrix, startPoint);



  }

  private static void dfs(ArrayList<ArrayList<Integer>> adjMatrix, int here, boolean[] visited) {
    ArrayList<Integer> connectedNodes = adjMatrix.get(here);
    for (int node :
          connectedNodes) {
      if(!visited[node]){
        visited[node] = true;
        System.out.print(""+node + " ");
        dfs(adjMatrix, node, visited);
      }
    }
  }

  private static void bfs(ArrayList<ArrayList<Integer>> adjMatrix, int startPoint){
    boolean[] visited = new boolean[adjMatrix.size()];
    Arrays.fill(visited, false);
    Queue<Integer> queue = new LinkedList<>();

    queue.add(startPoint);
    visited[startPoint] = true;

    while(!queue.isEmpty()){
      int here = queue.poll();
      System.out.print(""+ here+ " ");

      ArrayList<Integer> connectedNodes =  adjMatrix.get(here);
      for (int node :
              connectedNodes) {
        if (!visited[node]) {
          visited[node] = true;
          queue.add(node);
        }
      }

    }
    System.out.println();
  }
}
