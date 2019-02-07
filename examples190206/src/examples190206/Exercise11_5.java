//package examples190206;
//import java.util.*;
//
//class Student implements Comparable {
//	String name;
//	int    ban;
//	int    no;
//	int    kor;
//	int    eng;
//	int    math;
//
//	Student(String name, int ban, int no, int kor, int eng, int math) {
//		this.name = name;
//		this.ban  = ban;
//		this.no   = no;
//		this.kor  = kor;
//		this.eng  = eng;
//		this.math = math;
//	}
//
//	int getTotal() {
//		return kor+eng+math;
//	}
//
//	float getAverage() {
//		return (int)((getTotal()/ 3f)*10+0.5)/10f;
//	}
//
//	public String toString() {
//		return name
//			 +","+ban
//			 +","+no
//			 +","+kor
//			 +","+eng
//			 +","+math
//			 +","+getTotal()
//			 +","+getAverage()
//			 ;
//	}
//
//	@Override
//	public int compareTo(Object arg0) {
//		// TODO Auto-generated method stub
//		Student temp = (Student)arg0;
//		return this.name.compareTo(temp.name);
////		if(this.name < temp.name)
////			return 1;
////		else
////			return -1;
//	}
//}
//
//class Exercise11_5 {
//	public static void main(String[] args) {
//		ArrayList list = new ArrayList();
//		list.add(new Student("È«±æµ¿",1,1,100,100,100));
//		list.add(new Student("³²±Ã¼º",1,2,90,70,80));
//		list.add(new Student("±èÀÚ¹Ù",1,3,80,80,90));
//		list.add(new Student("ÀÌÀÚ¹Ù",1,4,70,90,70));
//		list.add(new Student("¾ÈÀÚ¹Ù",1,5,60,100,80));
//
//		Collections.sort(list);
//
//		Iterator it = list.iterator();
//
//		while(it.hasNext())
//			System.out.println(it.next());
//	}
//}
