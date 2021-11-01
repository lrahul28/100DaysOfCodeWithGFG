#include<bits/stdc++.h>
using namespace std;
int minEditDist(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        
        if(i == s.length()) return t.length() - j;
        if(j == t.length()) return s.length() - i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = minEditDist(s, t, i + 1, j + 1, dp);
        
        else return dp[i][j] = 1 + min(minEditDist(s, t, i, j + 1, dp), min(minEditDist(s, t, i + 1, j, dp), minEditDist(s, t, i + 1, j + 1, dp)));
           
    
    }
    int editDistance(string s, string t) {
        
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        
        return minEditDist(s, t, 0, 0, dp);
        
        
    }
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

}