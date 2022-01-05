#include <bits/stdc++.h>
using namespace std;
// a^b for large numbers
 // } Driver Code Ends
class Solution {
  public:
    int getLastDigit(string a, string b) {
        int n = b.size();
       if(b == "0") return 1;
       int base = a.back()-48;
       int power = stoi((n == 1) ? b : b.substr(n-2, n));
       power %= 4;
       
       unordered_map<int,vector<int>>mp;
       mp.insert({0,  {0,0,0,0}});
       mp.insert({1,  {1,1,1,1}});
       mp.insert({2,  {2,4,8,6}});
       mp.insert({3,  {3,9,7,1}});
       mp.insert({4,  {4,6,4,6}});
       mp.insert({5,  {5,5,5,5}});
       mp.insert({6,  {6,6,6,6}});
       mp.insert({7,  {7,9,3,1}});
       mp.insert({8,  {8,4,2,6}});
       mp.insert({9,  {9,1,9,1}});
       
       return mp[base][(power == 0) ? 3 : power-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}  // } Driver Code Ends