package print_queue_1966;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			PriorityQueue<Textfile> pq = null;
			Queue<Textfile> qu = null;
			Queue<Integer> qInt = new LinkedList<Integer>();
			
			//pq.offer(e)
			int temp;
			int  N;//num of text
			int M; // num of index;
			Scanner sc = new Scanner(System.in);
			int numOfOrder=sc.nextInt();
			for(int i=0;i<numOfOrder;i++) {
				pq = new PriorityQueue<Textfile>();// initialization..
				qu = new LinkedList<Textfile>();//also
				 N= sc.nextInt();
				 M= sc.nextInt();
				 for(int j=0;j<N;j++) {
					  temp = sc.nextInt();
					  qu.offer(new Textfile(j, temp));
					  pq.offer(new Textfile(j, temp));
				 }
				 //action.
				 qInt.offer(action(pq,qu,M));
			}
			
			while(!qInt.isEmpty()) {
				System.out.println(qInt.poll());
			}
			
			//return;		
	}
	
	public static int action(PriorityQueue<Textfile> pq, Queue<Textfile> qu, int M) {
		int count =0;
		while(!qu.isEmpty()) {
			Textfile tf = pq.peek();
			Textfile printq = qu.peek();
			if(printq.getPriority() <tf.getPriority()) {
				qu.offer(qu.poll()); // go back.
			}
				
			else { // we have to print text in queue;
				Textfile temp2  = qu.poll(); 
				if(temp2.getIndex() == M) // we want.
					return ++count;
				else
					count++;
				//System.out.println(temp.getIndex()+ " " + temp.getPriority());
				pq.poll(); 
				// we poll printq and priority queue together.
			}
		}
		return -1; // doesn't work.
	}
	
}

class Textfile implements Comparable<Textfile>{ // because priorityqueue is using Comparable implements when it decides sequence
	
	private int index;
	private int priority;
	
	public Textfile(int index, int priority) {
		this.index = index;
		this.priority = priority;
	}
	
	@Override
	public int compareTo(Textfile arg0) {
		if(this.priority<arg0.priority )
			return 1;
		else if(this.priority>arg0.priority)
			return -1;
		// TODO Auto-generated method stub
		return 0;
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}

	public int getPriority() {
		return priority;
	}

	public void setPriority(int priority) {
		this.priority = priority;
	}
	
	
}