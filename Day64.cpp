// { Driver Code Starts
//Initial Template for C++
//Lucys Neighbour
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:

    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < arr.size(); i++)
        {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        
        vector<int> res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }       
    
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 



  // } Driver Code Ends