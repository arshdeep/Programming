#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <set>
#include<stack>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <regex>
using namespace std;
/* http://community.topcoder.com/stat?c=problem_statement&pm=12155 */
#define SIZEOFARRAY(s) sizeof(s)/sizeof(s[0])
#define REP(i,n) for(int i=0;i<(n);++i)
#define LOOP(i,v,n) for(i=v;i<(n);++i)
#define LL long long
#define memSet(m, v) memset(m, v, sizeof(m))

struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postOrderIterative(Node* root) {
	if (!root) return;
	stack<Node*> dfs;
	Node* prev = NULL;
	dfs.push(root);

	while(!dfs.empty()) {
		Node *cur = dfs.top();
		if (!prev || prev->left == cur || prev->right == cur) {
			if (cur->left)
				dfs.push(cur->left);
			else if (cur->right)
				dfs.push(cur->right);
		}
		else if (cur->left == prev) {
			if (cur->right)
				dfs.push(cur->right);
		}
		else {
			cout<<cur->data<<" ";
			dfs.pop();
		}
		prev = cur;
	}
	cout<<endl;
}

void preorderIntr(Node *root) {
	if (!root) return;
	stack<Node*> dfs;

	dfs.push(root);

	while( !dfs.empty() ) {
		Node *top = dfs.top();
		dfs.pop();

		cout<<top->data<< " ";

		if (top->right)
			dfs.push(top->right);
		if (top->left)
			dfs.push(top->left);
	}

	cout<<endl;
}

void inorderItr(Node *root)
{
	if (!root) return;
	stack<Node*> dfs;
	Node *current = root;

	while( !dfs.empty() || current )
	{
		if (current)
		{
			dfs.push(current);
			current = current->left;
		}
		else {
			Node *top = dfs.top();
			dfs.pop();

			cout<<top->data<<" ";
			current = top->right;
		}
	}
}

int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    postOrderIterative(root);
	preorderIntr(root);
	inorderItr(root);
	getchar();
    return 0;
}