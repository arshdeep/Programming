/* http://leetcode.com/onlinejudge#question_87
http://blog.theliuy.com/scramble-string/ */

#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
using namespace std;

bool isScrambled(string &s1, string &s2)
{
	int len = s1.length();
	if (len != s2.length()) return false;
	if (s1.compare(s2) == 0) return true;

	unsigned int scode1 = 0;
	unsigned int scode2 = 0;
	for (int i = 0; i< len; ++i)
	{
		scode1 += s1[i];
		scode2 += s2[i];
	}
	if (scode1 != scode2) return false;

	for(int i = 1; i < len; ++i)
	{
		if (isScrambled(s1.substr(0,i), s2.substr(0,i)) && isScrambled(s1.substr(i, s1.length() - i), s2.substr(i, s2.length()-i))
			|| isScrambled(s1.substr(0,i), s2.substr(s2.length() - i,i))
				&& isScrambled(s1.substr(i,s1.length()-i), s2.substr(0,s2.length()-i)))
			return true;
	}
	return false;
}

bool isScrambledEx(string &s1, string &s2)
{
	if (s1.length() == 0 || s2.length() == 0)
		return false;

	int i = 0;
	int j = s1.length() - 1;
	if (s1.compare(s2) == 0)
	{
		return true;
	}
	else
	{
		if (s1.length() > 1)
		{
			if (isScrambledEx(s1.substr(0, i + 1), s2.substr(j - i, j))
					&& isScrambledEx(s1.substr(i + 1, j), s2.substr(0, j - i)))
				return true;
			
			if(isScrambledEx(s1.substr(0, j - i), s2.substr(i + 1, j))
					&& isScrambledEx(s1.substr(j - i, j), s2.substr(0, i + 1)))
				return true;

			if (isScrambledEx(s1.substr(0, i + 1), s2.substr(0, i + 1))
					&& isScrambledEx(s1.substr(i + 1, j), s2.substr(i + 1, j)))
				return true;

			if (isScrambledEx(s1.substr(0, j - i), s2.substr(0, j - i))
					&& isScrambledEx(s1.substr(j - i, j), s2.substr(j - i, j)))
				return true;

			if (isScrambledEx(s1.substr(0, (i + j)/2 + 1), s2.substr(0, (i + j)/2 + 1))
					&& isScrambledEx(s1.substr((i + j)/2 + 1, j), s2.substr((i + j)/2 + 1, j)))
				return true;

			if (isScrambledEx(s1.substr(0, (i + j)/2 ), s2.substr(0, (i + j)/2))
					&& isScrambledEx(s1.substr((i + j)/2, j), s2.substr((i + j)/2, j)))
				return true;
			return false;
		}
		else
			return false;

	}

}
    // dynamic programming.
    // assume i -- the start index on s1, j -- the start index on s2, p -- the size of string.
    // state function f(i, j, k) = true if for any n = 1...k-1, 
    //    f(i, j + n, k - n) == true && f(i + k - n, j, n) == true
    // or f(i, j, n) == true && f(i + n, j + n, k - n) == true;
bool isScrambleDP(string s1, string s2) {
	int n = s1.size();
	vector<vector<vector<int>>> m(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j][1] = (s1[i] == s2[j]);
		}
	}
	for (int p = 2; p <= n; p++) {
		for (int i = 0; i <= n - p; i++) {
			for (int j = 0; j <= n - p; j++) {
				for (int k = 1; k <= p - 1; k++) {
					if (m[i][j][k] && m[i + k][j + k][p - k]) {
						m[i][j][p] = 1;
						break;
					} else if (m[i][j+k][p-k] && m[i + p - k][j][k]) {
						m[i][j][p] = 1;
						break;
					}
				}
			}
		}
	}
	return m[0][0][s1.size()];
}

int main()
{
	string s1 = "abcd";//"abbbcbaaccacaacc";
	string s2 = "badc";//"acaaaccabcabcbcb";//"badc"; "dbac"

	__time32_t start, end;
	_time32(&start);
	if (isScrambleDP(s1, s2))
	{
		cout<<"TRUE";
	}
	else
	{
		cout<<"FALSE";
	}

	_time32(&end);
	cout<<endl<<_difftime32(end, start);

	getchar();
	return 0;
}
