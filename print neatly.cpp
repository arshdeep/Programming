#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*CLRS pretty print DP 
http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/ */

int printSolution (vector<int> &p, int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}

int printNeatly(int *l, int n, int m)
{
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	vector<vector<int>> cost(n+1, vector<int>(n+1));
	vector<int> minCost(n+1);
	vector<int> path(n+1);

	for (int i = 1; i <= n; ++i)
	{
		dp[i][i] = m - l[i - 1];
		for (int j = i + 1; j <= n; ++j)
		{
			dp[i][j] = dp[i][j-1] - l[j - 1] - 1;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			int temp = dp[i][j];

			if (j == n && temp >= 0)
				cost[i][j] = 0;
			else if (temp < 0)
				cost[i][j] = INT_MAX;
			else cost[i][j] = temp * temp;
		}
	}

	minCost[0] = 0;
	for (int j = 1; j <= n; ++j)
	{
		minCost[j] = INT_MAX;
		for (int i = 1; i <= j; ++i)
		{
			if (minCost[i - 1] != INT_MAX && cost[i][j] != INT_MAX
				&& (minCost[i - 1] + cost[i][j] < minCost[j]))
			{
				minCost[j] = minCost[i - 1] + cost[i][j];
				path[j] = i;
			}
		}
	}
	printSolution(path, n);
	return minCost[n];
}

int main()
{
   // int l[] = {5, 3, 5,8,4,4,7};
	int l[] = {3,2,2,5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;

    cout<<endl<<"Cost min :"<<printNeatly (l, n, M);
	getchar();
    return 0;
}