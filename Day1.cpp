// Sort an array of 0s, 1s and 2s TC - (O(N))
#include<bits/stdc++.h>
using namespace std;
void sort012(vector<int> &a)
{
	int n = a.size();
	int l = 0, h = n - 1;
	int mid = 0;
	while(mid <= h)
	{
		if(a[mid] == 1) mid++;
		else if(a[mid] == 0)
		{
			swap(a[mid], a[l]);
			l++;
			mid++;
		}
		else 
		{
			swap(a[mid], a[h]);
			h--;
		}
	}

}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/AppData/Roaming/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/AppData/Roaming/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	sort012(v);
	for(int x : v) cout << x << " ";


}