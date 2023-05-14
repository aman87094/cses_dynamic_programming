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
 
    int n;
    cin >> n;
    int M = 1e9 + 7;
    vector<ll> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if(i==j)dp[i]=dp[i]+1;
            else if (i - j >= 0)
            {
                dp[i] = dp[i] + dp[i - j] ;
                dp[i] %= M;
            }
        }
    }
    cout << dp[n] << endl;
 
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