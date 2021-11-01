// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool findSol(string a, string b, string c, int i, int j, int k, vector<vector<int>> &dp)
    {
            
        if(i == a.length() && j == b.length() && k == c.length()) return 1;
        bool f = false;
        if(i < a.length() && c[k] == a[i]) f = f or findSol(a, b, c, i + 1, j, k + 1, dp);
        if(j < b.length() && c[k] == b[j]) f = f or findSol(a, b, c, i, j + 1, k + 1, dp);
        
        return f;
        
        
    }
    bool isInterleave(string A, string B, string C) 
    {
        int i = 0, j = 0, k = 0;
        vector<vector<int>> dp(A.length(),vector<int>(B.length(), -1));
        return findSol(A, B, C, i, j, k, dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends