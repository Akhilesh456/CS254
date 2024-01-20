#include <bits/stdc++.h>
using namespace std;

int median_position(vector<int> &a, int l, int r){
    if(l == r)
        return l;
    vector<int> b;
    for(int i=l; i <= r; i++)
        b.push_back(a[i]);
    sort(b.begin(), b.end());
    int mdv = b[(r-l+1)/2];
    for(int i=l; i<=r; i++)
        if(a[i] == mdv)
            return i;
}

int partition(vector<int> &a, int l, int r){
    int p = median_position(a, l, r);
    swap(a[p], a[r]);
    int piv = a[r];
    int lo = l;
    for(int i=l; i<r; i++){
        if(a[i] < piv)
            swap(a[i], a[lo++]);
    }
    swap(a[lo], a[r]);
    return lo;
}

void quick_sort(vector<int> &a, int l, int r){
    if(l >= r)
        return;
    int p = partition(a, l, r);
    quick_sort(a, l, p-1);
    quick_sort(a, p+1, r);
}

int main(){
    freopen("test_cases_Q6.txt","r",stdin);
    freopen("output_Q6.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        quick_sort(a, 0, n-1);
        cout << "Sorted Array: ";
        for(auto x:a)
            cout << x << " ";
        cout << endl;
    }
}