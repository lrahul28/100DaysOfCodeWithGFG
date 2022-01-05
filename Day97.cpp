
 // } Driver Code Ends
//Possible paths between two vertices
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
void dfs(int v,vector<int>adj[],int src,int des,int&c){
      if(src == des){
          c++;
          return;
      }
      for(auto nbr:adj[src]){
          dfs(v,adj,nbr,des,c);
      }
      return;
  }
  
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int c =0;
        dfs(V,adj,source,destination,c);
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends