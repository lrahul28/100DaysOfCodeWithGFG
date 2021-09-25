// Check if the tree formed by the given preorder, inorder, postorder is unique
//TC = O(N ** 2)


#include<bits/stdc++.h>
using namespace std;
bool checktree(int preorder[], int inorder[], int postorder[], int n) 
    { 
        if(n == 0) return true;
        if(n == 1) return((preorder[0] == inorder[0]) && (postorder[0] == inorder[0]));
        
        int index = -1;
        for(int i = 0; i < n; i++)
        {
            if(preorder[0] == inorder[i])
            {
                index = i;
                break;
            }
        }
        
        if(index == -1) return false;
        if(preorder[0] != postorder[n - 1]) return false;
        bool isLeft = checktree(preorder + 1, inorder, postorder, index);
        if(!isLeft) return false;
        bool isRight = checktree(preorder + index + 1, inorder + index + 1, postorder + index, n - index - 1);
        if(!isRight) return false;
        return true;
        
    }
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	




}