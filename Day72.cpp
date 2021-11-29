// { Driver Code Starts
//Initial template for C++
//Minimum possible sum possible by forming two numbers from the array
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        string n1, n2;
        sort(arr, arr + n, greater<int>());
        string res;
        int carry = 0;
        for(int i = 0; i < n; i += 2)
        {
            int s = arr[i] + carry;
            if(i + 1 < n)
            {
                s += arr[i + 1];
                
            }
            carry = s / 10;
            res += to_string(s % 10);
        }
        if(carry) res += "1";
        int i = res.length() - 1;
        while(!res.empty() and res[res.length() - 1] == '0') res.pop_back();
        reverse(res.begin(), res.end());
        
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends