#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n ;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }

    // dp state dp[i][j]=1 if sum j is possible using i element of the gvien array otherwise 0.
    vector<vector<int>> dp(n+1, vector<int>(500010, 0));// initialize all elements to zero.

    for (int i = 0; i <=n; i++)
    {
        dp[i][0]=1;// base case for all length of given coins array sum =0 is  always possible by not taking any element of the coins array
    }
    // dp transition 
    // dp[i][j]=dp[i-1][j-coins[i-1]] when we take the current element and adding the coin into current sum
    // dp[i][j]=dp[i][j]|| dp[i-1][j] when we don't take the current element so the possible sum till length n-1 is also possible till length n.
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <=500010; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-coins[i-1]>=0){
                dp[i][j]=dp[i-1][j-coins[i-1]] || dp[i-1][j];
            }
        }
    }
    int cnt=0;
    for (int i = 1; i <500010; i++)
    {
        if(dp[n][i]==1)cnt++;
    }
    cout<<cnt<<endl;
    
    //if dp[i][j]=1 means it is possible to make a sum j so printing that no.
    
    for (int i = 1; i < 500010; i++)
    {
        if(dp[n][i]==1)cout<<i<<" ";
    }
    cout<<endl;
    

    return 0;
}