#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

int cutRodRec(int *p, int n)
{
	if (n <= 0) return 0;
	int max = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		max = std::max(max, p[i] + cutRodRec(p, n - i - 1));
	}
	return max;
}

int rodCut(int *p, int n)
{
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		int max = INT_MIN;
		for (int j = 0; j < i; j++)
		{
			max = std::max(p[j] + dp[i - j - 1], max);
		}
		dp[i] = max;
	}

	cout<< "Possible cuts at: ";
	int nBestCut = dp[n];
    int nCurLen = n;
    while (nBestCut > 0)
    {
        for (int i = 1; i <= nCurLen; i++)
        {
            if (nBestCut == p[i-1] + dp[nCurLen-i])
            {
                nBestCut -= p[i-1];
				cout<<i << " ";
                nCurLen -= i;
                continue;
            }
        }
    }
	cout <<endl;

	return dp[n];
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", rodCut(arr, size));
    getchar();
    return 0;
}