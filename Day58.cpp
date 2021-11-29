//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution {
  public:
    
    /*
    find the number of subarrays having sum less than or equal to R. 
    From this count, subtract the number of subarrays 
    having sum less than or equal to L-1.
    */
    long long count_subarray_sum_less_than_k(int n,vector<int> &a,long long k)
    {
        ll res=0,l=0,r=0,csum=0;
        while(r<n)
        {
            csum += a[r];
            while(csum>k)
                csum -= a[l++];
                
            res += r-l+1;
            r++;
        }
        return res;
    }
  
    long long countSubarray(int n,vector<int> a,long long l,long long r) {
    // code here
    
        ll lessThanl_1 = count_subarray_sum_less_than_k(n,a,l-1);
        ll lessThanR = count_subarray_sum_less_than_k(n,a,r);
        
        return lessThanR - lessThanl_1;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}    // } Driver Code Ends