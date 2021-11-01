// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	bitset<32> bset(n);
    	for(int i = 0; i < bset.size(); i+=2)
    	{
    	    int temp = bset[i];
    	    bset[i] = bset[i + 1];
    	    bset[i + 1] = temp;
    	}
    	return bset.to_ulong();
    	
    	
    	
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends