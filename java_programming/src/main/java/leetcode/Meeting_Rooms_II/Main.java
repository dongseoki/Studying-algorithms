package leetcode.Meeting_Rooms_II;

import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        int[][][] testInputs =
                new int[][][]{
                        {{0,30},{5,10},{15,20}},
                        {{7,10},{2,4}},
                        {{0,30}, {5,10}, {12,14}, {6,15}, {11,13}, {12,17}},
                        {{2,15},{36,45},{9,29},{16,23},{4,9}}
                };
        int[] expectedOutputs = {
                2,
                1,
                5,
                2
        };

        for (int i = 0; i < testInputs.length; i++) {
            int result = solution(testInputs[i]);
//            int result = minMeetingRoomsJerry(testInputs[i]);
            if(result!=expectedOutputs[i]){
                System.out.println(Arrays.deepToString(testInputs[i]));
                System.out.println("expectedOutputs[i] = " + expectedOutputs[i]);
                System.out.println("result = " + result);
                throw new IllegalStateException("틀렸습니다.");
            }

        }
        System.out.println("성공했습니다.");


    }

    private static int solution(int[][] mRooms) {
        if(mRooms.length==0)
            return 0;

        Arrays.sort(mRooms, (e1, e2)->{
            if(e1[0] == e2[0])
                return e1[1]-e2[1];
            else
                return e1[0] - e2[0];
        });

        // 초기화.
        int cnt = 1;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.add(mRooms[0][1]);

        for (int i = 1; i < mRooms.length; i++) {
            int[] meeting= mRooms[i];

            if(minHeap.peek() <= meeting[0]){
                minHeap.poll();
            }else{
                cnt++;
            }
            minHeap.add(meeting[1]);
        }

        return cnt;
    }

    public static int minMeetingRoomsJerry(int[][] intervals) {

        int numOfIntervals = intervals.length;

        int[] startPoints = new int[numOfIntervals];
        int[] endPoints = new int[numOfIntervals];

        for (int i = 0; i < numOfIntervals; i++) {
            startPoints[i] = intervals[i][0];
            endPoints[i] = intervals[i][1];
        }

        Arrays.sort(startPoints);
        Arrays.sort(endPoints);

        int numOfRooms = 0;
        int endPointIdx = 0;
        for (int i = 0; i < numOfIntervals; i++) {

            if (startPoints[i] < endPoints[endPointIdx]) {
                numOfRooms++;
            } else {

                endPointIdx++;
            }
        }
        return numOfRooms;

    }


}
