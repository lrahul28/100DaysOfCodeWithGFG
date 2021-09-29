// Restricted PACMAN
#include<bits/stdc++.h>
using namespace std;

int findAns(int m, int n)
{
	vector<bool> dp(m * n + 1);
	dp[0] = true;
	int ans = 0;
	for(int i = 1; i < dp.size(); i++)
	{
		if(i >= m) dp[i] = dp[i] | dp[i - m];
		if(i >= n) dp[i] = dp[i] | dp[i - n];
		if(!dp[i]) ans++;
	}
	return ans;


}

int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	cout << findAns(2, 5);


}