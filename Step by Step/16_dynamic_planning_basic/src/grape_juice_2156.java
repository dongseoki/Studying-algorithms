import java.util.ArrayList;
import java.util.Scanner;

public class grape_juice_2156 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> grape = new ArrayList<Integer>();
		ArrayList<Integer> maxGrape = new ArrayList<Integer>();
		ArrayList<Integer> maxGrapeState = new ArrayList<Integer>();
		int num = sc.nextInt();
		for(int i=0;i<num;i++) {
			grape.add(sc.nextInt());
		}
		
		int length = grape.size();
		
		
		maxGrape.add(grape.get(0));
		maxGrapeState.add(1);
		int[] ca = new int[3];
		int max;
		
		for(int i=1;i<num;i++) {
			for(int j=0;j<3;j++)
				ca[j] =0;
			max =0;
			//1 그 수를 포함, 그 전수를 포함
			// 2그 수를 포함 , 그전수를 포함X
			//3 그 수를 포함 하지 않음
			
			ca[0] = grape.get(i) + grape.get(i-1); 
			if(i-3>=0)
				ca[0]+=maxGrape.get(i-3);
			
			ca[1] = grape.get(i);
			if(i-2>=0)
				maxGrape.get(i-2);
			ca[2] = maxGrape.get(i-1);
			
			//System.out.println(ca[0]+" "+ ca[1]+" " + ca[2]);
			int caseT=0;
			for(int j=0;j<3;j++) {
				if(max<ca[j]) {
					max = ca[j];
					caseT = j;
				}
			}
			
			if(caseT==0) 
				maxGrapeState.add(2);
			else
				maxGrapeState.add(1);
			
			maxGrape.add(max);
		}
//		for(int i=0;i<maxGrape.size();i++) {
//			System.out.println(maxGrape.get(i));
//		}
		//int sum = drinkingALot(grape,0, 0,length,0);
		//System.out.println(sum);
		System.out.println(maxGrape.get(maxGrape.size()-1));

	}
	
	public static int drinkingALot(ArrayList<Integer> grape,int sum, int start, int length, int state) {
	// state true : you can drink grape juice 연달아.
		// end  term.
		if(start>=length) {
			return sum;
		}
		
		//case 1 : skip this index th juice.
		int case1 = drinkingALot(grape, sum, start+1, length, 0);
		
		int case2=0;
		if(state<2) {
			case2 = drinkingALot(grape, sum+ grape.get(start), start+1, length, state+1);
		}
		
		return Math.max(case1, case2);
		
	}

}
