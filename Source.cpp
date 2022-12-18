#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>


class node
{
public:
	node* left;
	node* right;
	int data;
	int height;
	node(int d, int height = 0, node* left = NULL, node* right = NULL) : data(d), height(height), left(left), right(right)
	{}
	node() : data(0), height(0), left(NULL), right(NULL)
	{}
};

class huffNode
{
public:
	huffNode* left = NULL;
	huffNode* right = NULL;
	int frequency = 0;
	char data = ' ';
	string code = "";
	huffNode(int f, huffNode* l, huffNode* r) {}
};


#include "BST.h"
#include "Graph.h"





int main(void)
{
	gnode A;
	gnode B;
	gnode C;
	gnode D;



	A.neighbours.push_back(&B);
	A.neighbours.push_back(&D);


	B.neighbours.push_back(&C);


	C.neighbours.push_back(&A);
	C.neighbours.push_back(&D);

	D.neighbours.push_back(&B);
	D.neighbours.push_back(&C);


	Graph g;

	g.BFS(&A, &B);


	if (A.visited) cout << "A" << endl;
	if (B.visited) cout << "B" << endl;
	if (C.visited) cout << "C" << endl;
	if (D.visited) cout << "D" << endl;



	
	
	return 0;
}