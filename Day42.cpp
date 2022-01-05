//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    bool check(vector<int> &A, int X, int mid)
    {
        int n = A.size();
        int m = 0, ans  = n;
        
        for(int i = 30; i >= 0; i--)
        {
            if((ans >> i) & 1)
            {
                m ^= (1ll << i);
                continue;
            }
            int c = 0;
            int m2 = m ^= (1ll << i);
            for(auto &j : A)
            {
                if((j & m2) == m2)
                {
                    c++;
                }
            }
            ans = min(ans, n - c);
        }
    }
    int count(int N, vector<int> A,int X)
    {
         // code here
        int prefix=0,ans=N;
        for(int i=30;i>=0;i--){
            if(((X>>i)&1)!=0){
                prefix^=(1l<<i);
                continue;
            }
            int ct=0;
            long p=prefix^(1l<<i);
            for(int j=0;j<N;j++){
                if((A[j]&p)==p)
                    ct++;
            }
            ans=min(ans,N-ct);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends