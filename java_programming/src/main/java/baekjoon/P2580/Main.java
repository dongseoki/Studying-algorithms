package baekjoon.P2580;

import java.util.*;
import java.util.stream.Stream;

public class Main {
    static int[][] sdocuMap = new int[10][10];
    static boolean[][] rowChecks = new boolean[10][10];
    static boolean[][] colChecks = new boolean[10][10];
    static boolean[][] sqChecks = new boolean[10][10];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        File testFile = new File("./src/main/java/baekjoon/P16768_MooyoMooyo/input2.txt");
//        Scanner scanner;
//        try{
//            scanner = new Scanner(testFile, StandardCharsets.UTF_8);
//        }catch(Exception e){
//            System.out.println("exception occured");
//            return;
//        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sdocuMap[i][j]= scanner.nextInt();
                int num =sdocuMap[i][j];
                rowChecks[i][num] = true;
                colChecks[j][num] = true;
                sqChecks[whichSquareIsIt(i,j)][num] = true;
            }
        }
        printAnswer();


//        System.out.println("test");
//        System.out.println(Arrays.deepToString(sdocuMap));





    }

    private static void printAnswer() {
        ArrayList<int[]> pointsList = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(sdocuMap[i][j]==0){
                    pointsList.add(new int[]{i,j});
                }
            }
        }

        bruteForce(0,pointsList);
    }

    private static boolean bruteForce(int sIdx, ArrayList<int[]> pointsList) {
        if(sIdx == pointsList.size()){
            // 답을 출력.
            for (int i = 0; i < 9; i++) {

                for (int j = 0; j < 9; j++) {
                    System.out.print(sdocuMap[i][j]+ " ");
                }
                System.out.println();
            }
            System.out.println();
            return true;
        }
        int[] point = pointsList.get(sIdx);
        for (int i = 1; i <= 9; i++) {
            // 해당 위치에 true값이 아니다로 채워져 있는지?
            if(rowChecks[point[0]][i] == false
                    && colChecks[point[1]][i] == false
                    && sqChecks[whichSquareIsIt(point[0],point[1])][i] == false){
                rowChecks[point[0]][i] =true;
                colChecks[point[1]][i] =true;
                sqChecks[whichSquareIsIt(point[0],point[1])][i] =true;
                sdocuMap[point[0]][point[1]] = i;

//                bruteForce(sIdx+1, pointsList);
                if (bruteForce(sIdx+1, pointsList)){
                    return true;
                }
                // 위 조건식은 여러건 찾는 것을 막기위해 넣음.

                sdocuMap[point[0]][point[1]] = 0;
                rowChecks[point[0]][i] =false;
                colChecks[point[1]][i] =false;
                sqChecks[whichSquareIsIt(point[0],point[1])][i] =false;

            }
        }
        return false;
    }

    private static int whichSquareIsIt(int i, int j) {
        return (i/3)*3 + j/3;
    }
}
