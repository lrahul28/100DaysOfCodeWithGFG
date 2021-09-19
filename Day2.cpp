//N meetings - Given start and end time of various meetings find the
//maximum rooms required for the given set of meetings 
//TC - (O(N + NLogN + N))
//SC - (O(N));
#include<bits/stdc++.h>
using namespace std;
int findMaximumRooms(vector<int> &start, vector<int> &end, int n)
{
	vector<pair<int, int>> p;
	for(int i = 0; i < n; i++)
	{
		p.push_back({end[i], start[i]});
	}
	int c = 1;
	sort(p.begin(), p.end());
	int currend = p[0].first;
	for(int i = 1; i < n; i++)
	{
		if(p[i].second > currend) 
		{
		  c++;
		  currend = p[i].first;
		}

	}
	return c;
} 
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/AppData/Roaming/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/AppData/Roaming/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	int n;
	cin >> n;
	vector<int> start(n);
	vector<int> end(n);
	for(int i = 0; i < n; i++) cin >> start[i];
	for(int i = 0; i < n; i++) cin >> end[i];
	cout << findMaximumRooms(start, end, n);
}