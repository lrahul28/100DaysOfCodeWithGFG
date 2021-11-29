// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// Count triplets But elements are present in the linked list.
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    vector<int> arr;
    int c = 0;
    while(head != NULL) 
    {
        arr.push_back(head -> data);
        
        head = head -> next;
    }
    for(int i = 0; i < arr.size(); i++)
    {
        int j = i + 1;
        int k = arr.size() - 1;
        while(j < k)
        {
            
            int sum = arr[i] + arr[j] + arr[k];
            
            if(sum == x)
            {
                c++;
                j++;
            }
            else if(sum < x) j++;
            else if(sum > x) k--;
        }
    }
    return c;
} 