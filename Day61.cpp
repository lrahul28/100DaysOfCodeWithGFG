// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    if(s.length() % 2 != 0) return -1;
    stack<char> st;
    int res = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{') st.push('{');
        else
        {
            if(st.empty())
            {
                st.push('{');
                res++;
            }
            else st.pop();
        }
    }
    if(!st.empty()) res += st.size() / 2;
    return res;
}