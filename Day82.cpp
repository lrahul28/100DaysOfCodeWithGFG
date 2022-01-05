#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
// Find Duplicate rows in a matrix
class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> a, int r, int c) 
{ 
    // Your code here
    unordered_set<string> us;
    vector<int> ans;
    for(int i=0;i<r;i++){
        string s;
        for(int j=0;j<c;j++){
            s+=to_string(a[i][j]);
        }
        if(us.count(s)) 
            ans.push_back(i);
        else 
            us.insert(s);
    }
    return ans;  
} 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends