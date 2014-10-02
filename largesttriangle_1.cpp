#include<iostream>
using namespace std;

void print(int dp[][4], int s, int e, int n, int m, int in[][4])
{
	if (s>=4)
		return;
	cout<<in[s][e]<< " ";

	if (dp[n+1][m] > dp[n][m - 1])
		print(dp, s + 1, e + 1, n + 1, m, in);
	else
		print(dp, s + 1, e, n, m-1, in);
}

int maxSum(int in[][4], int n)
{
	int dp[4][4];

	memset(dp, 0, sizeof(dp));

	for(int i = 0; i< n; ++i)
	{
		dp[i][i] = in[n-1][i];
	}

	for (int gap = 1; gap < n; ++gap)
	{
		for (int i = 0, j = gap; j < n; ++i, ++j)
		{
			dp[i][j] = in[n - 1 - gap][i] + max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	print(dp, 0,0, 0, n-1, in);
	return dp[0][n-1];
}

int main()
{
	int in[4][4] = {{3,0,0,0},{10,7,0,0},{12,14,13,0},{20,19,23,16}};
    printf ("\n max sum in triangle %d", maxSum(in, 4));
    getchar();
    return 0;
}