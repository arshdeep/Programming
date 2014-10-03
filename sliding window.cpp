#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
/*Sliding window 
http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
*/

void printKMax(int *a, int n, int k)
{
	deque<int> q;
	int i = 0;

	for (; i< k; ++i)
	{
		if (!q.empty() && a[q.back()] < a[i])
			q.pop_back();
		q.push_back(i);
	}

	for (;i < n; ++i)
	{
		cout<<a[q.front()]<< " ";

		if (!q.empty() && q.front() <= i - k)
			q.pop_front();
		if (a[q.back()] < a[i])
			q.pop_back();

		q.push_back(i);
	}

	cout<<a[q.front()]<< " ";
}
int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
	getchar();
    return 0;
}