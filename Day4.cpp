//Given an array and few queries find the sum from the
//given start and end range of all the queries
// TC - O(N)
// SC - O(N)
#include<bits/stdc++.h>
using namespace std;
vector<int> sumQuery2(vector<int> &arr, vector<int> &queries)
{
		unordered_map<int, int> mp;
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            mp[i] = sum;
        }
        vector<int> res;
        for(int i = 0; i < queries.size(); i += 2)
        {
            res.push_back(mp[queries[i + 1] - 1] - mp[queries[i] - 2]);
        }
        return res;
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
	int q;
	cin >> q;
	vector<int> query(2 * q);
	for(int i = 0; i < 2 * q; i++) cin >> query[i];
	vector<int> res = sumQuery2(v, query);
	for(int x : res) cout << x << "\n";


}