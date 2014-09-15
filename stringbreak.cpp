#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int cost(int p[], int i, int j)
{
    if(i == j-1)
        return 0;
    int k;
    int min = INT_MAX;

    for (k = i+1; k <j; ++k)
    {
        int count = cost(p, i, k) +
                cost(p, k, j) +
                p[j]-p[i];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}

void print(int cost[][5], int i, int j, int *p)
{
	for(int k=i+1; k < j; ++k)
	{
		int temp = cost[i][k] + cost[k][j] + p[j] - p[i];
		if (temp == cost[i][j])
		{
			cout<<p[k]<<endl;
			print(cost,i, k, p);
			print(cost,k, j, p);
			return;
		}
	}
}

int costRec(int p[], int len)
{
	int minCost[5][5];
	
	memset(minCost, 0, sizeof(minCost));
	for(int gap = 2; gap < len; ++gap)
	{
		for(int i = 0, j = gap; j< len; ++i, ++j)
		{
			int min = INT_MAX;

			for(int k = i+1; k<j; ++k)
			{
				int temp = minCost[i][k] + minCost[k][j] + p[j] - p[i];
				if (temp < min)
					min = temp;
				
			}
			minCost[i][j] = min;
		}
	}
	for(int i = 0; i <len; ++i)
	{
		for(int j = 0; j <len; ++j)
		{
			cout<<minCost[i][j]<< " ";
		}
		cout<<endl;
	}
	print(minCost, 0, len-1, p);

	return minCost[0][4];
}

// Driver program to test above function
int main()
{
    int arr[] = {0, 2,8,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum cost %d ", 
                          cost(arr,0,n-1));
 
    getchar();
    return 0;
}