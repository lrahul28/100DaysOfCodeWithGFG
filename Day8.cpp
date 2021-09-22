//Minimum no of times A should be repeated such that B becomes its Substring
//TC - O(|a| * |b|)
#include<bits/stdc++.h>
using namespace std;
bool isSubString(string rep1, string str2)
{
	int M = str2.length();
	int N = rep1.length();
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++)
			if (rep1[i + j] != str2[j])
				break;

		if (j == M) 
			return true;
	}

	return false; // not a substring
}
int repeatedStringMatch(string a, string b)
{
	string s = a;
	int ans = 1;
	while(s.size() < b.size())
	{
		s += a;
		ans++;
	}
	if(isSubString(s, b)) return ans;
	if(isSubString(s + a, b)) return ans + 1;

	return -1;
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	string a, b;
	cin >> a >> b;
	cout << repeatedStringMatch(a, b);
}