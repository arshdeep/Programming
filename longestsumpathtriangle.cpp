#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define SIZE 4

// space O(n),time: O(n^2)
int maxSumPathOptimized(int a[][SIZE])
{
	vector<int> dp(SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		dp[i] = a[SIZE  - 1][i];
	}

	for (int gap = 1; gap < SIZE; ++gap)
	{
		for (int i = 0, j = gap; j < SIZE; ++j, ++i)
		{
			dp[i] = a[SIZE - gap - 1][i] + std::max(dp[i], dp[i + 1]);
		}
	}
	int max = dp[0];

	for (int i = 1; i < SIZE; ++i) {
		max = std::max(max, dp[i]);
	}
	return max;
}

void print(vector<vector<int>> &dp, int s, int e, int n, int m, int a[][SIZE])
{
	if (s >= SIZE || e >= SIZE) return;

	cout<<a[s][e]<< " ";

	if (dp[n][m-1] > dp[n+1][m])
		print(dp, s+1, e, n, m-1, a);
	else
		print(dp, s+1, e+1, n+1, m, a);
	
}
// space,time: O(n^2)
int maxSumPath(int a[][SIZE])
{
	vector<vector<int>> dp(SIZE, vector<int>(SIZE));

	for (int gap = 0; gap < SIZE; ++gap)
	{
		for (int i = 0, j = gap; j < SIZE; ++j, ++i)
		{
			dp[i][j] = a[SIZE - gap - 1][i];
		}
	}

	for (int gap = 1; gap < SIZE; ++gap)
	{
		for (int i = 0, j = gap; j < SIZE; ++j, ++i)
		{
			dp[i][j] = dp[i][j] + std::max(dp[i][j-1], dp[i+1][j]);
		}
	}
	print(dp, 0,0, 0, SIZE-1, a);
	return dp[0][SIZE-1];
}

int main()
{
	int a[SIZE][SIZE] = {{3,0,0,0},{10,7,0,0},{12,14,13,0},{20,19,23,16}};
	cout<<endl<<"max sum path: "<<maxSumPath(a);
	getchar();
    return 0;
}