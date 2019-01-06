import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class AC_5430 {
	private static int state;
	private static int n;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Queue<String> q = new LinkedList<String>();
		StringBuilder strBuild;
		
		String command;
		String strDeque;
		state =0;
		String[] strarr;
		ArrayDeque<String> deque;
		try {
		int length;
		char ch;
		
		int numOfOrder =Integer.parseInt(br.readLine()); // sc.nextline has problems.
		for(int i=0;i<numOfOrder;i++) {
			int Rcount =0;// initialization.
			strBuild = new StringBuilder();
			state = 0; // initialization.
			deque = new ArrayDeque<String>();
//			command= sc.nextLine();
//			n = Integer.parseInt(sc.nextLine());
//			strDeque = sc.nextLine();
			 
			//System.out.println(n);
			 //System.out.println(command + "A");
			//System.out.println(strDeque + "A");
			
			command = br.readLine();
			n = Integer.parseInt(br.readLine());
			strDeque = br.readLine();
			 length = command.length();
			 
//			 System.out.println(command);
//			 System.out.println("Hi");
//			 System.out.println(n);
//			 System.out.println(strDeque);
			 
			 if(!strDeque.equals("[]")) {
				 strDeque=strDeque.substring(1, strDeque.length()-1);
				 strarr = strDeque.split(",");
				 for(int j=0;j<strarr.length;j++) {
					 deque.offerLast(strarr[j]);
				 }
			 }
				 for(int j=0;j<length;j++) {
					 ch = command.charAt(j);
					 if(ch == 'R')
						 Rcount++;
					 if(ch =='D') {
						 D(deque, Rcount);
						// System.out.println("Hi");//test
					 }
					 if(state == -1) {
						 q.offer("error");
						 break;
					 }
				 }
			if(Rcount%2 ==1)
				R(deque);
			 
			 if(state ==-1)
				 continue;
			 
			 strDeque = "[";
			 strBuild.append("[");
			 if(!deque.isEmpty()) {
				 //strDeque+=deque.pollFirst();
				 strBuild.append(deque.pollFirst());
			 }
				 
			 while(!deque.isEmpty()) {
				 //strDeque+=","+deque.pollFirst();
				 strBuild.append(",");
				 strBuild.append(deque.pollFirst());
			 }
			 
			 //strDeque+="]";
			 strBuild.append("]");
			 q.offer(strBuild.toString());
		}
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("error:" +e.getStackTrace());
		}
		
		
		
		while(!q.isEmpty()) {
			System.out.println(q.poll());
			//System.out.println("hi");
		}
		
		//System.out.println("Hi");// test
		
	}

	public static void R(ArrayDeque<String> deque) {
		int size = deque.size();
		Stack<String> stack = new Stack<String>();
		if (size == 0 || size == 1)
			return;
		while(!deque.isEmpty())
			stack.push(deque.pollFirst());
		while(!stack.isEmpty())
			deque.offerLast(stack.pop());
	}

	public static void D(ArrayDeque<String> deque, int Rcount) {
		//System.out.println( "deque.size()"+ deque.size());//test
		int size = deque.size();
		if (size == 0) {
			state = -1;
			return;
		}
		if(Rcount%2 ==0)
			deque.pollFirst();
		else
			deque.pollLast();
	}

}
