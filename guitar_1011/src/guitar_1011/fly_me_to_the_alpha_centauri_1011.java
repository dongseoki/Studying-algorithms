package guitar_1011;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class fly_me_to_the_alpha_centauri_1011 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st ;
		Scanner sc = new Scanner(System.in);
		
		try {
			int n = Integer.parseInt(br.readLine());
			int start;
			int end;
			int distance;
			int y;
			int z;
			int cost;
			int largecost;
			double x;
			for(int count =0;count<n;count++) {
				st= new StringTokenizer(br.readLine());
				start =Integer.parseInt(st.nextToken());
				end =Integer.parseInt(st.nextToken());
				//System.out.println("count:"+ count);
				//int start =sc.nextInt();
				//int end =sc.nextInt();
				//System.out.println("hi");
				distance = end - start;
				if(distance <=3) {
					System.out.println(distance);
					continue;
				}
					
				
				x =Math.sqrt(distance);
				y=(int)x;
				z= y*y;
				cost = 2 * y -1;
				distance = distance - z;
				//System.out.println("hi2");
				//System.out.println("cost:"+cost);
				if(distance != 0) {
					largecost = y;
					cost += distance/largecost ;
					if(distance %largecost !=0)
						cost++; // 
					//System.out.println("cost2:"+cost);
				}
				
				System.out.println(cost);
			}
			
		}catch(Exception e) {
			System.out.println("problem");
			e.printStackTrace();
		}
		
	}

}
