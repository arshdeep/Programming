#include<iostream>
using namespace std;

void print(int dp[][15], int s, int e, char *seq)
{
	if (s >= e)
	{
		if(s == e)
			cout<<seq[e];
		return;
	}

	if (seq[s] == seq[e])
	{
		cout<<seq[s];
		print(dp, s +1, e - 1, seq);
		cout<<seq[e];
	}
	else
	{
		if (dp[s + 1][e] > dp[s][e-1])
		{
			print(dp, s+1, e, seq);
		}
		else
		{
			print(dp, s, e-1, seq);
		}
	}
}

int lps(char *seq, int n)
{
	int dp[15][15];

	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
	}

	for(int gap = 1; gap < n; ++gap)
	{
		for(int i = 0, j = gap; j < n; ++i, ++j)
		{
			if (seq[i] == seq[j])
			{
				dp[i][j] = dp[i+1][j-1] + 2;
			}
			else
			{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	print(dp, 0, n-1, seq);
	return dp[0][n-1];
}

int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf ("\nThe lnegth of the LPS is %d", lps(seq, n));
    getchar();
    return 0;
}