#include <bits/stdc++.h>
using namespace std;
// Encrypt the string(identical elements are replaced by the count of its occurence in hexa decimal)
 // } Driver Code Ends
class Solution {
  public:
    string hexConvert(int n)
    {
        string res = "";
        while(n != 0)
        {
            int temp = n % 16;
            n /= 16;
            if(temp >= 10) res += char('a' + temp - 10);
            
            else res += char('0' + temp);
        }
        return res;
    }
    string encryptString(string s) {
        string res = "";
        int count = 1;
        int n = s.length();
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                   
                res = res + s[i - 1];
                res = res + hexConvert(count);
                count = 1;
                
            }
        }
        res = res + s[n - 1];
        res = res + hexConvert(count);
        for(int i = 0; i < res.length() / 2; i++)
        {
            swap(res[i], res[res.length() - i - 1]);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends