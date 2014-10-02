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

	return dp[0];
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

	return dp[0][SIZE-1];
}

int main()
{
	int a[SIZE][SIZE] = {{3,0,0,0},{10,7,0,0},{12,14,13,0},{20,19,23,16}};
	cout<<maxSumPathOptimized(a);
	getchar();
    return 0;
}