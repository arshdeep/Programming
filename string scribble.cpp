#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

bool isScribble(string &s1, string &s2)
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
		if (isScribble(s1.substr(0,i), s2.substr(0,i)) && isScribble(s1.substr(i, s1.length() - i), s2.substr(i, s2.length()-i))
			|| isScribble(s1.substr(0,i), s2.substr(s2.length() - i,i)) && isScribble(s1.substr(i,s1.length()-i), s2.substr(0,s2.length()-i)))
			return true;
	}
	return false;
}

bool isScribbleEx(string &s1, string &s2)
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
			if (isScribble(s1.substr(0, i + 1), s2.substr(j - i, j))
					&& isScribble(s1.substr(i + 1, j), s2.substr(0, j - i)))
				return true;
			
			if(isScribble(s1.substr(0, j - i), s2.substr(i + 1, j))
					&& isScribble(s1.substr(j - i, j), s2.substr(0, i + 1)))
				return true;

			if (isScribble(s1.substr(0, i + 1), s2.substr(0, i + 1))
					&& isScribble(s1.substr(i + 1, j), s2.substr(i + 1, j)))
				return true;

			if (isScribble(s1.substr(0, j - i), s2.substr(0, j - i))
					&& isScribble(s1.substr(j - i, j), s2.substr(j - i, j)))
				return true;

			if (isScribble(s1.substr(0, (i + j)/2 + 1), s2.substr(0, (i + j)/2 + 1))
					&& isScribble(s1.substr((i + j)/2 + 1, j), s2.substr((i + j)/2 + 1, j)))
				return true;

			if (isScribble(s1.substr(0, (i + j)/2 ), s2.substr(0, (i + j)/2))
					&& isScribble(s1.substr((i + j)/2, j), s2.substr((i + j)/2, j)))
				return true;
			return false;
		}
		else
			return false;

	}

}
int main()
{
	string s1 = "abbbcbaaccacaacc";
	string s2 = "acaaaccabcabcbcb";//"badc"; "dbac"

	__time32_t start, end;
	_time32(&start);
	if (isScribbleEx(s1, s2))
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
