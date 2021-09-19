//Median of two Sorted Arrays TC - O(log(min(m, n)))
#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &array1, vector<int> &array2)
{
	if(array1.size() > array2.size()) return findMedian(array2, array1);
	int m = array1.size(), n = array2.size();
	int cut1, cut2;
	int l1, l2, r1, r2;
	int l = 0, h = m;
	int len = m + n;
	while(l <= h)
	{
		cut1 = (l + h) / 2;
		cut2 = (len + 1) / 2 - cut1;
		l1 = cut1 == 0 ? INT_MIN : array1[cut1 - 1];
		l2 = cut2 == 0 ? INT_MIN : array2[cut2 - 1];
		r1 = cut1 == m ? INT_MAX : array1[cut1];
		r2 = cut2 == n ? INT_MAX : array2[cut2];
		if(l1 <= r2 and l2 <= r1)
		{
			if(len % 2 == 0) return (double)(max(l1, l2) + min(r1, r2)) / 2;
			return max(l1, l2);
		}
		else if(l1 > r2)
		{
			h = cut1 - 1;
		}
		else if(l2 > r1)
		{
			l = cut1 + 1;
		}
	}
	return -1;

}
int add()
{
	return 10;
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
		int m, n;
		cin >> m >> n;
		vector<int> array1(m);
		vector<int> array2(n);
		for(int i = 0; i < m; i++) cin >> array1[i];
		for(int i = 0; i < n; i++) cin >> array2[i];
		cout << findMedian(array1, array2);

}