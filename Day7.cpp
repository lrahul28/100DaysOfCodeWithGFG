//Dam of candies
//Given a vector of candies find the maximum no of candies you can store in
// between the books
//TC - O(N) SC - O(1)

#include<bits/stdc++.h>
using namespace std;
int maxCandy(vector<int> v, int n)
{
	int i = 0, j = n - 1;
	int maxLen = INT_MIN;
	while(i < j)
	{

		maxLen = max(maxLen, (j - i - 1) * min(v[i], v[j]));
		if(v[i] < v[j]) i++;
		else j--;
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
	cout << maxCandy(v, n);

}