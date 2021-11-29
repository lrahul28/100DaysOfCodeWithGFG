// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// Nth root of M (Binary Search)
 // } Driver Code Ends
class Solution{
	public:
	int check(int n, int mid)
	{
	    int ans = 1;
	   for(int i = 0; i < n; i++) ans *= mid;
	   return ans;
	}
	int NthRoot(int n, int m)
	{
	    int l = 1, h = m;
	    while(l <= h)
	    {
	        int mid = (l + h) / 2;
	        if(pow(mid, n) == m) return mid;
	        if(pow(mid, n) >= m) h = mid;
	        else l = mid + 1;
	    }
	    
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends