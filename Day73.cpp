// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Money distributions GFG
// ncr % p Check fermats little theorem 
 // } Driver Code Ends
class Solution{
	public:
	long long power(long long x, long long y, long long mod)
	{
	     long long res = 1;
	    while(y)
	    {
	        if(y & 1) res = (res * x) % mod;
	        y = y >> 1;
	        x = (x * x) % mod;
	    }
	    return res;
	}
	long long inverseMod(long long n, long long mod)
	{
	    return power(n, mod - 2, mod);
	}
    int totalWays(int N, int K) {
        if(N < K) return 0;
        int n = N - 1;
        int k = K - 1;
        /*
            ncr % p = (n! / (r! * (n - r)!)) % p
            = (n! % p) * ((r!)^-1 * (n - r)!^-1) % p
            = (n! % p) * ((r!)^p - 2 * (n - r)!^p - 2) % p
        */
        int r = k;
        int mod = 1e9 + 7;
        long long ans = 1;
        for(int i = 0, j = n; i < r; i++, j--)
        {
            ans = (ans * j) % mod;
            ans = ans * inverseMod(i + 1, mod) % mod;
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n , k;
		cin >> n >> k;
		Solution ob;
		int ans = ob.totalWays(n, k);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends