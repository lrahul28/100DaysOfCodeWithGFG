// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
// Minimum no of swaps to make all the elements <= to K
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int window_size = 0;
        int ans;
        for(int i = 0; i < n; i++)
        {
           if(arr[i] <= k) window_size++;
        }
        int i = 0, j = 0;
        int req_element = 0;
        while(j < window_size)
        {
            if(arr[j++] <= k) req_element++;
        }
        ans = window_size - req_element;
        while(j < n)
        {
            if(arr[i] <= k) req_element--;
            if(arr[j] <= k) req_element++;
            ans = min(ans, window_size - req_element);
            i++;
            j++;
        }
        return ans;
        
        
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends