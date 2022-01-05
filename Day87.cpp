// Max XOR subset
 // } Driver Code Ends
class Solution{
	public:
	int maxXor(int arr[], int n)
	{
		// Your code goes here
        int index = 0;
        
        for(int i=31; i>=0; i--){
            int maxElement = INT_MIN;
            int maxIndex = index;
            // find max element with set bit at i th bit position
            // because xor cannot be less than maxElement
            for(int j=index; j<n; j++){
                int isSetBit = (arr[j]>>i)&1;
                if(isSetBit && maxElement<arr[j]){
                    maxElement = arr[j];
                    maxIndex = j;
                }
            }
            
            if(maxElement == INT_MIN){
                continue;//no use of this position as maxElement is not yeilding from this pos
            }
            
            swap(arr[index],arr[maxIndex]);//swap maxElement to curleft
          
            maxIndex = index;
            
            //change all elements by xoring with maxElement that has setBit at ith bit position
            //setting with 0s in bit postions of all numbers except currnet maxElement at ith bit Postion
            //useful for getting final ans
            for(int j=0; j<n; j++){
                int isSetBit = (arr[j]>>i)&1;
                if(isSetBit && j!=maxIndex){
                    arr[j] = arr[j]^maxElement;
                }
            }
            
            index += 1;
            
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = res^arr[i];
        }
        return res;
	

	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxXor(a, n) << "\n";
   
    }
    return 0;
}
  // } Driver Code Ends