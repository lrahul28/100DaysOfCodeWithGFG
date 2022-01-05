#include<bits/stdc++.h>
using namespace std;
// Rotten Oranges
 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int i, int j,int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
    
    pair<int, int> bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, queue<pair<int, pair<int, int>>> &q)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 0;
        int t = -1;
        while(!q.empty())
        {
            t = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int p = 0; p < 4; p++)
            {
                int xx = x + dx[p];
                int yy = y + dy[p];
                if(isValid(xx, yy, grid.size(), grid[0].size()) && visited[xx][yy] == 0 && grid[xx][yy] == 1)
                {
                    visited[xx][yy] = 1;
                    q.push({t + 1, {xx, yy}});
                    ans++;
                }
            }
        }
        
        return {t, ans};
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                
                if(grid[i][j] == 2 && !visited[i][j])
                {
                    q.push({0,{i, j}});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }
        pair<int, int> ans = bfs(grid, visited, q);
        if(ans.second == cnt) return ans.first;
        return -1;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends