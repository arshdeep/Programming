#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

int largestSubBST(node *&p, int &min, int &max, int &maxNodes, node *&largestBST)
{
	if (p == NULL)
		return 0;
	bool isBST = true;
	int leftNodes = largestSubBST(p->left, min, max, maxNodes, largestBST);
	int minLeft = leftNodes == 0 ? p->data : min;

	if (leftNodes == -1 || (leftNodes != 0 && p->data <= max))
		isBST = false;

	int rightNodes = largestSubBST(p->right, min, max, maxNodes, largestBST);
	int maxRight = rightNodes == 0 ? p->data : max;

	if (rightNodes == -1 || (rightNodes != 0 && p->data >= min))
		isBST = false;
	if (isBST)
	{
		min = minLeft;
		max = maxRight;
		int totalNodes = leftNodes + rightNodes + 1;
		if (maxNodes < totalNodes)
		{
			maxNodes = totalNodes;
			largestBST = p;
		}
		return totalNodes;
	}
	else
		return -1;
}

void print (node *p)
{
	if (p == NULL) return;
	print(p->left);
	cout<<p->data<< " ";
	print(p->right);
}

// largest sub bst without decendentants
int largestSubBST2(node *&p, int min, int max, int &maxNodes, node *&largestBST, node *&child)
{
	if (p == NULL) return 0;

	if(p->data > min && p->data < max)
	{
		int lNodes = largestSubBST2(p->left, min, p->data, maxNodes, largestBST, child);
		node *lchild = lNodes == 0 ? NULL : child;

		int rNodes = largestSubBST2(p->right, p->data, max, maxNodes, largestBST, child);
		node *rchild = rNodes == 0 ? NULL : child;

		node *newP = newNode(p->data);
		newP->left = lchild;
		newP->right = rchild;

		child = newP;

		int totalNodes = lNodes + rNodes + 1;

		if (maxNodes < totalNodes)
		{
			maxNodes = totalNodes;
			largestBST = newP;
		}
		return totalNodes;
	}
	else
	{
		min = INT_MIN;
		max = INT_MAX;
		largestSubBST2(p, min, max, maxNodes, largestBST, child);
		return 0;
	}
}

int main(int argc, char *argv[])
{
	struct node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->right->right = newNode(7);

	root->left->left = newNode(1);
	root->left->right = newNode(8);

	int maxNodes = INT_MIN;
	node *largestBST = NULL;
	int min = INT_MIN;
	int max = INT_MAX;

	//largestSubBST(root, min, max, maxNodes, largestBST);
	//print(root);
	//cout<<maxNodes<<endl;
	node *child = NULL;

	largestSubBST2(root, min, max, maxNodes, largestBST, child);
	print(largestBST);

	getchar(); 
   return 0;
}