#include <iostream>
#include <vector>
using namespace std;
#define START -1
#define END -2
#define PASS_POINT 0
#define F(p,r,q) for(int p=q; p<r; p++)


int dr[] = { 0,-1,-1,-1,0,1,1,1 };
int dc[] = { 1,1,0,-1,-1,-1,0,1 };
class horse {
public :
	int row;
	int column;
	int direction;
	//
	//    321
	//    4*0
	//    567
	bool move_state;
	// move_state = false 면 시작이고,
	//true면 출발한 상태 라는 뜻.
	horse() {
		row = 1;
		column = 2;
		direction = 6;
		move_state = false;
	}

};

int solution(vector<int> dice_numbers) {
	vector<vector<int>> d_map = 
{ {	-3	,	-3	,	-3	,	-3	,	-3	,	-2	,	-3	,	-3	,	-3	,	-3	,	-3	},
{	-1	,	-3	,	-3	,	-3	,	-3	,	40	,	-3	,	-3	,	-3	,	-3	,	-3	},
{	2	,	-3	,	-3	,	-3	,	-3	,	0	,	38	,	-3	,	-3	,	-3	,	-3	},
{	4	,	-3	,	-3	,	-3	,	-3	,	0	,	-3	,	36	,	-3	,	-3	,	-3	},
{	6	,	-3	,	-3	,	-3	,	-3	,	35	,	-3	,	-3	,	34	,	-3	,	-3	},
{	8	,	-3	,	-3	,	-3	,	-3	,	30	,	-3	,	-3	,	-3	,	32	,	-3	},
{	10	,	0	,	13	,	16	,	19	,	25	,	26	,	27	,	28	,	0	,	30	},
{	-3	,	12	,	-3	,	-3	,	-3	,	24	,	-3	,	-3	,	-3	,	28	,	-3	},
{	-3	,	-3	,	14	,	-3	,	-3	,	22	,	-3	,	-3	,	26	,	-3	,	-3	},
{	-3	,	-3	,	-3	,	16	,	-3	,	0	,	-3	,	24	,	-3	,	-3	,	-3	},
{	-3	,	-3	,	-3	,	-3	,	18	,	0	,	22	,	-3	,	-3	,	-3	,	-3	},
{	-3	,	-3	,	-3	,	-3	,	-3	,	20	,	-3	,	-3	,	-3	,	-3	,	-3	} };
	
	vector<horse> horses(4,horse());
	for (int bit = 0; bit < (1 << 20); bit++) {
		F(turn, 10, 0) {
			int number = (bit >> (turn * 2)) & 0x3;
			int move_value = dice_numbers[turn];
			horse& myhorse = horses[number];
			int cnt = 0;
			//  이동 준비.


			// 이동 시작.
			while (true) {
				int map_value = d_map[myhorse.row][myhorse.column];
				if (d_map[myhorse.row][myhorse.column] == PASS_POINT) {
					myhorse.row += dr[myhorse.direction];
					myhorse.column += dc[myhorse.direction];
					continue;
				}
				// 예외 케이스 0 이면 가던길 한번 더.
				if (cnt >= move_value)
					break;
				// 모든 이동 횟수를 가면.
				if (map_value == 10) {

				}


				myhorse.row += dr[myhorse.direction];
				myhorse.column += dc[myhorse.direction];
				// 이동.


				myhorse.move_state = true;
				cnt++;
				//
			}
		}
	}
	




}

int main(void) {
	vector<int> dice_numbers;
	F(i, 10, 0) {
		int num;
		cin >> num;
		dice_numbers.push_back(num);
	}

	cout << solution(dice_numbers);


}