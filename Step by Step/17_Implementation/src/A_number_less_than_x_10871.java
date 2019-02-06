import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A_number_less_than_x_10871 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		try {
			StringTokenizer st;
			st = new StringTokenizer(br.readLine());
			
			int N =Integer.parseInt(st.nextToken());
			int X = Integer.parseInt(st.nextToken());
			
			
			st = new StringTokenizer(br.readLine());
			int temp;
			for(int i=0;i<N;i++) {
				temp = Integer.parseInt(st.nextToken());
				if(temp<X)
					System.out.print(temp+" ");
			}
			
		}catch(Exception e) {
			
		}

	}

}
