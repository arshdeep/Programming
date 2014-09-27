#include <limits.h>
#include <iostream>
using namespace std;
/*leetcode.com/2010/04/multiplication-of-numbers.html*/
void multiplication(int *a, int *o, int n)
{
	int left = 1;
	int right = 1;
	for (int i = 0; i <n ; ++i)
	{
		o[i] *= left;
		o[n - i - 1] *= right;

		left *= a[i];
		right *= a[n - i - 1];
	}
}


// Driver program to test above functions
int main()
{
    int l[5] = {4,3,2,1,2};
	int o[5] = {1,1,1,1,1};

	int n = sizeof(l)/sizeof(l[0]);
	multiplication(l, o, n);
	for (int i = 0; i <n ; ++i)
	{
		cout<<l[i] << " ";
	}
	cout<<endl;
	for (int i = 0; i <n ; ++i)
	{
		cout<<o[i] << " ";
	}
	return 0;
}