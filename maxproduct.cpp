#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;
/*
 public class Solution {
 public int maxProduct(int[] A) {
 if (A == null || A.length == 0) {
 return 0;
 }
 int[] f = new int[A.length];
 int[] g = new int[A.length];
 f[0] = A[0];
 g[0] = A[0];
 int res = A[0];
 for (int i = 1; i < A.length; i++) {
 f[i] = Math.max(Math.max(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
 g[i] = Math.min(Math.min(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
 res = Math.max(res, f[i]);
 }
 return res;
 }
 }
 */
int maxproduct(int *arr, int n)
{
    int maxproduct = -1;
    int max = arr[0];
    int prev = arr[0];
    int start = 0;
    int end = 0;
    
    for (int i = 1; i< n; ++i)
    {
        if (arr[i] == 0)
        {
            start = i + 1;
            end = i + 1;
            max = 0;
            prev = 0;
        }
        else{
            prev = prev * arr[i];
            if (prev == 0) prev = arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
            
            }
            else if (max < prev)
            {
                max = prev;
                end = i;
            }
            
        }
        
        
        maxproduct = std::max(max, maxproduct);
    }
    return maxproduct;
}

// Driver program to test abive function
int main()
{
    int a[] = {-3, -40, 0, -2};
    
    cout<<maxproduct(a, sizeof(a)/sizeof(a[0]))<<endl;
    
    return 0;
}
