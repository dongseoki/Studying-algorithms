import java.util.*;
import java.util.regex.*;

class Exercise11_18 {
	public static void main(String[] args) {
		String[] phoneNumArr = {
			"012-3456-7890",
			"099-2456-7980",
			"088-2346-9870",
			"013-3456-7890"
		};

		ArrayList list = new ArrayList();
		Scanner s = new Scanner(System.in); 

		while(true) { 
			System.out.print(">>"); 
			String input = s.nextLine().trim(); 

			if(input.equals("")) {
				continue;
			} else if(input.equalsIgnoreCase("Q")) {
				System.exit(0);
			}
			
			/*
			   (1) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
			*/

			if(list.size()>0) {
				System.out.println(list);
				list.clear();
			} else {
				System.out.println("��ġ�ϴ� ��ȣ�� �����ϴ�.");
			}
		} // while
	} // main
}
