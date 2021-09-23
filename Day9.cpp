#include<bits/stdc++.h>
using namespace std;
int largestPower(int n)
    {
        int x = 0;
        while(1 << x <= n) x++;
        return x - 1;
    }
    int countSetBits(int n)
    {
        if(n <= 0) return 0;
        int c = 0;
        int p = largestPower(n);
        c = p * pow(2, p) / 2 + (n - pow(2, p) + 1) + countSetBits(n - pow(2, p));
        return c;
    }
int main()
{
#ifndef IO_HANDLE
    freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/input.txt", "r", stdin);
    freopen("C:/Users/Rahul/OneDrive/Desktop/Sublime Text 3/Packages/User/output.txt", "w", stdout);
#endif  
    int n;
    cin >> n;
    cout << countSetBits(n);
}