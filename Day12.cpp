#include<bits/stdc++.h>
using namespace std;
int search(string s, string pat)
{
	map<char, int> mp;
	
	for(int i = 0; i < pat.length(); i++) mp[pat[i]]++;

	int c = mp.size();
	
	int i = 0, j = 0;
	
	int ans = 0;
	while(j < s.length())
	{
		
		if(j - i < pat.length())
		{
			if(mp[s[j]] == 1)
			{
			 c--;
			 if(c == 0) 
			 	{
			 		ans++;
			 		cout << j << endl;
			 	}
			}
			mp[s[j]]--;
			j++;
		}
		else
		{

			if(mp[s[i]] == 0) 
			{
				c++;
				if(c == 0) ans++;
			}
			mp[s[i]]++;
			i++;
			
		}
	}
	return ans;

}

int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	string txt, pat;
	cin >> txt;
	cin >> pat;
	cout << search(txt, pat);
}