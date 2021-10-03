//Vertical Order Traversal of a Tree 
//
#include<bits/stdc++.h>
using namespace std;

vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> node;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            auto i = q.front();
            Node *p = i.first;
            node[i.second.first][i.second.second].push_back(p -> data);
            if(p -> left != NULL) q.push({p -> left, {i.second.first - 1, i.second.second + 1}});
            if(p -> right != NULL) q.push({p -> right, {i.second.first + 1, i.second.second + 1}});
            q.pop();
        }
        vector<int> ans;
        for(auto it : node)
        {
            for(auto st : it.second) ans.insert(ans.end(), st.second.begin(), st.second.end());
        }
        return ans;
    }

int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	

	verticalOrder(root);

}