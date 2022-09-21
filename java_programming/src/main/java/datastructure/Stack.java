package datastructure;

import java.util.ArrayList;

public class Stack {
    private ArrayList<Integer> array = new ArrayList<>();
    public void put(int i) {
        array.add(i);
    }


    public int size() {
        return array.size();
    }

    public int pop() {
        if(array.isEmpty())
            throw new IndexOutOfBoundsException();
        int data = array.remove(array.size()-1);
        return data;
    }

    public int top() {
        if(array.isEmpty())
            throw new IndexOutOfBoundsException();
        int data = array.get(array.size()-1);
        return data;
    }
}
