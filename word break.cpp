#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

bool wordBreak(string str)
{
	int len = str.length();

	for (int i = 1; i <= len; ++i)
	{
		if (dictionaryContains(str.substr(0, i)) && wordBreak(str.substr(i, len - i)))
			return true;
	}

	return len > 0 ? false : true;
}

void print(vector<int> &dp, int size, string str)
{
	if (size == 1) return;
	int len = dp[size-1];
	if (len == -1)
		print(dp, size-1, str);
	print(dp, len, str.substr(0, len-1));
	cout<<str.substr(len - 1, str.length() - (len - 1))<< " ";
}
bool wordBreakDP(string str)
{
	int len = str.length();
	vector<int> dp(len+1);

	dp[0] = 1;
	for (int i = 1; i <= len; ++i)
	{
		for (int j = 1; j <= len - (i - 1); ++j)
		{
			if (dictionaryContains(str.substr(i-1, j)) && dp[i-1])
			{
				dp[i+j-1] = i;
				if (i+j -1 == len)
				{
					print(dp, dp.size(), str);
					cout<<endl;
				}
			}
		}
	}
	return dp[len];
}
int main()
{
    wordBreakDP("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreakDP("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakDP("")? cout <<"Yes\n": cout << "No\n";
    wordBreakDP("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreakDP("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreakDP("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	getchar();
    return 0;
}