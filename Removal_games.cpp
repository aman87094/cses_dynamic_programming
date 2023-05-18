#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

int main()
{
   int n;
   cin>>n;
   ll arr[n];
   for (int i = 0; i < n; i++)
   {
        cin>>arr[i];
   }
    vector<vector<ll>>sum(n,vector<ll>(n,0)); //sum[i][j] storing the sum from index i to index j(both including).
    sum[0][0]=arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[0][i]=sum[0][i-1]+arr[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(i==j){
                sum[i][j]=arr[i];
            }
            else{
                sum[i][j]=sum[i][j-1]+arr[j];
            }
        }
    }

    // solution : 
    // state : dp[i][j] =max score that can be achieved by player playing currently from array starting at index i upto index j e.g. arr[i],arr[i+1],....,arr[j]
    // transition : the player who is currently playing choose the side left or right only based on max score he can get 
    //          dp[i][j]=max(arr[i]+sum[i+1][j]-dp[i+1][j],arr[j]+sum[i][j-1]-dp[i][j-1]) 
    //          dp[i][j]==arr[i] when i==j bcz there is only one element
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    for (int i = n-1; i >=0; i--)
    {

        for (int j = i; j < n; j++)
        {
            if(i==j){
                dp[i][j]=arr[i];
            }
            else{
                dp[i][j]=max(arr[i]+sum[i+1][j]-dp[i+1][j],arr[j]+sum[i][j-1]-dp[i][j-1]);
            }   
        }
    }
    cout<<dp[0][n-1]<<endl;
    
    

    return 0;
}