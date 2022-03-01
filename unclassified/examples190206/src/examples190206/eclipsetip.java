package examples190206;

public class eclipsetip {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println();
		while (true) {
			System.out.println("se");
			break;
		}
		Person a = new Person();
		//a.num = 10;
		a.setNum(109);
		//https://blog.naver.com/broodwartm/221033292646
		//1. ctr shift f format
		// 2. alt shift s  -> getter and setter
		
	}

}
class Person{
	private int num;
	int age;
	String ar;
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getAr() {
		return ar;
	}
	public void setAr(String ar) {
		this.ar = ar;
	}
	
}
