/*
	Matrix Exponentiation in something that is done to find 
	fibonacci sequence in Log(N) time complexity

	Simply its something that is done by
	[f(n)			
	,        =  [1 1  ^n-1 * 	[
	 f(n-1)		 1 0]  	 		f(1)
	 							f(0)
	]					     	]
	
	In this way we can find the power of the matrix {{1, 1}, {1, 0}}
	in Log(N) time complexity
	when the power gets multiplied with the base values of the fibonacci
	we get the final fibonacci in O(Log(N)) time

*/
#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
    void mul(long long int res[2][2], long long int mat[2][2])
    {
        int sum = 0;
        int a = ((res[0][0] * mat[0][0]) % mod) + ((res[0][1] * mat[1][0]) % mod);
        int b = ((res[0][0] * mat[0][1]) % mod) + ((res[0][1] * mat[1][1]) % mod);
        int c = ((res[1][0] * mat[0][0]) % mod) + ((res[1][1] * mat[1][0]) % mod);
        int d = ((res[1][0] * mat[0][1]) % mod) + ((res[1][1] * mat[1][1]) % mod);
        res[0][0] = a % mod;
        res[0][1] = b % mod;
        res[1][0] = c % mod;
        res[1][1] = d % mod;
        return;
    }
    void findPower(long long int res[2][2], long long int n)
    {
        if(n == 0 or n == 1) return;
        findPower(res, n >> 1);
        mul(res, res);
        long long int mat[2][2] = {{1, 1}, {1, 0}};
        if(n % 2 != 0)
            mul(res, mat);
        
    }
	int TotalAnimal(long long int n){
	    long long int res[2][2] = {{1, 1}, {1, 0}};
	    findPower(res, n);
	    return res[0][0];
	    
	}
int main()
{
#ifndef IO_HANDLE
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
	freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif	


	int n;
	cin >> n;
	cout << findNoOfCows(n);

}