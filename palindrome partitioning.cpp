#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;


// O(n^3)
int minCut(string s) {
	int size = s.length();
	vector<vector<int>> minCuts(size, vector<int>(size));
	vector<vector<int>> palindrome(size, vector<int>(size));

	for (int i = 0; i < size; ++i)
	{
		palindrome[i][i] = 1;
	}

	for (int len = 1; len < size; ++len)
	{
		for (int i = 0, j = len; j < size; ++j, ++i)
		{
			if (len == 1 && s[i] == s[j])
				palindrome[i][j] = 1;
			else
				palindrome[i][j] = palindrome[i + 1][j-1] && s[i] == s[j];

			if (!palindrome[i][j])
			{
				minCuts[i][j] = INT_MAX;
				for (int k = i; k < j; ++k)
				{
					minCuts[i][j] = std::min(minCuts[i][j], minCuts[i][k] + 1 + minCuts[k+1][j]);
				}
			}
		}
	}

	return minCuts[0][size-1];
}

// O(n^2)
int minCutOtimized(string s) {
	int size = s.length();
	vector<int> minCuts(size+1);
	vector<vector<int>> palindrome(size, vector<int>(size));

	for (int i = 0; i < size; ++i)
	{
		palindrome[i][i] = 1;
	}

	for (int i = 0; i <= size; ++i)
	{
		minCuts[i] = size - i - 1;
	}

	for (int len = 1; len < size; ++len)
	{
		for (int i = 0, j = len; j < size; ++j, ++i)
		{
			if (len == 1 && s[i] == s[j])
				palindrome[i][j] = 1;
			else
				palindrome[i][j] = palindrome[i + 1][j-1] && s[i] == s[j];
		}
	}

	for (int i = size - 1; i >= 0; --i)
	{
		for (int j = i; j < size; ++j)
		{
			if (palindrome[i][j])
			{
				minCuts[i] = std::min(minCuts[i], minCuts[j+1]+1);
			}
		}
	}

	return minCuts[0];
}

int main(int argc, char *argv[])
{
	string str = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d",
           minCutOtimized(str));

	getchar(); 
   return 0;
}