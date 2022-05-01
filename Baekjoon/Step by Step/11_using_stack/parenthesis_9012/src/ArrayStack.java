import java.util.EmptyStackException;

public class ArrayStack {
	private int array[];
	private int topIndex;
	public ArrayStack() {
		array = new int[1];
		topIndex = -1;
	}
	public void resize(int newSize) {
		int[] t= new int[newSize];
		for(int i=0;i<size();i++) {
			t[i] = array[i];
			
		}
		array = t; // page49
	}
	
	public void push(int num) {
		if(size() == array.length)
			resize(2*array.length);
		array[++topIndex] = num;
		
	}
	public int pop() {
		if (empty() == 1)
			return -1;
		int popNum = array[topIndex];
		--topIndex;
		return popNum;
	}
	public int size() {
		return topIndex+1;
	}
	public int empty(){
		if(topIndex == -1)
			return 1;
		else
			return 0;
	}
	public int top() {
		if(empty() == 1)
			return -1;
		return array[topIndex];
		
		
	}
	
	public void showAll(){
		for(int i=0;i<size();i++) {
			System.out.print(array[i] + " ");
			
		}
		System.out.println();
		
	}
	
}
