package examples190206;
import java.util.*;

class Student implements Comparable {
	String name;
	int    ban;
	int    no;
	int    kor;
	int    eng;
	int    math;

	int    total;		
	int    schoolRank;	
	int    classRank;	// �ݵ��

	Student(String name, int ban, int no, int kor, int eng, int math) {
		this.name = name;
		this.ban  = ban;
		this.no   = no;
		this.kor  = kor;
		this.eng  = eng;
		this.math = math;

		total = kor+eng+math;
	}

	int getTotal() {
		return total;
	}

	float getAverage() {
		return (int)((getTotal()/ 3f)*10+0.5)/10f;
	}

	public int compareTo(Object o) {
		if(o instanceof Student) {
			Student tmp = (Student)o;

			return tmp.total - this.total;
		} else {
			return -1;
		}
	}

	public String toString() {
		return name
			 +","+ban
			 +","+no
			 +","+kor
			 +","+eng
			 +","+math
			 +","+getTotal()
			 +","+getAverage()
			 +","+schoolRank	
			 +","+classRank	// �����߰�
			 ;
	}
} // class Student

class ClassTotalComparator implements Comparator { 
	public int compare(Object o1, Object o2) { 
		/*
			(1) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
		*/
		if(o1 instanceof Student &&o2 instanceof Student ) {
			Student s1 = (Student)o1;
			Student s2 = (Student)o2;
			if(s1.ban != s2.ban)
				return s1.ban - s2.ban;
			else
				return s2.total - s1.total;
		}
		return -1;
	} 
} 

class Exercise11_9 {
	public static void calculateClassRank(List list) { 
		// ���� �ݺ� �������� ������������ �����Ѵ�.
		Collections.sort(list, new ClassTotalComparator()); 

		int prevBan = -1; 
		int prevRank = -1; 
		int prevTotal = -1; 
		int length = list.size(); 
		
		Student s;
		int j =0;
		for(int i=0;i<length;i++) {
			s = (Student)list.get(i);
			if(s.ban != prevBan) {
				prevRank = -1;
				prevTotal =-1;
				j=0;
			}
			if(s.total ==prevTotal) {
				s.classRank = prevRank;
			}
			else {
				s.classRank = j+1;
			}
			prevBan = s.ban;
			prevTotal = s.total;
			prevRank = s.classRank;
			j++;
		}
		/*
		   (2) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
	                1. �ݺ����� �̿��ؼ� list�� ����� Student��ü�� �ϳ��� �д´�.
          	          1.1 ���� �޶�����,(classNo�� prevClassNo�� �ٸ���)
                    	    �������(prevRank)�� ��������(prevTotal)�� �ʱ�ȭ �Ѵ�. 
	                  1.2 ����(total)�� ��������(prevTotal)�� ������
	                         ���� ���(prevRank)�� ���(schoolRank)�� �Ѵ�.
	                  1.3 ������ ���� �ٸ���,
	                      ���(schoolRank)�� ���� �˸°� ����ؼ� �����Ѵ�.
	                      ������ �����ڿ��ٸ�, �� ���� ����� �������� ���� ����ؾ��Ѵ�.
	                      (������ ����)
          	          1.4 ���� �ݰ� ������ ����� ������(prevClassNo)�� ��������(prevTotal)��
	                        �������(prevRank)�� �����Ѵ�.
		*/

	} // public static void calculateClassRank(List list) { 

	public static void calculateSchoolRank(List list) { 
		Collections.sort(list); // ���� list�� �������� ������������ �����Ѵ�.

		int prevRank = -1;       // ���� �������
		int prevTotal = -1;       // ���� ����
		int length = list.size(); 
		
		Student tm;
		for(int i=0;i<length;i++) {
			System.out.println("hi");
			tm = (Student)list.get(i);
			System.out.println("tm.total/prevTotal:" + tm.total + " " + prevTotal);
			if(tm.total == prevTotal) { 
				tm.schoolRank = prevRank;
			}
			else
				tm.schoolRank = i+1;
			prevTotal = tm.total;
			prevRank = tm.schoolRank;
			System.out.println("tmSR/tmtotal/PrevTotal/prevRank"+ tm.schoolRank+"/"+ tm.total + "/"+prevTotal + "/"+prevRank);
		}
		/*
		    (2) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
	               1. �ݺ����� �̿��ؼ� list�� ����� Student��ü�� �ϳ��� �д´�.
          	          1.1 ����(total)�� ��������(prevTotal)�� ������
                              ���� ���(prevRank)�� ���(schoolRank)�� �Ѵ�.
	                  1.2 ������ ���� �ٸ���,
                              ���(schoolRank)�� ���� �˸°� ����ؼ� �����Ѵ�.
                              ������ ������ ���ٸ�, �� ���� ����� �������� ���� ����ؾ��Ѵ�.
       		              (������ ����)
                          1.3 ���� ������ ����� ��������(prevTotal)�� �������(prevRank)�� �����Ѵ�.
		*/
	}

	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add(new Student("���ڹ�",2,1,70,90,70));
		list.add(new Student("���ڹ�",2,2,60,100,80));
		list.add(new Student("ȫ�浿",1,3,100,100,100));
		list.add(new Student("���ü�",1,1,90,70,80));
		list.add(new Student("���ڹ�",1,2,80,80,90));

		calculateSchoolRank(list);
		calculateClassRank(list);

		Iterator it = list.iterator();

		while(it.hasNext())
			System.out.println(it.next());
	}
}

