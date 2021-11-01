// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long int> st;
        long long int ans = INT_MIN;
        vector<long long int> leftSmall(n, -1), rightSmall(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push(0);
                leftSmall[i] = 0;
            }
            else
            {
                while(!st.empty() and arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if(st.empty()) leftSmall[i] = 0;
                else leftSmall[i] = st.top() + 1;
                st.push(i);
            }
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push(n - 1);
                rightSmall[i] = n - 1;
            }
            else
            {
                while(!st.empty() and arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if(st.empty()) rightSmall[i] = n - 1;
                else rightSmall[i] = st.top() - 1;
                st.push(i);
            }
        }
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, (rightSmall[i] - leftSmall[i] + 1) * arr[i]);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends