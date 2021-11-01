// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Solution{

 // } Driver Code Ends
	public:
	int sieve[100003];
	int N = 100003;
	void createSieve()
	{
	    for(int i = 2; i < N; i++)
	    {
	        sieve[i] = true;
	    }
	    for(int i = 2; i * i < N; i++)
	    {
	        for(int j = i * i; j < N; j += i)
	        {
	            sieve[j] = false;
	        }
	    }
	}
	int isCircularPrime(int n) {
	    createSieve();
	    int t = n;
	    int len = 0;
	    while(t)
	    {
	        t = t / 10;
	        len++;
	    }
	    int mul = 1;
	    for(int i = 0; i < len - 1; i++)
	    {
	        mul *= 10;
	    }
	    for(int i = 0; i < len; i++)
	    {   
	        int rem = n % 10;
	        int res = n / 10;
	        int ans = rem * mul + res;
	        if(sieve[ans] == false) return 0;
	        n = ans;
	    }
	    
	    return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends