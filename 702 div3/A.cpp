#include<bits/stdc++.h>
using namespace std;

#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define ll long long

void solve() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 0;
    int prev = arr[0];
    for(int i = 1; i < n; i++) {
        int a = min(prev, arr[i]), b = max(prev, arr[i]);

        while(a * 2 < b) {
            res++;
            a *= 2;
        }
        prev = arr[i];
    }
    cout<<res<<endl;
}

int main() {
    BOOST;
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}