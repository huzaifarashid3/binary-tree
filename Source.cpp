#include <iostream>
#include <queue>
using namespace std;
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
#include "AVL.h"
#include "BST.h"
#include "BH.h"
#include "BinaryTree.h":

int main(void)
{

	int arr[10] = { 10,6,3,2,1,4,11,12,14,13};

	BinaryHeap bh(10);

	for (int i = 0; i < 4; i++)
		bh.Insert(arr[i]);

	/*cout << bh.Extract() << endl;
	cout << bh.Extract() << endl;
	cout << bh.Extract() << endl;*/

	return 0;
}