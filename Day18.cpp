#include<bits/stdc++.h>
using namespace std;
pair<int, int> KSortedRange(vector<vector<int>> &v, int k, int n)
{
	
	map<pair<int, int>, int> mp;
	pair<int, int> ans = {0, INT_MAX};
	for(int i = 0; i < k; i++)
		mp[{v[i][0], i}] = 0;
	while(true)
	{
		int minVal = (mp.begin() -> first).first;
		int maxVal = (mp.rbegin() -> first).first;
		int row = (mp.begin() -> first).second;
		int col = mp.begin() -> second;
		if(maxVal - minVal < ans.second - ans.first) ans = {minVal, maxVal};
		if(col + 1 == n) break;
		mp.erase(mp.begin());
		
		mp[{v[row][col + 1], row}] = col + 1;

	}
	return ans;

}

int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(k, vector<int>(n));
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n; j++) cin >> v[i][j];
	}
	
	pair<int, int> ans = KSortedRange(v, k, n);

	cout << ans.first << " " << ans.second;
}