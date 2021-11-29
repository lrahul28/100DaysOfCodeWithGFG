// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
    // Find the maximum value of arr[i] * i
 // } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a, a + n);
        long long int ans = 0;
        for(int i = 0; i < n; i++)
        {
            long long int p = (1ll * a[i] * i) % 1000000007;
            ans = (ans + p) % 1000000007;
        }
        return ans % 1000000007;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends