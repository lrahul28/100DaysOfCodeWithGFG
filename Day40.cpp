// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void uni(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(size[pu] < size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else 
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> wt;
        for(int i = 0; i < V; i++)
        {
            for(auto it : adj[i]) 
            {
                wt.push_back({it[1], {i, it[0]}});
            }
        }
    /*for(int i = 0; i < wt.size(); i++)
    {
        cout << wt[i].first << " " << wt[i].second.first << "-> " << wt[i].second.second;
        cout << endl;
    }*/
    DSU *dsu = new DSU(wt.size());
    sort(wt.begin(), wt.end());
    int wtg = 0;
    for(int i = 0; i < wt.size(); i++)
    {
        auto it = wt[i];
            if(dsu -> findParent(it.second.first) != dsu -> findParent(it.second.second))
            {
                wtg += it.first;
                dsu -> uni(it.second.first, it.second.second);
            }
        
    }
    return wtg;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends