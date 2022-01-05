//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    //Function to find list of all words possible by pressing given numbers.
    
    void findPossibleWords(int a[], int N, int ind, vector<string> v, string &ans, vector<string> &res)
    {
        if(a[ind] == 1 or a[ind] == 0) return;
        for(int i = 0; i < v[a[ind] - 2].size(); i++)
        {
            
            ans += v[a[ind] - 2][i];
            if(ans.length() == N)
            {
                res.push_back(ans);
                ans.pop_back();
                
            }
            if(ind + 1 < N) findPossibleWords(a, N, ind + 1, v, ans, res);
        }
        if(ans.length()) ans.pop_back();
        return;
        
        
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> v;
        v.push_back("abc");
        v.push_back("def");
        v.push_back("ghi");
        v.push_back("jkl");
        v.push_back("mno");
        v.push_back("pqrs");
        v.push_back("tuv");
        v.push_back("wxyz");
        vector<string> res;
        string ans = "";
        findPossibleWords(a, N, 0, v, ans, res);
        return res;
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends