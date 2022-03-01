// acm_study_homework_3_division_conquer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
//오른쪽 피연산자로 'std::string' 형식을 사용하는 연산자가 없거나 허용되는 변환이 없습니다.
// 위 오류 해결방법 #incldue <string>
using namespace std;

void quadtree(int r, int c, int length);

char img[65][65];

int main()
{
	ios::sync_with_stdio(false); //  printf 와 scanf 를 못사용하게 하면서 속도 향상을 시킴. 동기화를 해제한다.?
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?
	int N;
	cin >> N;
	//img.resize(N);
	//vector<string> img;

	
	//img.push_back(NULL);
	for (int i = 0; i < N; i++) {
		cin >>img[i];
	}
	quadtree( 0, 0,N);



	return 0;
  
}

void quadtree(int r, int c, int length) {
	if (length <= 0)
		return;
	if (length == 1) {
		cout << img[r][c]; // img[r][c] 실패. 첨자는 배열 또는 포인터 형식을 사용해야 합니다.
		return;
	}

	string str;
	int state = 0;
	state = img[r][c]-48.;// atoi는 어디에 있는가?
	//cout << "state:" << state << endl;
	for (int i = r; i < r+length; i++) {
		for (int j = c; j < c+length; j++) {
			if (state != img[i][j] - 48) {
				cout << "(";
				quadtree(r, c, length / 2);
				quadtree(r, c+length / 2, length / 2);
				quadtree(r+ length / 2, c, length / 2);
				quadtree(r+ length / 2, c + length / 2, length / 2);
				cout << ")";
				return;
			}
		}
	}

	if (state == 0)
		cout << "0";
	if (state == 1)
		cout << "1";

	return;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
