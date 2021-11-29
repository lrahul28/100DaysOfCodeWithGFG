//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution {
    int dfs(vector<vector<int>>&graph, vector<vector<long>>&dp, int cur, int target, int k) {
        if(dp[cur][k] != -1) {
            return dp[cur][k];
        }
        dp[cur][k] = 0;
        for(int i=0; i<graph.size(); i++) {
            if(graph[cur][i]) {
                dp[cur][k] = (dp[cur][k] + dfs(graph, dp, i, target, k-1))%int(1e9+7);
            }
        }
        return dp[cur][k];
    }
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    vector<vector<long>> dp(graph.size(), vector<long>(k+1, -1));
	    dp[v][0] = 1;
	    for(int i=0; i<graph.size(); i++) {
	        if(i != v) dp[i][0] = 0;
	    }
	    dfs(graph, dp, u, v, k);
	    return dp[u][k];
	}
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends