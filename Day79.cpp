#include <bits/stdc++.h>
// Maximum Product Obtained in the array of +ve and -ve elements
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long maxi1 = INT_MIN;
	    long long maxi2 = INT_MIN;
	    long long int ans = 1;
	    for(int i = 0; i < n; i++)
	    {
	        ans *= arr[i];
	        maxi1 = max(maxi1, ans);
	        if(ans == 0) ans = 1;
	    }
	    ans = 1;
	    for(int i = n - 1; i >= 0; i--) 
	    {
	        ans *= arr[i];
	        maxi2 = max(maxi2, ans);
	        if(ans == 0) ans = 1;
	    }
	    return max(maxi1, maxi2);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends