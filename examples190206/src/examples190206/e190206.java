package examples190206;

import java.util.*;

public class e190206 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		ArrayList list = new ArrayList();
//		list.add("1");
//		list.add("2");
//		list.add("3");
//		list.add("4");
//		list.add("5");
//
//		Iterator it = list.iterator();
//
//		while(it.hasNext()) {
//			Object obj = it.next();
//			System.out.println(obj);
//		}
		
//		
//		ArrayList list = new ArrayList();
//		list.add("1");
//		list.add("2");
//		list.add("3");
//		list.add("4");
//		list.add("5");
//
//		ListIterator it = list.listIterator();
//
//		while(it.hasNext()) {
//			System.out.print(it.next());
//		}
//
//		System.out.println();
//
//		while(it.hasPrevious()) {
//			System.out.print(it.previous());
//		}
		
//		Set set = new HashSet();
//		
//		for (int i = 0; set.size() < 6 ; i++) {
//
//			int num = (int)(Math.random()*45) + 1;
//			set.add(new Integer(num));
//		}
//
//		List list = new LinkedList(set);	// LinkedList(Collection c)
//		Collections.sort(list);		// Collections.sort(List list)
//		System.out.println(list);
//		
		
		TreeSet set = new TreeSet();

		String from = "b";
		String to	= "d";

		set.add("abc");
		set.add("alien");
		set.add("bat");
		set.add("car");
		set.add("Car");
		set.add("disc");
		set.add("dance");
		set.add("dZZZZ");
		set.add("dzzzz");
		set.add("elephant");
		set.add("elevator");
		set.add("fan");
		set.add("flower");

		System.out.println(set);
		System.out.println("range search : from " + from  +" to "+ to);
		System.out.println("result1 : " + set.subSet(from, to));
		System.out.println("result2 : " + set.subSet(from, to + "zzz"));
		
		HashMap map = new HashMap();
		map.put("castello", "1234");
		map.put("asdf", "1111");
		map.put("asdf", "1234");

		Scanner s = new Scanner(System.in);	// ȭ�����κ��� ���δ����� �Է¹޴´�.

		while(true) {
			System.out.println("id�� password�� �Է����ּ���.");
			System.out.print("id :");
			String id = s.nextLine().trim();

			System.out.print("password :");
			String password = s.nextLine().trim();
			System.out.println();

			if(!map.containsKey(id)) {
				System.out.println("�Է��Ͻ� id�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���.");
				continue;
			} else {
				if(!(map.get(id)).equals(password)) {
				 System.out.println("��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.");
				} else {
					System.out.println("id�� ��й�ȣ�� ��ġ�մϴ�.");						
					break;
				}
			}
		} // while
	}

}
