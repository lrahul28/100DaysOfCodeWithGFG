#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with equal 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<long long int, long long int> mp;
        int sum = 0;
        long long int ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += (arr[i] == 0)? -1 : arr[i];
            if(mp.find(sum) != mp.end())
            {
                ans += mp[sum];
            
            }
            mp[sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends