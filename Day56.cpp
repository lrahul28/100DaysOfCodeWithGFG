//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    
    public:
    int findSum(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
        
    }
    int maxiSum(vector<int> v)
    {
        int sum = 0;
        for(int i = 0; i < 2; i++) sum += v[i];
        return sum;
    }
    int RulingPair(vector<int> arr, int n) 
    { 
        unordered_map<int, int> mp;
        int maxi_sum = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int sum = findSum(arr[i]);
            if(mp.find(sum) != mp.end())
            {
                maxi_sum = max(maxi_sum, mp[sum] + arr[i]);
                mp[sum] = max(mp[sum], arr[i]);
            }
            else
            {
                mp[sum] = arr[i];
            }
        }
        if(maxi_sum == INT_MIN) return -1;
        return maxi_sum;
        
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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
	    Solution obj;
		cout << obj.RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends