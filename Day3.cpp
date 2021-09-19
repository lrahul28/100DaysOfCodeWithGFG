//Find kth element after merging two sorted Arrays TC : O(log(min(m, n)))
#include<bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
	// If second vector is small doing binary search on second array
	if(arr2.size() < arr1.size()) findKthElement(arr2, arr1, m, n, k);
	
	/*
	EdgeCase1 - If we pick 0 from 1st vector we make sure
	that we have enough elements in the 2nd vector if not we take
    those many elements from the first array
    
    Example :- k = 6
    2 5 7 8 
    1 6 7 8 9 
    If l = 0
    Then even by taking all elements from second vector we cannot get enough 
    elements.
	EdgeCase2 :- If k is less than the size of the array we are searching 
	1 2 3 4 
	3 4 6 7 8
	k = 3
	v1.size() = 4
	so h will be equal to 3 since the size is less than the size of vector
	*/

	int l = max(0, k - m); //EdgeCase1

	int h = min(k, n); // EdgeCase2
	while(l <= h) // Binary search on choosing number of elements
	{
		int cut1 = (l + h) / 2; 
		int cut2 = k - cut1; // Cut2 = remaining elements to choose from 2nd vector
/*
		#EdgeCase3
		If there are no elements before cut 1 or cut 2 i.e. cut1 = 0 
		and cut 2 = 0 
		We have to make sure that the l1 and l2 are assigned to least possible values
		l1 = INT_MIN
		l2 = INT_MIN
		and viceversa the right values are to be assigned with greatest possible value
*/

		int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
		int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
		int r1 = cut1 == n ? INT_MAX : arr1[cut1];
		int r2 = cut2 == m ? INT_MAX : arr2[cut2];
		//If the selected partition forms a sorted list
		if(l1 <= r2 and l2 <= r1)
		{
			return max(l1, l2);
		}
		//Else we have reduce l1 and increase r2
		else if(l1 > r2) h = cut1 - 1;
		//Else we have reduce l2 and increase r1
		else if(l2 > r1) l = cut1 + 1;
	}
	return -1;
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v1(n);
	vector<int> v2(m);
	for(int i = 0; i < n; i++) cin >> v1[i];
	for(int i = 0; i < m; i++) cin >> v2[i];
	cout << findKthElement(v1, v2, n, m, k);
}