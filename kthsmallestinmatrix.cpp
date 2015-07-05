#include<iostream>
#include<queue>
using namespace std;
 /*http://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/*/

struct Item
{
	int val;
	int col;
	int row;
	Item(int _val, int _row, int _col) : val(_val), row(_row), col(_col) {}

	bool operator<(const Item &rhs) const
	{
		return this->val > rhs.val;
	}
};
int kthSmallest(int mat[4][4], int n, int k)
{
	priority_queue<Item> pq;
	for (int i = 0; i< 4; ++i)
		pq.push(Item(mat[0][i], 0, i));

	int res = -1;
	for (int idx = 0; idx < k; ++idx)
	{
		Item top = pq.top();
		res = top.val;
		pq.pop();
		(top.row < n - 1) ? pq.push(Item(mat[top.row + 1][top.col], top.row + 1, top.col)) : pq.push(Item(INT_MAX, top.row + 1, top.col));
	}

	return res;
}
 
int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}