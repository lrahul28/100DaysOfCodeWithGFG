// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        //code
        string res = "";
        int row_inc = (2 * n) - 2;
        int adj_col = 0;
        if(n == 1) return s;
        for(int i = 0; i < n; i++)
        {   
            int flag = 0;
            int j = i;
            while(j < s.length())
            {
                if(flag == 1 and adj_col != 0)
                {
                    
                    if(j < s.length()) res += s[j];
                    j = j + adj_col;
                    

                }
                else if(row_inc != 0)
                {   
                    if(j < s.length()) res += s[j]; 
                    j = j + row_inc;
                    
                }
                flag = !flag;
            }
            row_inc -= 2;
            adj_col += 2;
        }
        return res;
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends