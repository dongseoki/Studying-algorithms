

import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.IntStream;

public class HashMapTest {
    public static void main(String[] args) throws IOException {
        // HashMap<Integer, Boolean> map = new HashMap<>();
        // map.put()
        TreeSet<Integer> set = new TreeSet<Integer>();
        set.add(1);
        set.add(2);
        set.add(11);
        set.remove(2);
        System.out.println(        set.contains(1));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=1;i<=5;i++){
            pq.add(i);
        }

        while(!pq.isEmpty()){
            System.out.println(pq.poll());
        }

        for(int item : set){
            System.out.print(item+ " ");
        }



        int[] array = new int[]{1, 2, 3, 4, 5};
        
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
            
        if(IntStream.of(array).anyMatch(x -> x == num)) {
            System.out.println("포함");
        } else {
            System.out.println("포함되지 않음");
        }    

    }
}
