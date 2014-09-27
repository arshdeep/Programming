#include <limits.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestPalSubstr(string &str)
{
	int n = str.length();
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 1;
	}
	int mxlen = INT_MIN;
	int start = INT_MIN;

	for( int i = 0; i < n-1; ++i )
    {
        if( str[i] == str[i+1] )
        {
            dp[i][i+1] = 1;
            start = i;
            mxlen = 2;
        }
    }
	for (int gap = 2; gap < n; ++gap)
	{
		for (int i = 0, j = gap; j < n; ++j, ++i)
		{
			if (dp[i + 1][j - 1] && str[i] == str[j])
			{
				dp[i][j] = 1;
				if (mxlen < gap)
				{
					mxlen = j-i+1;
					start = i;
				}
			}
		}
	}

	cout<<str.substr(start, mxlen)<<endl;
	return mxlen;
}

int main()
{
    string str = "rofgeeksskeegfor";

    printf("\nLength is: %d\n", longestPalSubstr( str ) );
	getchar();
    return 0;
}