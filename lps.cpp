#include <limits.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void print(vector<vector<int>> &dp, int i, int j, string &str)
{
	if (i > j) return;

	if (i == j) {
		cout<<str[j];
		return;
	}

	if (str[i] == str[j])
	{
		cout<<str[j];
		print(dp, i + 1, j - 1, str);
		cout<<str[j];
	}
	else {
		if (dp[i+1][j] > dp[i][j-1])
			print(dp, i+1,j,str);
		else
			print(dp, i, j-1,str);
	}

}

int lps(string &str)
{
	int n = str.length();
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
	}

	for (int gap = 1; gap < n; ++gap)
	{
		for (int i = 0, j = gap; j < n; ++j, ++i)
		{
			if (str[i] == str[j])
			{
				dp[i][j] = dp[i + 1] [j - 1] + 2;
			}
			else {
				dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	print(dp, 0, n-1, str);
	return dp[0][n-1];
}
int main()
{
    string seq = "GEEKS FOR GEEKS";
    printf ("\nThe lnegth of the LPS is %d", lps(seq));
    getchar();
    return 0;
}