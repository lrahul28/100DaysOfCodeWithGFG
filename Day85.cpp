#include<bits/stdc++.h>
using namespace std;

// Find maximum sum that is closest to 0
 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            int l = 0, h = n - 1;
            int res = arr[0] + arr[n - 1];
            int sum;
            sort(arr, arr + n);
            while(l < h)
            {
                sum = arr[l] + arr[h];
                if(sum == 0) return 0;
                if(abs(sum) < abs(res))
                {
                    res = sum;
                }
                if(abs(sum) == abs(res)) res = max(sum, res);
                if(sum < 0) l++;
                
                else h--;
                
            }
            return res;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends