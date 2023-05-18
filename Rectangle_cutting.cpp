#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    // state : dp[i][j]=min no of operation required for making squares from rectangle of size ixj.
    //transition : either cut along lenth wise or width wise 
    // for length wise dp[i][j]=dp[i-k][j]+dp[k][j]+1 iterating over all j, where k is dummy variable running over 1 to length 
    // similarly for breadth also.
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] =min(dp[i][j],1+dp[i][j-k]+dp[i][k]);//cutting widthwise.
                }
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] =min(dp[i][j],1+dp[i-k][j]+dp[k][j]);// cutting length wise.
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}