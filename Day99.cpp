#include<bits/stdc++.h>
using namespace std;
// Maximum sum after K negations
 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
        sort(arr,arr+n);
        
        int i=0;
        
        long long int sum=0,minimum=INT_MAX;
        while(i<n ){
            
            if(arr[i]<0 && k>0){
                arr[i]=-arr[i];
                k--;
                
            }
              minimum=min(arr[i],minimum);
             
             sum+=arr[i];
             i++;
            
        }
       
       if(k>0 && k%2!=0)
       sum=sum-minimum-minimum;
       
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends