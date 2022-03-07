package thisiscodingtestwithpython.c05dfsbfs;

import java.util.Stack;

public class StackQueueRecursion {

    public static void main(String[] args) {
        System.out.println("hello world");

        // stack
        Stack<Integer> s = new Stack<>();
        for(int i =0;i<5;i++){
            s.push(i);
        }
        s.pop();
        s.forEach(item-> System.out.println("item = " + item));

    }
}
