

public class Combi {
    public static int count = 0; 
    // https://minhamina.tistory.com/38
    public static void main(String[] args) {
        // int[] arr = {1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //조합을 만들 배열 
        // boolean[] visited = new boolean[arr.length];
 
        //1. 백트래킹을 이용해 구현
        System.out.println("-------- 1. 백트래킹 ---------");
    
        // for(int r = 1; r <= arr.length; r++) {
        // 	System.out.println("\n" + arr.length + "개 중에 " + r  + "개 뽑음");
        //     comb1(arr, visited, 0, r);
        // }
        // comb1(arr, visited, 0,10);
        int n = 3;
        int[] arr = {1, 2, 3};
        int[] output = new int[n];
        boolean[] visited = new boolean[n];

        perm(arr, output, visited, 0, n, 3);
        // perm(arr, output, visited, depth, n, r);

        System.out.println(count);


        
    }
    static void perm(int[] arr, int[] output, boolean[] visited, int depth, int n, int r) {
        if (depth == r) {
            count +=1;
            return;
        }
     
        for (int i=0; i<n; i++) {
            if (visited[i] != true) {
                visited[i] = true;
                output[depth] = arr[i];
                perm(arr, output, visited, depth + 1, n, r);       
                output[depth] = 0; // 이 줄은 없어도 됨
                visited[i] = false;;
            }
        }
    }
 
    //1. 백트래킹을 이용해 구현
    static void comb1(int[] arr, boolean[] visited, int start, int r) {
        if(r == 0) {
            // print(arr, visited);
            count += 1;
            return;
        } else {
            for(int i = start; i < arr.length; i++) {
                visited[i] = true;
                comb1(arr, visited, i + 1, r - 1);
                visited[i] = false;
            }
        }
    }
 
    // 배열 출력
    static void print(int[] arr, boolean[] visited) {
        for(int i = 0; i < arr.length; i++) {
            if(visited[i] == true)
                System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
