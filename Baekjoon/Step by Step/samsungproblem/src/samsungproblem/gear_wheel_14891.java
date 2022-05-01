package samsungproblem;

import java.util.ArrayList;
import java.util.Scanner;

public class gear_wheel_14891 {
	public static GearWheel[] gwl;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int[] scorelist = new int[]{1,2,4,8};
		 gwl= new GearWheel[4];
		for(int i=0;i<4;i++) {
			gwl[i] = new GearWheel();
			gwl[i].gw=sc.next().toCharArray();
		}
		
		int K =  sc.nextInt();
		int num=0;
		int spinDir=0;
		for(int i=0;i<K;i++) {
			num = sc.nextInt() -1;
			spinDir = sc.nextInt();
			spiningResult(num,spinDir,+1);
			//System.out.println("m");
			switch(spinDir * (-1)) {
			case +1: // 시계방향
				gwl[num].indexOf12 = (gwl[num].indexOf12 +7)%8;
				break;
			case -1: // 시계방향
				gwl[num].indexOf12 = (gwl[num].indexOf12 +1)%8;
				break;
			} // 두번 돌리는 문제 해결을 위해 넣음.
			spiningResult(num,spinDir,-1);
			//System.out.println("end");
		}
			//System.out.println("hi3");
		int sum =0;
		for(int i=0;i<4;i++) {
			int index = gwl[i].indexOf12;
			if(gwl[i].gw[index]=='1')
				sum+=scorelist[i];
		}
		
		System.out.println(sum);
		
		
		
		
//		for(int i=0;i<4;i++) {
//			for(int j=0;j<8;j++)
//				System.out.print(gwl[i].gw[j]);
//			System.out.println();
//		}
		
		
		// TODO Auto-generated method stub
		//1. 값을 받는다
		//2. 문제를 푼다.
		
	}
	public static void spiningResult(int num, int spinDir,int spreadDir) {
		//System.out.println("start");
		//1. 영향을 받는 톱니바퀴가 있나 확인 -> 있으면 재귀 호출
		if(!((num==0&&spreadDir==-1) ||(num==3&&spreadDir==1))) {
			//System.out.println("num+spreadDir : " +num +" "+ spreadDir);
			int a =(gwl[num+spreadDir].indexOf12 +8+ spreadDir*(-1) *2)%8;
			int b = (gwl[num].indexOf12 +8+ spreadDir *2)%8;
			//System.out.println("a/b:"+a + " "+b);
			if(gwl[num+spreadDir].gw[a] !=gwl[num].gw[b])
				spiningResult(num+spreadDir,spinDir*(-1),spreadDir);
		}
		//2. 내거를 돌린다.
		//System.out.println("hi");
		switch(spinDir) {
		case +1: // 시계방향
			gwl[num].indexOf12 = (gwl[num].indexOf12 +7)%8;
			break;
		case -1: // 시계방향
			gwl[num].indexOf12 = (gwl[num].indexOf12 +1)%8;
			break;
		}
		//System.out.println("num/spinDir" + (num+1) + " "+spinDir);
		//System.out.println("hi2");
	}
	
	
	

}
class GearWheel{
	//ArrayList<Character> gw;
	char[] gw;
	int indexOf12;
	
	GearWheel(){
		gw = new char[8];
		indexOf12 = 0;
	}
	
}