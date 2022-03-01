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
	int    classRank;	// 반등수

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
			 +","+classRank	// 새로추가
			 ;
	}
} // class Student

class ClassTotalComparator implements Comparator { 
	public int compare(Object o1, Object o2) { 
		/*
			(1) 알맞은 코드를 넣어 완성하시오.
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
		// 먼저 반별 총점기준 내림차순으로 정렬한다.
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
		   (2) 알맞은 코드를 넣어 완성하시오.
	                1. 반복문을 이용해서 list에 저장된 Student객체를 하나씩 읽는다.
          	          1.1 반이 달라지면,(classNo와 prevClassNo가 다르면)
                    	    이전등수(prevRank)와 이전총점(prevTotal)을 초기화 한다. 
	                  1.2 총점(total)이 이전총점(prevTotal)과 같으면
	                         이전 등수(prevRank)를 등수(schoolRank)로 한다.
	                  1.3 총점이 서로 다르면,
	                      등수(schoolRank)의 값을 알맞게 계산해서 저장한다.
	                      이전에 동점자였다면, 그 다음 등수는 동점자의 수를 고려해야한다.
	                      (실행결과 참고)
          	          1.4 현재 반과 총점과 등수를 이전반(prevClassNo)와 이전총점(prevTotal)과
	                        이전등수(prevRank)에 저장한다.
		*/

	} // public static void calculateClassRank(List list) { 

	public static void calculateSchoolRank(List list) { 
		Collections.sort(list); // 먼저 list를 총점기준 내림차순으로 정렬한다.

		int prevRank = -1;       // 이전 전교등수
		int prevTotal = -1;       // 이전 총점
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
		    (2) 알맞은 코드를 넣어 완성하시오.
	               1. 반복문을 이용해서 list에 저장된 Student객체를 하나씩 읽는다.
          	          1.1 총점(total)이 이전총점(prevTotal)과 같으면
                              이전 등수(prevRank)를 등수(schoolRank)로 한다.
	                  1.2 총점이 서로 다르면,
                              등수(schoolRank)의 값을 알맞게 계산해서 저장한다.
                              이전에 동점자 였다면, 그 다음 등수는 동점자의 수를 고려해야한다.
       		              (실행결과 참고)
                          1.3 현재 총점과 등수를 이전총점(prevTotal)과 이전등수(prevRank)에 저장한다.
		*/
	}

	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add(new Student("이자바",2,1,70,90,70));
		list.add(new Student("안자바",2,2,60,100,80));
		list.add(new Student("홍길동",1,3,100,100,100));
		list.add(new Student("남궁성",1,1,90,70,80));
		list.add(new Student("김자바",1,2,80,80,90));

		calculateSchoolRank(list);
		calculateClassRank(list);

		Iterator it = list.iterator();

		while(it.hasNext())
			System.out.println(it.next());
	}
}

