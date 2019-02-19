//package examples190206;
//import java.util.*;
//
//class Exercise11_12 {
//	public static void main(String args[]) throws Exception {
//		SutdaDeck deck = new SutdaDeck();
//
//		deck.shuffle();
//		Player p1 = new Player("Ÿ¥", deck.pick(), deck.pick());
//		Player p2 = new Player("���", deck.pick(), deck.pick());
//
//		System.out.println(p1+" "+deck.getPoint(p1));
//		System.out.println(p2+" "+deck.getPoint(p2));
//	}
//}
//
//class SutdaDeck {
//	final int CARD_NUM = 20;
//	SutdaCard[] cards = new SutdaCard[CARD_NUM];
//
//	int pos = 0; // ������ ������ ī���� ��ġ
//	HashMap jokbo = new HashMap(); // ������ ������ HashMap
//
//	SutdaDeck() {
//		for(int i=0;i < cards.length;i++) {
//			int num = i%10+1;
//			boolean isKwang = i < 10 && (num==1 || num==3 || num==8);
//
//			cards[i] = new SutdaCard(num,isKwang);
//		}
//
//		registerJokbo();  // ������ ����Ѵ�.
//	}
//
//	void registerJokbo() {
//		jokbo.put("K"+"K", 4000);
//		for(int i=10;i>=1;i--) {
//			jokbo.put((i+"")+i, new Integer(3000+10*i));
//		}
//		int[] intarr1 = new int[] {1,2,1,4,1,9,1,10,4,10,4,6};
//		int[] intarr2 = new int[] {2,1,4,1,9,1,10,1,10,4,6,4};
//		for(int i=11;i>=0;i--) {
//			jokbo.put((intarr1[i]+"")+intarr2[i], new Integer(2010+ i/2 * 10));
//		}
//		/*
//			(1) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
//			1. jokbo(HashMap)�� ������ �����Ѵ�.
//			   �� ī���� ���� ���ڿ��� �ٿ��� key��, ������ value�� �����Ѵ�.
//		*/
//		
//	}
//
//	int getPoint(Player p) {
//		if(p==null) return 0;
//
//		SutdaCard c1 = p.c1;
//		SutdaCard c2 = p.c2;
//
//		Integer result = 0;
//		
//		if(c1.isKwang == true && c2.isKwang ==true) {
//			
//				p.point = (Integer)jokbo.get("KK");
//		}
//		else {
//			
//			if(jokbo.containsKey((c1.num+"")+c2.num)){
//				p.point =(Integer)jokbo.get((c1.num+"")+c2.num);
//			}
//			else
//				p.point = (c1.num + c2.num) % 10 + 1000;
//		}
//		result = p.point;
//			
//		
//		/*
//			(1) �˸��� �ڵ带 �־� �ϼ��Ͻÿ�.
// 			1. ī�� �� ���� ��� ���̸�, jokbo���� key�� "KK"�� �ؼ� ������ ��ȸ�Ѵ�.
//			2. �� ī���� ����(num)�� jokbo���� ����� ��ȸ�Ѵ�.
//			3. �ش��ϴ� ����� ������, �Ʒ��� �������� ������ ����Ѵ�.
//				(c1.num + c2.num) % 10 + 1000
//			4. Player�� ����(point)�� ����� ���� �����Ѵ�.
//		*/
//
//		return result.intValue();
//	}
//
//	SutdaCard pick() throws Exception {
//		SutdaCard c = null;
//
//		if(0 <= pos && pos < CARD_NUM) {
//			c = cards[pos];
//			cards[pos++] = null;
//		} else {
//			throw new Exception("�����ִ� ī�尡 �����ϴ�.");
//		}
//
//		return c;
//	}
//
//	void shuffle() {
//		for(int x=0; x < CARD_NUM * 2; x++) {
//			int i = (int)(Math.random() * CARD_NUM);
//			int j = (int)(Math.random() * CARD_NUM);
//
//			SutdaCard tmp = cards[i];
//			cards[i] = cards[j];
//			cards[j] = tmp;
//		}
//	}
//} // SutdaDeck
//
//class Player {
//	String name;
//	SutdaCard c1;
//	SutdaCard c2;
//
//	int point; // ī���� ��޿� ���� ���� - ���� �߰�
//
//	Player(String name, SutdaCard c1, SutdaCard c2) {
//		this.name = name ;
//		this.c1 = c1 ;
//		this.c2 = c2 ;
//	}
//
//	public String toString() {
//		return "["+name+"]"+ c1.toString() +","+ c2.toString();
//	}
//} // class Player
//
//class SutdaCard {
//	int num;
//	boolean isKwang;
//
//	SutdaCard() {
//		this(1, true);
//	}
//
//	SutdaCard(int num, boolean isKwang) {
//		this.num = num;
//		this.isKwang = isKwang;
//	}
//
//	public String toString() {
//		return num + ( isKwang ? "K":"");
//	}
//
//}
//
