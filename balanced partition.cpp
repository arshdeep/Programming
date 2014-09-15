#include<iostream>
using namespace std;
 
int getNegOnes(int a[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
         
        int half = sum/2 + 1;
        bool **rec = new bool*[n];

		for (int i = 0; i <= n; ++i)
		{
			rec[i] = new bool[half];
		}

        for (int i = 0; i <= n; i++)
            rec[i][0] = true;
         
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= half; j++)
            {
                if (rec[i-1][j] || (j - a[i] >= 0 && rec[i-1][j - a[i]]))
                    rec[i][j] = true;
            }
        }
        
		for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= half; j++)
            {
                cout<<rec[i][j]<< " ";
            }
			cout<<endl;
        }

        int k = sum;
        for (int i = half; i >= 0; i--)
        {
            if (rec[n-1][i])
            {
                k = i;
                break;
            }
        }
         
        int ret = sum - k - k;
         
        for (int i = n; i > 0; i--)
        {
            if (k - a[i-1] >= 0 && rec[i-1][k - a[i-1]])
            {
                k -= a[i-1];
                cout<<a[i-1];
                cout<<" ";
            }
        }
         
        return ret;
    }
 
int main()
{
	int a[] = { 3, 5, 7, 11, 13, 7, 2, 12, 10, 3, 6 };
    cout<<getNegOnes(a, sizeof(a)/sizeof(a[0]));
    return 0;
}