#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define F(p,q,r) for(int p=q;p<r;p++)
using namespace std;


class Node {
public:
	int data;
	int x;
	int y;
	Node* lnp; // left node pointer
	Node* rnp; // right node pointer
	Node(int data, int x, int y) {
		this->data = data;
		this->x = x;
		this->y = y;
		lnp = NULL;
		rnp = NULL;
	}
	void insertNode(Node& subNode) {
		if (subNode.x < this->x) {
			//임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
			if (this->lnp == NULL) {
				this->lnp = &subNode;
			}
			else {
				this->lnp->insertNode(subNode);
			}
		}
		else {
			// 같은 경우는 없다. 
			// 그 반대의 큰 경우.
			if (this->rnp == NULL) {
				this->rnp = &subNode;
			}
			else {
				this->rnp->insertNode(subNode);
			}
		}
	}
	void makePreOrderVector(vector<int>& v) {
		//VLR
		v.push_back(this->data);
		if (this->lnp != NULL) {
			this->lnp->makePreOrderVector(v);
		}
		if (this->rnp != NULL) {
			this->rnp->makePreOrderVector(v);
		}
	}
	void makePostOrderVector(vector<int>& v) {
		//LRV
		
		if (this->lnp != NULL) {
			this->lnp->makePostOrderVector(v);
		}
		if (this->rnp != NULL) {
			this->rnp->makePostOrderVector(v);
		}
		v.push_back(this->data);
	}

};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<Node>> level_table(100001, vector<Node>());

	F(idx, 0, nodeinfo.size()) {
		level_table[nodeinfo[idx][1]].push_back(Node(idx+1, nodeinfo[idx][0], nodeinfo[idx][1]));
		//data, x, y.
	}

	bool firstflag = true;
	Node* root = NULL;
	// 정렬 할 필요 없을 듯.
	for (int level = 100001; level >= 0; level--) {
		//if (level == 10) {
		//	cout << "드디어 10..\n";
		//}
		if (!level_table[level].empty()) {
			for (auto& item : level_table[level]) {
				if (firstflag == true) {
					firstflag = false;
					root = &item;
				}
				else {
					root->insertNode(item);
				}
			}
		}
	}

	vector<vector<int>> answer(2, vector<int>());
	root->makePreOrderVector(answer[0]);
	root->makePostOrderVector(answer[1]);
	
;
	return answer;
}
int main(void) {
	vector<vector<int>> nodeinfo ={{5, 3}, { 11,5 }, { 13,3 }, { 3,5 }, { 6,1 }, { 1,3 }, { 8,6 }, { 7,2 }, { 2,2 }
};

	vector<vector<int>> answer = solution(nodeinfo);
	cout << "answer..\n";
	F(idx, 0, answer[0].size()) {
		cout << answer[0][idx]<<" ";
	}
	cout << "\n";
	F(idx, 0, answer[1].size()) {
		cout << answer[1][idx] << " ";
	}
	cout << "\n";

}