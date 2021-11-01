#include<bits/stdc++.h>
using namespace std;
int KMP(string s, string res)
{
	int n = res.size();
	int lps[n + 1];
	int i = 0, j = 1;
	lps[0] =  0;
	while(j < res.length())
	{
		if(res[i] != res[j])
		{
			
			if(i - 1 < 0) lps[j] = 0;
			else lps[j] = lps[i - 1];
			j++;
		}
		else
		{
			lps[j] = i + 1;
			i++;
			j++;
		}
	}
	i = 0, j = 0;
	int ans = 0;
	while(i < s.length())
	{
		
		if(res[j] == s[i])
		{
			i++;
			j++;
		}
		if(j == n) 
		{
			j = lps[j - 1];
			ans++;
		}
		else if(s[i] != res[j])
		{
			if(j > 0) j = lps[j - 1];
			else i++;

		}

	}
	return ans;
}
int maxFrequency(string s)
{
	int i = 0, j = s.length() - 1;
	string res = "";
	string pre = "";
	string suff = "";

	while(i <= j)
	{		
		pre = pre + s[i];
		suff = s[j] + suff;
		if(pre == suff) 
		{
				res = pre;
				break;
		}
		i++;
		j--;
	}
	int ans = KMP(s, res);
	return ans;
	
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	string s;
	cin >> s;

	cout << maxFrequency(s);

}