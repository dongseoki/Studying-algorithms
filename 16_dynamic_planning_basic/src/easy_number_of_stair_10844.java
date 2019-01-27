import java.util.Scanner;

public class easy_number_of_stair_10844 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		int[] intarr = new int[10];
		int[] intarr2 = new int[10];
		
		if(N==1)
			System.out.println("9");
		else {
			
			for(int i=1;i<10;i++)
				intarr[i] = 1;
			
			int count = 1;
			while(true) {
				if(count ==N)
					break;
				for(int i=0;i<10;i++) // intarr2 초기화
					intarr2[i] = 0;
				int temp =0;
				for(int i=0;i<10;i++) {
					//System.out.println("i:"+i);
					temp = intarr[i];
					if(i != 0 && i !=9) {
						intarr2[i-1] += temp;
						intarr2[i+1] += temp;
					}
					else if( i==0) 
						intarr2[1] +=temp;
					else 
						intarr2[8] += temp;
				}
				
				for(int i=0;i<10;i++)
					intarr2[i] = intarr2[i] % 1000000000;
				
				// 복사...
				intarr = intarr2.clone(); // arr2 -> arr1 으로..
				count++;
			}
			
			int sum =0;
			for(int i=0;i<10;i++)
				sum = (sum +intarr[i]) % 1000000000;
			
			System.out.println(sum);
			
		}
		
		

	}

}
