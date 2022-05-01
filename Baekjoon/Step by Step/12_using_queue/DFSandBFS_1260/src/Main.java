import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int N;
		int M;
		int V;
		//int arrint = new int[];
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		int FirstV = V;
		
		
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
		for(int i =0;i<(N+1);i++) {
			al.add(new ArrayList<Integer>());
		}
//		al.add(0, new ArrayList<Integer>());
//		al.get(0).add(1);
		int n1 =0;
		int n2 = 0;
		

		
		try {
			for(int i=0;i<M;i++) {
				n1 =sc.nextInt();
				n2 =sc.nextInt();
				al.get(n1).add(n2);
				al.get(n2).add(n1);
				
			}
		} catch(Exception e) {
			e.printStackTrace();
			System.out.println(n1 + ", " + n2+ ", " + al.size());
		}
		// end Input

//		// test out put.
//		for(int i=1;i<al.size();i++) {
//			for(int j=0;j<al.get(i).size();j++) {
//				System.out.print(al.get(i).get(j) + " ");
//				//System.out.print("hi");
//			}
//			System.out.println();
//		}
//		// good..
		
		
		
		// find DFS
		Stack<Integer> stack = new Stack();
		int visited[] = new int[N+1]; // we don't use 0 index..
		System.out.print(V + " ");
		visited[V] = 1;
		stack.push(V);
		
		while(!stack.isEmpty()) {
			V=stack.peek();
			// V's adj.
			for(int j=0;j<al.get(V).size();j++) {
				// pick up one of V's element.
				int W = al.get(V).get(j);
				// check if it is not visited or...
				if(visited[W] == 0) {
					System.out.print(W +" ");
					visited[W] = 1;
					stack.push(W);
					
					V=W;
					
					j=0;
				}
			}
			//V = stack.pop();
			stack.pop();
			//V=stack.peek();
		}
		System.out.println();
		// end.
		
		// find BFS way.
		V = FirstV;
		Queue<Integer> q = new LinkedList<Integer>();
		visited = new int[N+1];
		q.add(V);
		visited[V] =1;
		System.out.print(V + " ");
		while(!q.isEmpty()) {
			int temp = q.poll();
			for(int j=0;j<al.get(temp).size();j++) {
				int u = al.get(temp).get(j);
				if(visited[u] == 0) {
					System.out.print(u + " " );
					q.add(u);
					visited[u] = 1;
				}
			}
		}
	
	}

}
