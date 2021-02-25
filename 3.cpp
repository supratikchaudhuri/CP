#include<bits/stdc++.h>
using namespace std;

#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define ll long long

void solve() {
    ll res = 0;
    long long a, b; cin >> a >> b;
    for(int i = 1; i < a; i++) {
        for(int j = 1; j < i; j++)
            if(i/j == i%j)
                res++;
    }
    cout<<res<<endl;;
}

int main() {
    BOOST;
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}