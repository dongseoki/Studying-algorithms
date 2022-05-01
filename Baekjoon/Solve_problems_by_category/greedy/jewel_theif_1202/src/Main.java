import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	private static int N;
	private static int K;
	private static PriorityQueue<Integer> Q;
	static Jewel[] jewel;
	static Bag[] bag;
	static long answer;
	
	public static void main(String[] args) {
		long startTime = System.nanoTime(); // test
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		try {
			st = new StringTokenizer(in.readLine());
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		// TODO Auto-generated method stub
//		Scanner sc = new Scanner(System.in);
//		int N = sc.nextInt();
//		int K = sc.nextInt();

		jewel= new Jewel[N];
		bag = new Bag[K];
//		for (int i = 0; i < N; i++) {
//			jewel[i] =new Jewel(sc.nextInt(), sc.nextInt());
//		}
//		for (int i = 0; i < K; i++) {
//			bag[i] = new Bag(sc.nextInt());
//		}
		
		// insert jewerlry
				for (int i = 0 ; i < N ; i++) {
					try {
						st = new StringTokenizer(in.readLine());
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					int m = Integer.parseInt(st.nextToken());
					int v = Integer.parseInt(st.nextToken());
					jewel[i] = new Jewel(m, v);
				}
				// insert bag
				int c;
				for (int i = 0 ; i < K ; i++) {
					c=0;// initailize
					try {
						c = Integer.parseInt(in.readLine());
					} catch (NumberFormatException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					bag[i] = new Bag(c);;
				}

//		System.out.println("_-------------------------");
//		for (int i = 0; i < listJ.size(); i++) {
//			System.out.println(listJ.get(i));
//		}
//		System.out.println("_-------------------------");
//		for (int i = 0; i < listB.size(); i++) {
//			System.out.println(listB.get(i));
//		}
		
		Arrays.sort(jewel, 0, jewel.length, new Comparator<Jewel>() {
			@Override
			public int compare(Jewel arg0, Jewel arg1) {
				return arg0.weight - arg1.weight;
			}
		});
		
		Arrays.sort(bag, 0, bag.length, new Comparator<Bag>() {
			@Override
			public int compare(Bag arg0, Bag arg1) {
				return arg0.weightMax - arg1.weightMax;
			}
		});

//		Collections.sort(jewel);
//		Collections.sort(listB);
//		System.out.println("_-------------------------");
//		for (int i = 0; i < listJ.size(); i++) {
//			System.out.println(listJ.get(i));
//		}
//		System.out.println("_-------------------------");
//		for (int i = 0; i < listB.size(); i++) {
//			System.out.println(listB.get(i));
//		} // test

		//int valueOfJewel;
		// find answer
		Q = new PriorityQueue<Integer>();
				answer = 0;
				int jwidx = 0;
				for (int k = 0 ; k < K ; k++) {
					while(jwidx < N && jewel[jwidx].weight <= bag[k].weightMax) {
						Q.offer(0 - jewel[jwidx].value);
						jwidx++;
					}
//					System.out.println("Q : " + Q);
					if (!Q.isEmpty()) {
						int v = Q.poll();
						answer += (long)(0 - v);
					}
				}
				System.out.println(answer);
		
		//
		
//		int sum = 0;
//		int weight = 0;
//		for (int i = 0; i < N; i++) {
//			//System.out.println("value : " +listJ.get(0).weight);//test
//			weight = jewel[i].weight;
//			
//			sum += findGoodBag(weight, i);
//			//System.out.println(sum + "");//test
//		}
//		//System.out.println("_-------------------------");//test
//
//		System.out.println(sum);
		
		//code
				long endTime = System.nanoTime();
				//System.out.println("Took "+(endTime - startTime) + " ns"); 

	}

	public static int findGoodBag(int weight, int index) {
		int result = 0;
		if (bag.length ==0)
			return 0;
		try {
			for (int i = 0; i < bag.length; i++) {
				if (weight <= bag[i].weightMax) {
					bag[i].weightMax = -1;//selected bag
					result += jewel[index].value;
					
					return result;
				}
			}
			//listJ.remove(0);
		} catch (Exception e) {

		}

		return 0;
	}

}

class Jewel  {
	public int weight;
	public int value;

	public Jewel(int weight, int value) {
		this.weight = weight;
		this.value = value;
	}

	
}

class Bag  {
	public int weightMax;
	// public int value;

	public Bag(int weightMax) {
		this.weightMax = weightMax;
		// this.value = value;
	}
}
