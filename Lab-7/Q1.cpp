#include <bits/stdc++.h>
using namespace std;

int maximum_cost_greedy(int max_weight, vector<int> &weights, vector<int> &values){
    int n = weights.size(), ans = 0;
    vector<int> items(n);
    iota(items.begin(), items.end(), 0);
    sort(items.begin(), items.end(), [&](int a, int b){
        return values[a]/weights[a] < values[b]/weights[b];
    });
    for(auto i:items){
        if(weights[i] >= max_weight){
            ans += values[i];
            max_weight -= weights[i];
        }
    }
    return ans;
}

int maximum_cost(int max_weight, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> dp(max_weight+1);
    for(int i=0; i<n; i++)
        for(int j=max_weight; j>=weights[i]; j--)
            dp[j] = max(dp[j], dp[j-weights[i]]+values[i]);
    return dp[max_weight];
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, max_weight; cin >> n >> max_weight;
        vector<int> weights(n), values(n);
        for(int i=0; i<n; i++) cin >> weights[i];
        for(int i=0; i<n; i++) cin >> values[i];
        cout << maximum_cost(max_weight, weights, values) << endl;
    }
}