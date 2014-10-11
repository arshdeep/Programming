#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum(int *vect, int s, int e)
{
	int sum = 0;

	for (int i = s; i < e; ++i)
	{
		sum += vect[i];
	}

	return sum;
}
// exponential time complexity
int partition(int *arr, int n, int k)
{
	if (k == 1) return sum(arr, 0, n);
	if (n == 1) return arr[0];
	int min = INT_MAX;
	int max = INT_MAX;
	for (int i = 1; i < n; ++i)
	{
		int rsum = sum(arr, i, n);
		int lsum = partition(arr, i, k - 1);

		max = std::min(max, std::max(rsum, lsum));
	}
	return max;
}

// time : O(k * n ^ 2), space : O(nk)
int partitionDP(int *arr, int n, int k)
{
	vector<vector<int>> dp(n + 1, vector<int>(k+1));
	vector<int> csum(n+1);

	for (int i = 1; i <= n; ++i)
	{
		csum[i] = csum[i - 1] + arr[i-1];
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[i][1] = csum[i];
	}

	for (int kk = 1; kk <= k; ++kk)
	{
		dp[1][kk] = arr[0];
	}

	for (int kk = 2; kk <= k; ++kk)
	{
		for (int i = 2; i <= n; ++i)
		{
			int best = INT_MAX;
			for (int j = 1; j <= i; ++j)
			{
				best = std::min(best, std::max(dp[j][kk-1], csum[i] - csum[j]));
			}
			dp[i][kk] = best;
		}
	}
	return dp[n][k];
}

int main(int argc, char *argv[])
{
	int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int size = sizeof(a)/sizeof(a[0]);
	cout<<partitionDP(a, size, 3)<<endl;

	cout<<partitionDP(a, size, 5)<<endl;
	int a2[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
	size = sizeof(a2)/sizeof(a2[0]);
	cout<<partitionDP(a2, size, 6)<<endl;
	int a3[] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782};
	size = sizeof(a3)/sizeof(a3[0]);
	cout<<partitionDP(a3, size, 4);

	getchar(); 
   return 0;
}