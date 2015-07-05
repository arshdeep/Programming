#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int val;
    struct node *left, *right;
};

struct node * NewNode(int val)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->right = tmp->left =NULL;
    return tmp;
}

bool isPairPresent(node *root, int x)
{
	stack<node *> fstk;
	stack<node *> rstk;
	bool flag1 = true, flag2 = true;
	node *cur = root;
	node *cur2 = root;

	int val1 = 0, val2 = 0;
	while (1)
	{
		while (flag1)
		{
			if (cur)
			{
				fstk.push(cur);
				cur = cur->left;
			}
			else if (fstk.empty()) {
				flag1 = false;
			}
			else {
				node *top = fstk.top();
				val1 = top->val;
				fstk.pop();
				cur = top->right;
				flag1 = false;
			}
		}

		while (flag2)
		{
			if (cur2)
			{
				rstk.push(cur2);
				cur2 = cur2->right;
			}
			else if (rstk.empty()) {
				flag2 = false;
			}
			else {
				node *top = rstk.top();
				val2 = top->val;
				rstk.pop();
				cur2 = top->left;
				flag2 = false;
			}
		}

		if (val1 + val2 == x) {
			cout<< "found";
			return true;
		}

		if (val1 + val2 > x)
			flag2 = true;
		else
			flag1 = true;

		if (val1 >= val2)
			return false;
	}
}
int main()
{
    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct node *root =  NewNode(15);
    root->left = NewNode(10);
    root->right = NewNode(20);
    root->left->left = NewNode(8);
    root->left->right = NewNode(12);
    root->right->left = NewNode(16);
    root->right->right = NewNode(25);
 
    int target = 33;
    if (isPairPresent(root, target) == false)
        printf("\n No such values are found\n");
 
    getchar();
    return 0;
}