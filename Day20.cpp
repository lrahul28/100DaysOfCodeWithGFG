#include<bits/stdc++.h>
using namespace std;
int findMaxDifference(string s)
{
	   int curr;
	    curr = -1;
	    if(s[0] == '0') curr = 1;
	    int maxi = curr;
	    for(int i = 1; i <= s.length(); i++)
	    {
	           if(s[i] == '0') curr = max(curr + 1, 1);
	           if(s[i] == '1') curr = max(curr - 1, -1);
	           maxi = max(maxi, curr);
	    }
	    return (maxi == 0)? -1 : maxi;
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	string s;
	cin >> s;
	cout << findMaxDifference(s);
}