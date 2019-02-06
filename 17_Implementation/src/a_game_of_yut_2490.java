import java.util.ArrayList;
import java.util.Scanner;

public class a_game_of_yut_2490 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> alist = new ArrayList<Integer>();
		Scanner sc = new Scanner(System.in);
		String[] strarr = new String[] { "E", "A", "B", "C", "D" };
		int yut;
		int state;
		for (int i = 0; i < 3; i++) {
			alist.clear();
			state = 0;
			for (int j = 0; j < 4; j++) {
				// alist.add(sc.nextInt());
				yut = sc.nextInt();
				if (yut == 0) {
					state++;
				}
			}
//			 switch(state){
//				 case 0:
//					 System.out.println("D");
//					 break;
//				 case 1:
//					 System.out.println("D");
//					 break;
//				 case 2:
//					 System.out.println("D");
//					 break;
//				 case 3:
//					 System.out.println("D");
//					 break;
//				 case 4:
//					 System.out.println("D");
//					 break;
			System.out.println(strarr[state]);
		}

	}

}

