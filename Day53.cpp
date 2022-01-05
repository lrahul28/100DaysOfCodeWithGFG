//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
// Division without using multiplication operator
 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        int flag = 0;
        if((dividend < 0 and divisor >= 0) or (dividend > 0 and divisor <= 0))
        {
            flag = 1;
            
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ans = 0;
        int temp = divisor;
        while(dividend - divisor >= 0)
        {
            int count = 1;
            while(dividend - (divisor << 1) >= 0)
            {
                count = count << 1;
                divisor = divisor << 1;
            }
            dividend = dividend - divisor;
            divisor = temp;
            ans = ans + count;
        }
        if(flag == 1) return -1 * ans;
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}
  // } Driver Code Ends