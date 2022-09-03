package baekjoon.P10816;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(System.in);
        // 트리 셋.
        //given
        int N = scanner.nextInt();
        scanner.nextLine();
        int[] sangunNums = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int M = scanner.nextInt();
        scanner.nextLine();
        int[] searchNums = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();


        //when
        int[] result = countNumbers(N, sangunNums, M, searchNums);


//        int[] expectedOutputs = Arrays.stream("3 0 0 1 2 0 0 2".split(" ")).mapToInt(Integer::parseInt).toArray();

        // then
        // 테스트 코드.
//        if (!Arrays.equals(result, expectedOutputs))
//            throw new Exception("틀립니다.");

        BufferedWriter bufferedWriter = new BufferedWriter((new OutputStreamWriter(System.out)));

        for (int item :
                result) {
            bufferedWriter.write(""+ item+" ");
        }
        bufferedWriter.flush();
    }

    private static int[] countNumbers(int n, int[] sangunNums, int m, int[] searchNums) {
        // 초기화.
        int[] result = new int[searchNums.length];
        Map<Integer, Integer> numToCntMap = new HashMap<>();
        for (int num :
                sangunNums) {
            numToCntMap.put(num, numToCntMap.getOrDefault(num, 0) + 1);
        }

        // 작업
        for (int idx = 0; idx < searchNums.length; idx++) {
            int target = searchNums[idx];
            result[idx] = numToCntMap.getOrDefault(target, 0);
        }

        // 결과를 반환.
        return result;
    }
}
