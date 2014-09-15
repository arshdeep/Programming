#include<iostream>
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
int knapSackProblem(int w[], int v[], int n, int t)
{
    if (NULL == v || NULL == w || n <= 0 || t <= 0)
        return -1;
 
    int rec[500][500] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (j < w[i-1])
                rec[i][j] = rec[i-1][j];
            else
                rec[i][j] = max(rec[i-1][j], rec[i-1][j-w[i-1]] + v[i-1]);
        }
    }

    int tmp = t;
    for (int i = n; i > 0 && tmp; i--)
    {
        if (rec[i][t] != rec[i-1][t])
        {
            cout<<i<<" ";
            tmp -= w[i-1];
        }
    }
 
    return rec[n][t];
}
 
int main()
{
    int val[] = {60, 100, 120, 10};
    int wt[] = {10, 20, 30, 50};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSackProblem(wt, val, n, W));
    return 0;
}