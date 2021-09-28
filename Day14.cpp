// Sort a stack such that the top of the stack is always the greatest
// O(N**2)
#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int v)
{
	if(s.top() <= v or s.empty())
	{
		s.push(v);
		return;
	}
	int a = s.top();
	s.pop();
	insert(s, v);
	s.push(a);
}
void sortStack(stack<int> &s)
{
	if(s.size() <= 1) return;
	int a = s.top();
	s.pop();
	sortStack(s);
	insert(s, a);
}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	stack<int> s;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) 
	{
		int ele;
		cin >> ele;
		s.push(ele);
	}

	sortStack(s);
	



}