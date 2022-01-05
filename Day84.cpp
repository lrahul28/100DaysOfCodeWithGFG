#include <bits/stdc++.h>
using namespace std;
// Triplets with a given sum
 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findTriplets(int Arr[], int N, int target)
    {
        sort(Arr, Arr + N);
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            int l = i + 1;
            int h = N - 1;
            while(l < h)
            {
                int sum = Arr[i] + Arr[l] + Arr[h];
                if(sum > target) h--;
                else
                {
                    ans += (h - l);
                    l++;
                }
            }
        }
        return ans;
    }
    int countTriplets(int Arr[], int N, int L, int R) {
        
        int c1 = findTriplets(Arr, N, R);
        int c2 = findTriplets(Arr, N, L - 1);
        return c1 - c2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends