#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> &dp, int i, int j, char *x, char *y)
{
	if (i > j) return ;
	if (x[i-1] == y[j-1])
	{
		print(dp, i - 1, j - 1, x, y);
		cout<<x[i-1];
	}
}

int lcs(char *x, char *y, int n, int m)
{
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	int max = -1;
	int start, end;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				if(max < dp[i][j])
				{
					max = dp[i][j];
					start = i;
					end = j;
				}
			}
		}
	}
	print(dp, start, end, x, y);
	return max;
}

int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    cout <<endl<< "Length of Longest Common Substring is " << lcs(X, Y, m, n);
	getchar();
    return 0;
}