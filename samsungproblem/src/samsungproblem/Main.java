package samsungproblem;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int n;
	static int[][] arr;
	static boolean[][] visit;
	static int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

	static class Info {
		// 좌표r, c, 상어크기, 먹은 갯수, 먹이까지의길이
		int r, c, sSize, eat, len;

		Info(int r, int c, int sSize, int eat, int len) {
			this.r = r;
			this.c = c;
			this.sSize = sSize;
			this.eat = eat;
			this.len = len;
		}
	}

	static boolean isRange(int r, int c) {
		if (r < 0 || r >= n || c < 0 || c >= n) {
			return false;
		}
		return true;
	}

	static void solve(int r, int c) {
		Queue<Info> que = new LinkedList<>();
		que.add(new Info(r, c, 2, 0, 0));
		visit[r][c] = true;
		int result = 0; // 최종 시간 저장용

		while (!que.isEmpty()) {
			// 제일 위쪽, 제일 왼쪽 찾기 위한 변수
			int top = 999999, left = 999999;
			// 먹은거 0,
			int eat = 0, sSize = 0, len = 0;
			int size = que.size();
			// 현재 저장되어 있는 큐만큼
			for (int j = 0; j < size; j++) {
				Info flag = que.poll();
				for (int i = 0; i < 4; i++) {
					int nextR = flag.r + dir[i][0];
					int nextC = flag.c + dir[i][1];
					if (isRange(nextR, nextC) && !visit[nextR][nextC]) {
						visit[nextR][nextC] = true;
						que.add(new Info(nextR, nextC, flag.sSize, flag.eat, flag.len + 1));

						// 물고기가 지금 사이즈 보다 작다면
						if (arr[nextR][nextC] != 0 && arr[nextR][nextC] < flag.sSize) {
							// 위 우선 그다음 왼쪽 우선
							if (nextR < top) {
								left = nextC;
								top = nextR;
								eat = flag.eat;
								sSize = flag.sSize;
								len = flag.len + 1;
							} else if (nextR == top) {
								if (nextC < left) {
									left = nextC;
									top = nextR;
									eat = flag.eat;
									sSize = flag.sSize;
									len = flag.len + 1;
								}
							}
						}
					}

				}
			}

			// 위치이동이 일어 났다면 먹을게 있따는거 큐 등등 초기화
			if (top != 999999) {
				eat++;
				if (eat == sSize) {
					sSize++;
					eat = 0;
				}
				arr[r][c] = 0;
				arr[top][left] = 9;
				result += len;
				r = top;
				c = left;
				
				System.out.println("r/c/result ="+r+" "+c+" "+result);
				visit = new boolean[n][n];
				que.clear();
				visit[top][left] = true;
				que.add(new Info(top, left, sSize, eat, 0));
			}
		}
		System.out.println(result);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n][n];
		int r = 0;
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = sc.nextInt();
				if (arr[i][j] == 9) {
					r = i;
					c = j;
				}
			}
		}
		visit = new boolean[n][n];
		solve(r, c);
	}
}