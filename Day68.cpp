// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
//Longest Common prefix
class Solution{
public:
    vector<int> longestCommonPrefix(string str1, string str2){
        vector<int> res;
        int len = INT_MIN;
        int i, j;
        for(int i = 0; i < str2.size(); i++)
        {
            int j = 0, k = i;
            while(k < str2.size() && j < str1.size() && str2[k] == str1[j]) 
            {
                k++;
                j++;
            }
            len = max(j, len);
        }
        if(len == 0) return {-1, -1};
        return {0, len - 1};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string str1,str2;
        cin >> str1>> str2;
        Solution ob;
        vector<int> p;
        p = ob.longestCommonPrefix(str1,str2);
        if(p[0]==-1)
        cout<<"-1\n";
        
        else
        cout<<p[0]<<" "<<p[1]<<"\n";
    }
    return 0;
}
  // } Driver Code Ends