#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    int price[n];
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n+ 1, vector<int>(x + 1, 0));

    //edge case if i have money=i than how many pages can i buy if i take only the first book(index=0)
    // if(price of book at index 0 is less than money i have than i can't buy so pages=0 otherwise pages =pages[0])
    for (int i = 0; i <= x; i++)
    {
        if(i-price[0]>=0){
            dp[0][i]=pages[0];
        }
    }
    //dp state dp[i][j] tha max amount of pages i have till index i and money=j;
    //tansition : either we take the current book or not take the current book
    // dp[i][j]=dp[i-1][j] not taking the current book
    // dp[i][j]=dp[i-1][j-price[i]]+pages[i] for taking of currnt book
    // take the max of the two above at each step for finding answer.
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j<=x; j++)
        {
            dp[i][j]=dp[i-1][j];// not taking the current index
            if(j-price[i]>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-price[i]]+pages[i]);// taking max. of not taken and taken current index
            }
        }
        
    }

    cout << dp[n-1][x] << endl;
    return 0;
}