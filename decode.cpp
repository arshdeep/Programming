#include <iostream>
#include <cstring>
using namespace std;
 
// A Dynamic Programming based function to count decodings
int countDecodingDP(char *digits, int n)
{
    int count[101]; // A table to store results of subproble
	count[0] = 1;
	if (digits[0] >='1' && digits[0] <= '9')
		count[1] = 1;
	else return 0;

    for (int i = 2; i <= n; i++)
    {
		if (digits[i - 1] >='1' && digits[i - 1] <= '9')
		{
			if ((digits[i-2] == '1' && digits[i-1] >='0' && digits[i-1] <= '9')
				|| digits[i-2] == '2' && digits[i-1] >='0' && digits[i-1] <= '6')
				count[i] = count[i -1] + count[i-2];
			else
				count[i] = count[i-1];
		}
		else
		{
			 if ((digits[i-2] == '1' && digits[i-1] >='0' && digits[i-1] <= '9')
				|| digits[i-2] == '2' && digits[i-1] >='0' && digits[i-1] <= '6')
			count[i] = count[i-2];
			 else
				 return 0;
		}
		

    }
    return count[n];
}
 
// Driver program to test above function
int main()
{
    char digits[] = "109";
    int n = strlen(digits);
    cout << "Count is " << countDecodingDP(digits, n);
    return 0;
}