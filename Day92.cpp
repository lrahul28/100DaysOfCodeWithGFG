#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
     queue<int> st;
     int i = 0, j = 0;
     vector<long long> ans;
     int n = N;
     while(j < N)
     {
        if(j - i >= K)
        {
            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.front());
            
            if(!st.empty() && A[i] == st.front())
            {
                st.pop();
            }
            i++;
        }
        else
        {
            if(A[j] < 0) 
            {
                st.push(A[j]);
            }
            j++;
        }
     }
     if(st.empty()) ans.push_back(0);
     else ans.push_back(st.front());
     return ans;
     
 }