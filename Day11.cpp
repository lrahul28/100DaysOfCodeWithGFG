// Maxmim subarray length with sum 0
// TC - O(NLogN)
#include<bits/stdc++.h>
using namespace std;
int maxLen(vector<int> &v, int n)
{
	map<int, int> mp;
	int maxLen = INT_MIN;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += v[i];
		if(sum == 0)
		{

		 maxLen = max(maxLen, i + 1);
		}
		if(mp.find(sum) != mp.end())
		{
			maxLen = max(maxLen, i - mp[sum]);
			
		}

		else mp[sum] = i;
	}

	return maxLen;

}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	cout << maxLen(v, n);

}