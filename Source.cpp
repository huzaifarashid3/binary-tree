#include <iostream>
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

#include "AVL.h"
#include "BST.h"
#include "BH.h"
#include "Huffman.h"
#include "Hashing.h"
//#include "Queue.h"




int main(void)
{
	int arr[] = { 50, 700, 76, 85, 92, 73, 101 };
	int size = sizeof(arr) / sizeof(int);
	HashTable table(size);

	for (int i = 0; i < size; i++)
	{
		table.Insert(arr[i]);
	}
	table.Insert(1);

	table.print();

	
	
	return 0;
}