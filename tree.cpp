#include <stdlib.h>
#include <iostream>
using namespace std;

class Node
{
public:
	Node();
	~Node();
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};

class Tree
{
public:
	Tree();
	~Tree();
	Node *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex,int direction,Node *pNode);
	bool DeleteNode(int nodeIndex,Node *pNode);
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
private:
	Node *m_pRoot;
	
};

Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Tree::Tree()
{
	m_pRoot = new Node();
}

int main(int argc, char const *argv[])
{
	
	return 0;
}