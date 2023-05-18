//--->WRITER : AMAN _XONE

;
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "/Users/amankumar/Documents/contest/debug.h"
#else
#define debug(...) 42
#endif
#define ll long long
#define endl "\n";
#define ld long double
const int N = 2e5 + 10;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
// typedef vector<vl>     vvl;
// typedef vector<vi>     vvi;
typedef vector<pl> vpl;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<int> vi;
vector<int> g[N];
bool sortByFirstThenSecond(pair<string, int> &a, pair<string, int> &b);

void dfs(int vertex, int par = 0)
{
    for (int child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        dfs(child, vertex);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
    vector<int>dp1(m+1,0);
    vector<int>dp2(m+1,0);
    if (arr[0] == 0)
    {
        for (int i = 0; i < m + 1; i++)
        {
            dp2[i]=1;
        }
    }
    else
    {
        dp2[arr[0]] = 1;
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            dp1[j]=0;
        }
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1&&k<=m)
                    {
                        // dp[i][j] += dp[i - 1][k];
                        // dp[i][j] %= int(1e9 + 7);
                        dp1[j]+=dp2[k];
                        dp1[j]%=int(1e9+7);
                    }
                }
            }
        }
        else
        {
            for (int k : {arr[i] - 1, arr[i], arr[i] + 1})
            {
                if (k >= 1&&k<=m)
                {
                    // dp[i][arr[i]] += dp[i - 1][k];
                    // dp[i][arr[i]] %= int(1e9 + 7);
                    dp1[arr[i]]+=dp2[k];
                    dp1[arr[i]]%=int(1e9+7);
                }
            }
        }
        dp2=dp1;
    }
    debug(dp1);
    // debug(n);
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp2[i];
        ans=ans%int(1e9+7);
    }
    cout << ans << endl;

    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
bool sortByFirstThenSecond(pair<string, int> &a, pair<string, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}