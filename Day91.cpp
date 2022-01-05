#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string res = "";
        string temp = "";
        int flag = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] != '.')
            {
                temp = temp + s[i];
                if(i == 0) res = temp + res;
            }
            else 
            {
                temp = '.' + temp;
                res = temp + res;
                temp = "";
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends