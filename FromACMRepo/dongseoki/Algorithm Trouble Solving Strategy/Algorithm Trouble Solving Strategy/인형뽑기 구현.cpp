#include <string>
#include <vector>
#include <iostream>

using namespace std;

int move_crain_catch_item_push_item(vector<vector<int>>& board, int crain_pos, vector<int>& baguni) {
	for (int i = 0; i < board.size(); i++) {
		int item = board[i][crain_pos - 1];
		if (item > 0) {

			board[i][crain_pos - 1] = 0;
			// 그 자리 비우기
			baguni.push_back(item);
			// 그 값을 바구니에 담기.
			if (baguni.size() >= 2 && baguni[baguni.size() - 1] == baguni[baguni.size() - 2]) {
				baguni.pop_back();
				baguni.pop_back();
				return 2;
			}
			break;
		}
	}
	return 0;
}
void print_state(vector<vector<int>>& board, vector<int>& baguni, vector<int> &moves) {
	cout << "\n-----board------\n";
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		
		}
		cout << "\n";
	}

	cout << "\n-----baguni------\n";
	for (int i = 0; i < baguni.size(); i++) {
		cout << baguni[baguni.size()-1 -i] << "\n";
	}

	cout << "\n-----moves------\n";
	for (int i = 0; i < moves.size(); i++) {
		cout << moves[i]<<" ";
	}
	cout << "\n----print_state_end..---\n";
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> baguni;
	int crain_pos; // crain position
	for (int i = 0; i < moves.size(); i++) {
		crain_pos = moves[i];
		answer += move_crain_catch_item_push_item(board, crain_pos, baguni);
		print_state(board, baguni,moves);
	}
	return answer;
}

int main(void) {
	int row, column;
	int moves_count;
	cin >> row;
	cin >> column;
	cin >> moves_count;
	vector<vector<int>> board(row, vector<int>(column, 0));
	vector<int> moves(moves_count, 0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < moves_count; i++) {
		cin >> moves[i];
	}
	cout << solution(board, moves);
}