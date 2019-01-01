import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static ArrayList<Integer> listStair = new ArrayList<Integer>();
	static ArrayList<Integer> listMax = new ArrayList<Integer>();
	static ArrayList<Integer>[] arrList;
	 //ArrayList<Integer>[] arrList;
	//arrList[0] = new ArrayList();
	public static void main(String[] args) {
		
		arrList = new ArrayList[2];
		arrList[0] = new ArrayList<>();
		arrList[1] = new ArrayList<>();
		// TODO Auto-generated method stub
			Scanner sc = new Scanner(System.in);
			int n = sc.nextInt();
			listStair.add(0); // index no. literaly.. 1th stair have index 1 
			for(int i=0;i<n;i++) {
				listStair.add(sc.nextInt());
			}
			for(int i=0;i<n+1;i++) {
				arrList[0].add(0);
				arrList[1].add(0);
			}
			
//			for(int i=0;i<n;i++) {
//				System.out.println(arrList[0].get(i) + "  "+ arrList[1].get(i));
//			}// for test
			//list.add(1);
			System.out.println(cal(n, 0));
	}
	
	public static int cal(int n, int m) { // m is only 0or 1..
		//int getNum;
		if(n==0)
			return 0;
		if(n==1)
			return listStair.get(1);
		if(arrList[m].get(n)>0)
			return arrList[m].get(n);
		if(m==1) 
			return cal(n-2, 0) + listStair.get(n);
		 //m==0... , n not 0 or 1..
//		for(int i=0;i<n+1;i++)
//			System.out.println(list.get(n));
//		
		arrList[m].set(n, cal(n-2,0) + listStair.get(n));
		if(arrList[m].get(n) < cal(n-1,1) + listStair.get(n))
			arrList[m].set(n, cal(n-1,1) + listStair.get(n));
		
		//System.out.println("value" + list.get(n));
		return arrList[m].get(n);
	}

}
