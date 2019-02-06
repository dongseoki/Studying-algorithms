package samsungproblem;
import java.util.ArrayList;
import java.util.Scanner;

public class Resignation_14501 {
	public static ArrayList<Integer> t;
	public static ArrayList<Integer> p;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		t = new ArrayList<Integer>();
		p = new ArrayList<Integer>();
		int N = sc.nextInt();
		
		t.add(0);
		p.add(0);// we do not use index zero.
		for(int i=0;i<N;i++) {
			t.add(sc.nextInt());
			p.add(sc.nextInt());
		}
		
		int sum = go(1,0,N);
		System.out.println(sum);
//		for(int i =0;i<N;i++) {
//			System.out.println(t.get(i)+" "+p.get(i));
//		}
	}
	
	public static int go(int day, int sum, int N) {
		int temp;
		int temp2;
		//System.out.println("day/sum/N : " +day + " "+ sum + " "+N);
		
//		if(day ==N) {
//			if(t.get(day) ==1)
//				return sum+p.get(day);
//			else
//				return sum;
//		}
		if(day>N) {
			if(day==N+1)
				return sum;
			return -1;
		}
			
		
		
		//day 일에 대해 상담을 할까 말까?
		temp =  go(day+t.get(day), sum + p.get(day), N);
		temp2 = go(day+1,sum,N);
		//System.out.println(temp + " " + temp2);
		
		return Math.max(temp, temp2);
	}
}
