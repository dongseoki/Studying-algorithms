#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//7
//A B C
//B D .
//C E F
//E . .
//F.G
//D . .
//G . .
//

//����
//����
//����
//ABDCEFG 
//DBAECFG
//DBEGFCA

int count2 = 0;


class BinaryNode
{
public:
	int data;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{ }

	int getData() { return data; }
	void setData(int val) { data = val; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
};

class BinaryTree
{
public:
	BinaryNode* root;
	BinaryTree(BinaryNode* root) :root(root)
	{ }
	void inorder(BinaryNode* n) {
		if (n != NULL)
		{
			if (n->getLeft() != NULL)
				inorder(n->getLeft());
			cout << n->getData();
			if (n->getRight() != NULL)
				inorder(n->getRight());
		}
	}
	void preorder(BinaryNode * n) {
		if (n != NULL)
		{
			cout << n->getData();
			if (n->getLeft() != NULL)
				preorder(n->getLeft());
			if (n->getRight() != NULL)
				preorder(n->getRight());
		}
	}
	void postorder(BinaryNode * n) {
		if (n != NULL)
		{

			if (n->getLeft() != NULL)
				postorder(n->getLeft());
			if (n->getRight() != NULL)
				postorder(n->getRight());
			cout << n->getData()<<"\n";

		}
	}
	void insert(int num, BinaryNode * root) {
		count2++;
		if (num < root->data)
			if (root->getLeft() == NULL) {
				BinaryNode* newNode = new BinaryNode(num);
				root->left = newNode;
			}
			else
				insert(num, root->getLeft());
		else
			if (root->getRight() == NULL) {
				BinaryNode* newNode = new BinaryNode(num);
				root->right = newNode;
			}
			else
				insert(num, root->getRight());


	}

};



int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?

	
	
	
	int N;
	if (scanf_s("%d", &N) == EOF)
		return 0;
	BinaryNode * node = new BinaryNode(N);
	BinaryTree* bt = new BinaryTree(node);
	while (true) {
		int N;
//		cin >> N;
		if (scanf_s("%d", &N) == EOF)
			break;
		bt->insert(N, node);
	}
	bt->postorder(node);
	



	return 0;



}