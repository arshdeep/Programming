#include<iostream>
using namespace std;

int smallest(int x, int y, int z){
    return std::min(std::min(x, y), z);
}

int editDistRec(char *a, char *b, int n, int m)
{
	if (n == 0 && m == 0)
		return 0;

	if (n > 0 && m == 0)
		return n;

	if (m > 0 && n == 0)
		return m;

	int x = editDistRec(a, b, n - 1, m) + 1;
	int y = editDistRec(a, b, n, m -1) + 1;
	int z = editDistRec(a, b, n - 1, m - 1) + (a[n-1] != b[m-1] ? 1: 0);
	return smallest(x,y, z);
}
 
int editDist(char *a, char *b, int n, int m)
{
	if (a == NULL && b == NULL)
		return -1;

	int **edit = new int*[n+1];

	for(int i = 0; i <=n; ++i)
		edit[i] = new int[m+1];
	for(int i = 0; i <=n; ++i)
		edit[i][0] = i;
	for(int i = 0; i <=m; ++i)
		edit[0][i] = i;

	for(int i = 1; i <=n; ++i)
	{
		for(int j = 1; j <=m; ++j)
		{
				
				int x = edit[i - 1][j] + 1;
				int y = edit[i][j - 1] + 1;
				int z = edit[i - 1][j - 1] + (a[i-1] != b[j-1] ? 1 : 0);
				edit[i][j] = smallest(x,y, z);
		}
	}

	return edit[n][m];
}

int main()
{
	char *a = "SATURDAY";
	char *b = "SUNDAY";

	cout<<editDist(a, b, strlen(a), strlen(b));
	getchar();
    return 0;
}