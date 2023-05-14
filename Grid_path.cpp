#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n;
    cin>>n;
    char grid[n][n];
    vector<vector<int>>dp(n,vector<int>(n,0)); //dp table to fill the ans
    //dp state : dp[i][j] -> gives the non of ways to reach till i,j indexes from (0,0)
    // transition : dp[i][j]=dp[i-1][j]+dp[i][j-1]  only right and down movement is allowed 
    // Base case : 1. if grid[i][j]=='*' dp[i][j]=0 because we can't go there.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
        }
    }

    // Initialization
    if(grid[0][0]=='*')dp[0][0]=0;
    else dp[0][0]=1;
    //handling edge cases
    for (int i = 1; i < n; i++)
    {
        if(grid[0][i]!='*')
            dp[0][i]=dp[0][i-1];
        else dp[0][i]=0;
    }
    //handling edge cases
    for (int i = 1; i < n; i++)
    {
        if(grid[i][0]!='*')
            dp[i][0]=dp[i-1][0];
        else dp[i][0]=0;
    }
    
    //filling table using above mentioned transition
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(grid[i][j]=='*'){
                dp[i][j]=0;
            }
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=M;
        }
        
    }
    cout<<dp[n-1][n-1]<<endl;
    
    
    return 0;
}