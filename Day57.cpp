#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* findMid(Node *head)
    {
        Node *slow = head, *fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    Node* reverse(Node *head)
    {
        Node *prev = head;
        Node *curr = head -> next;
        Node *nex = curr -> next;
        while(curr != NULL)
        {
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
        
    }
    bool isPalindrome(Node *head)
    {
        if(head == NULL) return false;
        if(head -> next == NULL) return true;
        if(head -> next -> next == NULL) return head -> data == head -> next -> data;
        Node *middle = findMid(head);
        Node *r = reverse(middle);
        Node *l = head;
        while(r != middle)
        {
            if(l -> data != r -> data) return false;
            r = r -> next;
            l = l -> next;
        }
        if(l -> data != r -> data) return false;
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends