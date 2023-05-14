#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int coins[n];
    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<ll> dp(1000001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j - coins[i] >= 0)
            {
                dp[j] += dp[j - coins[i]];
                dp[j] %= M;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}