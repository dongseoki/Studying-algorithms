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

template<typename T>
class BinaryNode
{
private:
	T data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(T val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r)
	{ }
	T getData() { return data; }
	void setData(T val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
};

template<typename T>
class BinaryTree
{
public:
	BinaryNode<T>* root;
	//BinaryTree(BinaryNode * root):root(root)
	//{ }
	void inorder(BinaryNode<T>* n) {
		if (n != NULL)
		{
			if (n->getLeft() != NULL)
				inorder(n->getLeft());
			cout << n->getData();
			if (n->getRight() != NULL)
				inorder(n->getRight());
		}
	}
	void preorder(BinaryNode<T> * n) {
		if (n != NULL)
		{
			cout << n->getData();
			if (n->getLeft() != NULL)
				preorder(n->getLeft());
			if (n->getRight() != NULL)
				preorder(n->getRight());
		}
	}
	void postorder(BinaryNode<T> * n) {
		if (n != NULL)
		{

			if (n->getLeft() != NULL)
				postorder(n->getLeft());
			if (n->getRight() != NULL)
				postorder(n->getRight());
			cout << n->getData();

		}
	}

};



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout �� cin ���̿� ���� ���� ���� ������ ���´�. ����ȭ�� �����Ѵ�.?
	int N;
	cin >> N;
	vector<BinaryNode<char>*> vec;

	for (int i = 0; i < N; i++)
		vec.push_back(new BinaryNode<char>());

	for (int i = 0; i < N; i++) {
		char nodeName;
		char leftNode;
		char rightNode;
		cin >> nodeName;
		cin >> leftNode;
		cin >> rightNode;
		//vec.push_back(new BinaryNode());
		int index = nodeName - 'A';
		vec[index]->setData(nodeName);
		if (leftNode == '.')
			vec[index]->setLeft(NULL);
		else
			vec[index]->setLeft(vec[leftNode - 'A']);

		if (rightNode == '.')
			vec[index]->setRight(NULL);
		else
			vec[index]->setRight(vec[rightNode - 'A']);

	}

	BinaryTree<char> * bt = new BinaryTree<char>();

	bt->preorder(vec[0]);
	cout << "\n";
	bt->inorder(vec[0]);
	cout << "\n";
	bt->postorder(vec[0]);

	return 0;



}