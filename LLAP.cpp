#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lenghtOfLongestAP(int *arr, int size)
{
	if (size == 2) return size;

	vector<vector<int>> dp(size, vector<int>(size));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			dp[i][j] = 2;
		}
	}
	int max = 2;
	for (int j = 1; j < size-1; ++j)
	{
		int i = j - 1;
		int k = j + 1;

		while(i >=0 && j < size)
		{
			int e1 = arr[j]*2;
			int e2 = arr[i] + arr[k];
			if (e1 == e2)
			{
				dp[j][k] = dp[i][j] + 1;
				max = std::max(max, dp[j][k]);
				i--;
				k++;
			}
			else {
				if (e1 > e2)
					k++;
				else
					i--;
			}
		}
	}
	return max;
}
int main()
{
    int set1[] = {1, 7, 10, 15, 27, 29, 33,38,43};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    cout <<   lenghtOfLongestAP(set1, n1) << endl;
 
    int set2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    cout <<   lenghtOfLongestAP(set2, n2) << endl;
 
    int set3[] = {5,10,15,20,25,30,35};
    int n3 = sizeof(set3)/sizeof(set3[0]);
    cout <<   lenghtOfLongestAP(set3, n3) << endl;
 
	getchar();
    return 0;
}