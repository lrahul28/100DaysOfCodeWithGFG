// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// Project Manager finding the minimum time that takes to complete all the modules

 // } Driver Code Ends
class Solution{
    public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        queue<int> q;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++)
        {
            adj[dependency[i].first].push_back(dependency[i].second);
        }
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++)
        {
            for(auto it : adj[i]) indegree[it]++;
        }
        vector<int> timeReq(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                timeReq[i] = duration[i];
            }
        }
        int numOfNodes = 0;
        while(!q.empty())
        {
            int node = q.front();
            numOfNodes++;
            q.pop();
            for(auto it : adj[node])
            {
                indegree[it]--;
                timeReq[it] = max(timeReq[it], duration[it] + timeReq[node]);
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(numOfNodes != n) return -1;
        return *max_element(timeReq.begin(), timeReq.end());
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends