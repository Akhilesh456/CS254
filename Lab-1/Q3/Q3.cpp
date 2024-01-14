#include <iostream>
#define int long long
using namespace std;

const int n = 4;

int adj[n][n] = {   
    { 0, 20, 42, 35 },
    { 20, 0, 30, 34 }, 
    { 42, 30, 0, 12 },
    { 35, 34, 12, 0 },
};

int dp[n][(1 << n)];

int func(int i, int s){
    if(dp[i][s] != 0)
        return dp[i][s];
    
    if(__builtin_popcount(s) == 2)
        return dp[i][s] = adj[0][i];
    
    int res = INT_MAX;
    for(int msk = 1; msk < n; msk++)
        if((s & (1 << msk)) && msk != i)
            res = min(res, func(msk, s ^ (1 << i)) + adj[msk][i]);
    return dp[i][s] = res;
}

signed main(){
    int ans = INT_MAX;
    for(int j=1; j<n; j++)
        ans = min(ans, func(j, (1 << n)-1) + adj[j][0]);
    cout << ans << endl;
}