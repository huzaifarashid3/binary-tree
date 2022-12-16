#include <iostream>
using namespace std;

class node
{
public:
	node* left;
	node* right;
	int data;
	int height;
	node(int d, int height=0, node* left = NULL, node* right = NULL): data(d), height(height), left(left), right(right)
	{}
	node(): data(0), height(0), left(NULL), right(NULL)
	{}
};

class BST
{
public:
	BST() {}
	void Insert(node** root, int data) 
	{
		node* newNode = new node(data);
		if (*root == NULL)
		{
			*root = newNode;
		}
		else if (data <= (*root)->data)
			Insert(&((*root)->left), data);
		else if (data > (*root)->data)
			Insert(&((*root)->right), data);


	}
	node* Search(node* root, int data)
	{
		if (root == NULL)
			return NULL;
		if (root->data == data)
			return root;
		else if (data < root->data)
			Search(root->left, data);
		else if (data > root->data)
			Search(root->right, data);
	}
	int Height(node* root)
	{
		if (root == NULL)
			return -1;
		return max(1 + Height(root->right), 1 + Height(root->left));
	}
	int HeightTill(node* root, int data)
	{
		if (data < root->data)
			return 1 + HeightTill(root->left, data);
		else if (data > root->data)
			return 1 + HeightTill(root->right, data);
		else
		{
			return 0;
		}
	}
	int Width(node* root)
	{
		return  HeightTill(root, FindMax(root)->data) + HeightTill(root, FindMin(root)->data);
	}
	void Inorder(node* root)
	{
		if (root == NULL) return;
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
	void Preorder(node* root)
	{
		if (root == NULL) return;
		cout << root->data << endl;
		Preorder(root->left);
		Preorder(root->right);
	}
	void Postorder(node* root)
	{	
		if (root == NULL) return;
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
	node* FindMin(node* root)
	{
		if (root == NULL)
			return NULL;
		while (root->left != NULL)
			root = root->left;
		return root;
	}
	node* FindMax(node* root)
	{
		if (root == NULL)
			return NULL;
		while (root->right != NULL)
			root = root->right;
		return root;

	}
	node* Delete(node* root, int data)
	{
		if (root == NULL) {
			return NULL;
		}
		if (data > root->data) {
			root->right = Delete(root->right, data);
		}
		else if (data < root->data) {
			root->left = Delete(root->left, data);
		}
		else {
			if (root->right == NULL && root->left == NULL) {
				delete root;
				root = NULL;
			}
			else if (root->left == NULL) {
				node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL) {
				node* temp = root;
				root = root->left;
				delete temp;
			}
			else {
				node* temp = FindMin(root->right);
				root->data = temp->data;
				root->right = Delete(root->right, temp->data);
			}
		}

		return root;

	}
	int Successor(node* root, int data)
	{
		return FindMin(Search(root, data)->right)->data;
	}
	int Predeccessor(node* root, int data)
	{
		return FindMax(Search(root, data)->left)->data;
	}
	int BFS_Search()
	{

	}
	int DFS_Search()
	{

	}
	void Display(node* root)
	{
		Preorder(root);
	}
	void DeleteBST(node** root)
	{
		//deletion is post-order
		if (*root == NULL) return;
		DeleteBST(&((*root)->left));
		DeleteBST(&((*root)->right));
		delete *root;
		*root = NULL;
	}
};

class AVL
{
public:
	node* Insert(node* root, int data)
	{
		node* newNode = new node(data);
		if (root == NULL)
			return newNode;
		else if (data < root->data)
			root->left = Insert(root->left, data);
		else if (data > root->data)
			root->right = Insert(root->right, data);


		root->height = Height(root);

		int balance = Height(root->left) - Height(root->right);

		//left left
		if (balance > 1 && data < root->left->data)
			root = RightRotate(root);

		//right right
		else if (balance < -1 && data > root->right->data)
			root = LeftRotate(root);

		//left right
		else if (balance > 1 && data > root->left->data)
		{
			root->left = LeftRotate(root->left);
			root = RightRotate(root);
		}

		//right left
		else if (balance < -1 && data < root->right->data)
		{
			root->right = RightRotate(root->right);
			root = LeftRotate(root);
		}
		return root;
	}
	node* Delete(node* root, int data)
	{
		if (root == NULL)
			return NULL;
		if (data > root->data)
			root->right = Delete(root->right, data);
		else if (data < root->data)
			root->left = Delete(root->left, data);
		else
		{
			if (root->right == NULL && root->left == NULL)
			{
				delete root;
				root = NULL;
			}

			else if (root->left == NULL)
			{
				node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				node* temp = root;
				root = root->left;
				delete temp;
			}

			else {
				node* temp = FindMin(root->right);
				root->data = temp->data;
				root->right = Delete(root->right, temp->data);
			}
		}

		if (root == NULL)
			return root;


		root->height = Height(root);

		int balance = Height(root->left) - Height(root->right);

		//left left
		if (balance > 1 && data < root->left->data)
			root = RightRotate(root);

		//right right
		else if (balance < -1 && data > root->right->data)
			root = LeftRotate(root);

		//left right
		else if (balance > 1 && data > root->left->data)
		{
			root->left = LeftRotate(root->left);
			root = RightRotate(root);
		}

		//right left
		else if (balance < -1 && data < root->right->data)
		{
			root->right = RightRotate(root->right);
			root = LeftRotate(root);
		}

		return root;

	}

	void Inorder(node* root)
	{
		if (root == NULL) return;
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}

	void Preorder(node* root)
	{
		if (root == NULL) return;
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}

	node* RightRotate(node* root)
	{
		node* pivot = root->left;
		node* pivot_right = pivot->right;

		root->left = pivot_right;
		pivot->right = root;

		root->height = Height(root);
		pivot->height = Height(pivot);

		return pivot;
	}
	node* LeftRotate(node* root)
	{
		node* pivot = root->right;
		node* pivot_left = pivot->left;

		root->right = pivot_left;
		pivot->left = root;
		
		root->height = Height(root);
		pivot->height = Height(pivot);

		return pivot;
	}

	int Height(node* root)
	{
		if (root == NULL)
			return -1;
		return max(1 + Height(root->right), 1 + Height(root->left));
	}

	node* FindMin(node* root)
	{
		if (root == NULL)
			return NULL;
		while (root->left != NULL)
			root = root->left;
		return root;
	}
	node* FindMax(node* root)
	{
		if (root == NULL)
			return NULL;
		while (root->right != NULL)
			root = root->right;
		return root;

	}
 
	

};

int main(void)
{
	AVL avl;
	node* root = NULL;
	root = avl.Insert(root, 3);
	root = avl.Insert(root, 2);
	root = avl.Insert(root, 1);
	root = avl.Delete(root, 2);
	avl.Preorder(root);
	cout << endl;

	

	return 0;
}