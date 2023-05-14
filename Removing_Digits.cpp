#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    for (int i = 0; i <= min(n + 1, 9); i++)
    {
        dp[i] = 1;
    }

    for (int i = 10; i <= n; i++)
    {
        set<int> st1;
        int n1 = i;
        while (n1 > 0)
        {
            st1.insert(n1 % 10);
            n1 = n1 / 10;
        }
        for (int j = 0; j <= 9; j++)
        {
            

            if (st1.find(j) != st1.end())
            {
                dp[i] = min(dp[i], 1 + dp[i - j]);
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}