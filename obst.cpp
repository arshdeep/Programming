#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

struct treeNode
{
	int i;
	struct treeNode *left;
	struct treeNode *right;
};
#define SIZE 3
struct treeNode* innerPrint(int root[][3], int i, int j, int w[][3])
{
	struct treeNode *p = NULL;
	int tg = root[i][j];
	for (int k = i; k <= j; k++)
	{
		int tmp = (k>i ? root[i][k-1] : 0) + (j>k ? root[k+1][j] : 0) + w[i][j];
		if (tmp == tg)
		{
			p = (struct treeNode*)malloc(sizeof(treeNode));
			p->i = k;
			cout<<k<< " ";
			p->left = innerPrint(root, i, k-1, w);
			p->right = innerPrint(root, k+1, j, w);
			break;
		}
	}
	return p;
}
int optimalSearchTree(int *keys, int *freq, int n)
{
	int e[SIZE][SIZE];
	int w[SIZE][SIZE];

	memset(e, 0, sizeof(e));
	memset(w, 0, sizeof(w));

	for (int i = 0; i <n; ++i)
	{
		e[i][i] = freq[i];
		w[i][i] = freq[i];
	}

	for (int gap = 1; gap < n; ++gap)
	{
		for (int i = 0, j = gap; j < n; ++i, ++j)
		{
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j-1] + (j < n ? freq[j] : 0);

			for(int r = i; r <=j; ++r)
			{
				int t = (r>i ? e[i][r-1] : 0) + (j>r ? e[r+1][j] : 0) + w[i][j];
				if (t < e[i][j])
				{
					e[i][j] = t;
				}
			}
		}
	}
	innerPrint(e, 0, 2, w);
	return e[0][n];
}
int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
	return 0;
}