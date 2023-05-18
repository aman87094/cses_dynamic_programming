#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
    // state : dp[i][j]=no of operation needed for making string a of length i equal to string b of length j
    for (int i = 0; i <=n; i++)
    {
        dp[i][0]=i;//base case when length of one string is 0 then the no of oeration 
                   // needed for making one string equal to another
    }
    for (int j = 0; j <=m; j++)
    {
        dp[0][j]=j;//base case when length of one string is 0 then the no of oeration 
                   // needed for making one string equal to another
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));//deleting and inserting create same condition
                                                                        // while in replacing dp[i][j]=dp[i-1][j-1]
            }
        }
    }
    
    cout<<dp[n][m]<<endl;

    return 0;
}