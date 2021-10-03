#include<bits/stdc++.h>
using namespace std;
 	bool cycleBFS(int s, vector<int> &adj[], vector<int> &visited, queue<pair<int, int>> q)
    {	
		if(q.empty()) q.push({s, -1});
		visited[s] = 1;
		while(!q.empty())
		{
			int parent = q.front().second;
			int node = q.front().first;
			q.pop();
			for(auto it : adj[node])
			{
				if(!visited[it])
				{
					visited[it] = 1;
					q.push({it, node});
				}
				else
				{
					if(parent != it) return true;
				}

			}


		}
		return false;
        
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(V + 1, 0);
        queue<pair<int, int>> q;
        for(int i = 0; i < v; i++)
        {
        	if(!visited[i])
        		if(cycleBFS(i, adj, visited, q)) return true;
        }
        return false;
    }
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	
	isCycle(v, g);
}