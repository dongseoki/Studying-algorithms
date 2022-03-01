#include <iostream>
#include <vector>
#define F(p,q,r) for(int p = q; p<r; p++)

using namespace std;

enum Shape_type {
	NOT_AVAILABLE,
	TYPE_1_3 ,
	TYPE_1_4 ,
	TYPE_2_2 ,
	TYPE_2_3, 
	TYPE_3_1
};
class Block {
public:
	int type;
	int row;
	int column;
	Block() {
		type = NOT_AVAILABLE;
		row = -1;
		column = -1;
	}
};

void block_shape_make(vector<vector<vector<char>>>& block_shapes) {
	block_shapes.push_back({ {'O', 'X', 'X'}, { 'O','O','O' } });
	// index zero. dummy...

	block_shapes.push_back({ {'O', 'X', 'X'},
							{ 'O','O','O' } });

	block_shapes.push_back({ {'X', 'O'},
						{'X', 'O'},
						{'O', 'O'} });

	block_shapes.push_back({ {'O', 'X'},
							{'O', 'X'},
							{'O', 'O'} });

	block_shapes.push_back({ {'X', 'X', 'O'},
						{ 'O','O','O' } });

	block_shapes.push_back({ {'X', 'O', 'X'},
					{ 'O','O','O' } });
}
void check_register_block(int R, int C, int type_num,
	vector<Block>& block_list,
	vector<vector<vector<char>>>& block_shapes,
	vector<vector<int>>& board) {
	int value = -1;
	bool flag = true;
	F(x_dis, 0, block_shapes[type_num].size()) {
		F(y_dis, 0, block_shapes[type_num][0].size()) {
			if (block_shapes[type_num][x_dis][y_dis] == 'O') {
				if (value == -1) {
					value = board[R + x_dis][C + y_dis];
					
				}
				else {
					if (value != board[R + x_dis][C + y_dis])
						flag = false;
				}
			}
		}
	}

	if (flag == true && value != 0) {
		block_list[value].type = type_num;
		block_list[value].row = R;
		block_list[value].column = C;
	}

}
bool try_remove_block(int idx, vector<Block>& block_list,
	vector<vector<vector<char>>>& block_shapes,
	vector<vector<int>>& board) {


	int type_num = block_list[idx].type;
	int cnt = 0;
	F(x_dis, 0, block_shapes[type_num].size()) {
		F(y_dis, 0, block_shapes[type_num][0].size()) {
			if (block_shapes[type_num][x_dis][y_dis] == 'X') {
				int point_row = block_list[idx].row + x_dis;
				int point_column = block_list[idx].column + y_dis;
				F(b_idx, 0, (point_row+1)) {
					if (board[b_idx][point_column] != 0)
						return false;
				}
				// 여기까지 온것은 위에 전부 빈칸이였다. 라는 뜻.
				cnt++;
			}
		}
	}

	// 여기 까지 오면 위에 전부 빈칸 이였다 라고 볼수 있음.
	F(x_dis, 0, block_shapes[type_num].size()) {
		F(y_dis, 0, block_shapes[type_num][0].size()) {
			if (block_shapes[type_num][x_dis][y_dis] == 'O') {
				int point_row = block_list[idx].row + x_dis;
				int point_column = block_list[idx].column + y_dis;
				board[point_row][point_column] = 0;
			}
		}
	}
	//board에 해당하는 블록값들도 지워줘야 한다.

	block_list[idx].type = NOT_AVAILABLE;
	return true;

}

int solution(vector<vector<int>> board) {
	// 1. 블록을 블록 리스트에 등록한다.
	// 2.모든 블록 리스트를 순회하며 위에가 비어있는 것을 찾는다.
	// 2-1 위에가 비어 있다면 채우고, 해당 블록을 처리된거로 처리, 
	//2-2 모든 블록 리스트 순회시, 채운것이 하나도 없다면, 반복을 탈출하고
	// 지금까지 쓴 블록 의 수를 반환.


	int N = board.size();
	vector<Block> block_list(201, Block());
	// 블록 의 번호는 0이상 200 이하다.

	vector<vector<vector<char>>> block_shapes;
	block_shape_make(block_shapes);

	F(R, 0, N) {
		F(C, 0, N) {
			F(type_num, 1, 6) {
				if (type_num == TYPE_1_4 || type_num == TYPE_2_2) {
					if ((R + 2) <= (N - 1) && (C + 1) <= (N - 1)) {
						check_register_block(R,C,type_num, block_list, block_shapes, board);
					 }
				}
				else {
					if ((R + 1) <= (N - 1) && (C + 2) <= (N - 1)) {
						check_register_block(R, C, type_num, block_list, block_shapes, board);
					}
				}
			}
		}
	}
	int answer = 0;
	//1. 블록을 등록한다.

	while (true) {
		bool continue_flag = false;
		F(idx, 1, 201) {
			if (block_list[idx].type != 0) {
				if (try_remove_block(idx, block_list, block_shapes, board) == true) {
					continue_flag = true;
					answer++;
				}// 2-1 위에가 비어 있다면 채우고, 해당 블록을 처리된거로 처리, 
			}
		}
		if (continue_flag == false) {
			break;
		}//2-2 모든 블록 리스트 순회시, 채운것이 하나도 없다면, 반복을 탈출

	}
	
	//2.모든 블록 리스트를 순회하며 위에가 비어있는 것을 찾는다.




	return answer;
}
int main(void) {
	vector<vector<int>> board = { {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5} };

	cout <<solution(board);
}
