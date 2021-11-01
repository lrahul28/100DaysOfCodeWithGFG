// Given an array of negative and non negative integers find all the
// distinct pairs whose sum is > 0
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    
    public:
    long long int findPair(int a[], int n, int element, int l, int h)
    {
        
        long long int c = 0;
        while(l <= h)
        {
            int mid = (l + h) / 2;
            if(a[mid] + element > 0)
            {
                
                c += h - mid + 1;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return c;
    }
    long long ValidPair(int a[], int n) 
    { 
    	sort(a, a + n);
    	long long int ans = 0;
    	
    	for(int i = 0; i < n; i++)
    	{
    	    ans += findPair(a, n, a[i], 0, i - 1) + findPair(a, n, a[i], i + 1, n - 1);
    	}
    	
    	
    	return ans / 2;
    }   
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends