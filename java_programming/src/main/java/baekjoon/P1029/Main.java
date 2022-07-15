package baekjoon.P1029;

import java.util.*;

class Identifier {
    private int price;
    private int X;
    private int visited;

    public Identifier(int price, int X, int visited) {
        this.price = price;
        this.X = X;
        this.visited = visited;
    }

    @Override
    public boolean equals(Object o) {
        if(this == o) return true;
        if(o == null || getClass() != o.getClass()) return false;

        Identifier other = (Identifier)o;

        return other.price == price && other.X == X && other.visited == visited;
    }

    @Override
    public int hashCode() {
        return Objects.hash(X, visited); // import java.util.Objects; 가 필요함
    }

    @Override
    public String toString() {
        return "price " + this.price+" X " + this.X + " V " + this.visited + " | ";
    }
}

public class Main {
    // test
    static Map<Identifier, Integer> memo = new HashMap<Identifier, Integer>();
    static ArrayList<ArrayList<Integer>> buyGraph;




    public static void main(String[] args) {
//        System.out.println("test");
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        // 0 base
        buyGraph = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < N; i++) {
            ArrayList<Integer> rowItemList = new ArrayList<Integer>();
            char[] inputData = sc.nextLine().toCharArray();
            for (int j = 0; j < inputData.length; j++) {
                rowItemList.add(Integer.parseInt(String.valueOf(inputData[j])));
            }
            buyGraph.add(rowItemList);
        }

        int start = 0;
        System.out.println(getMaxPeo(0,0,(1<<start)));


//        System.out.println(N);
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                System.out.print(buyGraph.get(i).get(j)+ " ");
//            }
//            System.out.println();
//        }


    }

    private static boolean isThereVisited(int visited, int node){
        return (visited & (1<<node)) > 0;
    }

    private static int getMaxPeo(int cuP, int X, int visited) {
//        System.out.println("getMaxPeo start called cuP: "+ cuP+ " X "+ X+ " visited: "+ visited);
        Identifier identifier = new Identifier(cuP, X, visited);
        if (memo.containsKey(identifier)){
//            System.out.println("getMaxPeo start returned cuP: "+ cuP+ " X "+ X+ " visited: "+ visited);
            return memo.get(identifier);
        }
        int subMaxPeo = 0;
        final int LENGTH = buyGraph.get(X).size();
        for (int i = 0; i < LENGTH; i++) {
            // 탐색 노드의 조건.
            // 1 X에 연결되었으며, ,<- 제거 . 항상 연결상태 가정.
            // 2 아직 방문하지 않았으며,
            // 3 현재 금액으로 구매할수 있는 사람
            final int HOPE_PRICE = buyGraph.get(X).get(i);
            if (cuP<=HOPE_PRICE && isThereVisited(visited, i) == false){
                subMaxPeo = Math.max(subMaxPeo, getMaxPeo(HOPE_PRICE, i, visited | (1<<i)));
            }
        }
        final int Result = 1 + subMaxPeo;
        memo.put(new Identifier(cuP, X, visited), Result);
//        System.out.println("getMaxPeo start returned cuP: "+ cuP+ " X "+ X+ " visited: "+ visited);
        return Result;
    }
}