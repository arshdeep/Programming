#include<iostream>
#include<limits.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& height) {
    stack<int> stk;
    int res = 0;
    int i = 0, n = height.size();
        
    while( i < n) {
        if (stk.empty() || height[i] >= height[stk.top()]) {
            stk.push(i++);
        }
        else {
            int top = stk.top();
            stk.pop();
                
            res = std::max( res, height[top] * (stk.empty() ? i : i - stk.top() - 1) );
        }
    }
        
    while ( !stk.empty() ) {
        int top = stk.top();
        stk.pop();
            
        res = std::max( res, height[top] * (stk.empty() ? i : i - stk.top() - 1) );
    }
    return res;
}

// Driver program to test above function
int main()
{
    vector<int> vect;

	vect.push_back(2);
	vect.push_back(1);
	vect.push_back(5);
	vect.push_back(6);

	vect.push_back(4);
	vect.push_back(3);
	cout<<largestRectangleArea(vect);
    getchar();
    return 0;
}