package baekjoon.P10003;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {

		// 1) 값을 입력받아 배열에 저장.
		// 2) 배열에서 순회.
		// 덱을 이용함.
		// 순회에서 한개의 아이템에 대해서
		// deq에 최솟값 후보군 최신화.
		// deq 슬라이딩 범위 체크.
		// deq에서 최소값얻기.
		// 그것을 출력하기.
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new java.io.OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		int N = Integer.parseInt(st.nextToken());
		int winSize = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(bf.readLine());
		int[] arr = new int[N];
		int[] result = new int[N];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		// 2) 배열에서 순회.
		// 덱을 이용함.
		// 순회에서 한개의 아이템에 대해서
		// deq에 최솟값 후보군 최신화.
		// deq 슬라이딩 범위 체크.
		// deq에서 최소값얻기.
		// 그것을 출력하기.
		Deque<int[]> deq = new ArrayDeque<>();
		for (int i = 0; i < arr.length; i++) {
			// deq에 최솟값 후보군 최신화.
			int input = arr[i];
			// 예외. 값이 하나도 없을 경우.
			if (deq.size() == 0) {
				deq.add(new int[] {i, input});
				// System.out.print("" + input + " ");
				result[i] = input;
				continue;
			}
			while (!deq.isEmpty()) {
				int[] lastItem = deq.getLast();
				if (lastItem[1] >= input) {
					deq.removeLast();
					continue;
				} else {
					deq.addLast(new int[] {i, input});
					break;
				}
			}
			// 예외 처리. 덱이 다 비어서 끝난경우. 이 값을 일단 넣어준다.
			if (deq.isEmpty()) {
				deq.add(new int[] {i, input});
			}

			// deq 슬라이딩 범위 체크.
			long windowStartIdx = i - (winSize - 1);
			while (!deq.isEmpty()) {
				int[] firstItem = deq.getFirst();
				if (firstItem[0] < windowStartIdx) {
					deq.removeFirst();
					continue;
				} else {
					break;
				}
			}
			// deq에서 최소값얻기.
			int[] minItem = deq.getFirst();
			// 그것을 출력하기.
			// System.out.print("" + minItem[1] + " ");
			result[i] = minItem[1];
		}

		for (int i = 0; i < result.length; i++) {
			// System.out.print(result[i] + " ");
			bw.write(result[i] + " ");
		}
		bw.flush();
		bw.close();
	}
}