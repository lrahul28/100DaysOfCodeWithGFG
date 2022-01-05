#include<bits/stdc++.h>
using namespace std;
// Spiral Matrix
 // } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        vector<int> v;
        int left = 0, top = 0, bottom = n - 1, right = m - 1;
        int h = 0;
        while(h <= k and left <= right and top <= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                v.push_back(a[top][i]);
                
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                v.push_back(a[i][right]);
                
            }
            right--;
            if(top <= bottom)
            {    for(int i = right; i >= left; i--)
                {
                    v.push_back(a[bottom][i]);
                    
                }
                
            
            bottom--;
            }
            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    v.push_back(a[i][left]);
                    
                }
                
            
            left++;
            }
        }
        return v[k - 1];
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } Driver Code Ends