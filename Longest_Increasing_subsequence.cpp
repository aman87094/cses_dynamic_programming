#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;
//This code is someone's other code i was not able to complete this question on my own.

// dp[x] = minimum ending value of an increasing subsequence of length x+1, 
// using the elements considered so far.e add elements one by one from left to right. Say we want to add a new value v.


//  For this to be part of an increasing subsequence, the previous value in the 
//  subsequence must be lower than v. We might as well take the maximum length subsequence 
//  leading up to v, as the values don't matter for the continuation to the right of v. 
//  Therefore we need to extend the current longest increasing subsequence ending in a value
//   less than v. This means we want to find the rightmost element in the 
//   dp array (as the position corresponds to the length of the subsequence), 
//   with value less than v. Say it is at position x. We can put v as a new 
//   candidate for ending value at position x+1 (since we have an increasing subsequence 
//   of length x+1 + 1, which ends on v). Note that since x was the rightmost position with
//    value less than v, changing dp[x+1] to v can only make the value smaller (better), 
//    so we can always set dp[x+1] = v without checking if it is an improvement first.
// Time Complexity O(n.logn)
int main()
{
   int n;
   cin>>n; 
   vector<int>dp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        auto it =lower_bound(dp.begin(),dp.end(),x);
        if(it==dp.end()){
            dp.push_back(x);
        }else{
            *(it)=x;
        }
    }
    
    cout<<dp.size()<<endl;
    return 0;
}