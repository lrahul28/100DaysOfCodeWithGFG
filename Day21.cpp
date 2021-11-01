#include<bits/stdc++.h>
using namespace std;
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    vector<int> dfs(int node, vector<pair<int, int>> adj[], vector<int> &visited)
    {
        vector<int> temp;
        visited[node] = 1;
        stack<int> st;
        st.push(node);
        int mini = INT_MAX;
        temp.push_back(node);
        int curr;
        while(!st.empty())
        {
            node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                curr = it.first;
                int dia = it.second;
                if(!visited[curr])
                {
                    mini = min(dia, mini);
                    visited[curr] = 1;
                    
                    st.push(curr);
                }
            }
            if(st.empty()) temp.push_back(curr);
        }
        temp.push_back(mini);
        
        return temp;
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<pair<int, int>> adj[n + 2];
        vector<int> visited(n + 2, 0);
        int deg[n+2] = {0};
        for(int i = 0; i < p; i++)
        {
            int u = a[i];
            int v = b[i];
            int dia = d[i];
            adj[u].push_back({v, dia});
            deg[u]++;
            deg[v]++;
        }
        vector<int> tanks;
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 1 && adj[i].size() == 1)
            {
                tanks.push_back(i);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < tanks.size(); i++)
        {
            if(!visited[tanks[i]]) 
            {
             vector<int> temp = dfs(tanks[i], adj, visited);
             ans.push_back(temp);
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends