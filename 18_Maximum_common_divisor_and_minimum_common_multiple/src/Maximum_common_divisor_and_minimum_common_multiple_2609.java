import java.util.Scanner;

public class Maximum_common_divisor_and_minimum_common_multiple_2609 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int min = Math.min(N, M);
		int max = Math.max(N, M);
		
		// �μ��� �������?
		
		//
		int temp;
		 while(true) {
			 temp = max%min;
			 if(temp ==0) {
				 break;
			 }
			 //System.out.println("hi");
			 max = min;
			 min = temp;
		 }
		 
		 System.out.println(min);
		 System.out.println(N*M/min);
	}

}
//https://blog.naver.com/jamogenius/221259721978
// ��Ŭ���� ȣ���� �̿�
