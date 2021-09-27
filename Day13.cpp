//Find Middle element of a linked list

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node(int data)
	{
		this -> data = data;
		this -> next = NULL;
	}
};
int findMid(Node *head)
{

	Node *slow, *fast;
	slow = fast = head;
	while(fast != NULL and fast -> next != NULL)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow -> data;
}

int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	Node *head = new Node(1);
	head -> next = new Node(2);
	head -> next -> next = new Node(3);

	cout << findMid(head);
}