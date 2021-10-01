//IS BST
//
#include<bits/stdc++.h>
using namespace std;

    bool check(int low, int high, Node* root)
    {
        if(root == NULL) return 1;
        if(root -> data < low or root -> data > high) return 0;
        return check(low, root -> data, root -> left) && check(root -> data + 1, high, root -> right);
        
    }
    bool isBST(Node* root) 
    {
        return check(INT_MIN, INT_MAX, root);        
    }
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	isBST(root);

}