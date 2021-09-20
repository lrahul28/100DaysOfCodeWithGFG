//Factorial of Large Numbers
// TC - O(N * Digits) = O(N**2)
#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
	vector<int> res;
	res.push_back(1);
	int ans, carry = 0;
	if(n == 1 or n == 0) return res;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < res.size(); j++)
		{
			ans = res[j] * i + carry;
			res[j] = ans % 10;
			carry = ans / 10;
		}
		while(carry)
		{
			res.push_back(carry % 10);
			carry = carry / 10;
		}
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
	vector<int> res = factorial(n);
	for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
}