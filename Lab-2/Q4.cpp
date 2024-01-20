#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("test_cases_Q4.txt","r",stdin);
    freopen("output_Q4.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        if(n%2)
            cout << "Median: " << a[n/2] << endl;
        else
            cout << setprecision(15)<< "Median: " << (a[n/2-1]+a[n/2])/2.0 << endl;
    }
}