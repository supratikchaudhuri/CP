// 1472A - Cards for Friends
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
void solve(){
    int w, h, n; cin >> w >> h >> n;
    ll count = 1;
    while(w % 2 == 0) {
        w /= 2;
        count *= 2;
    }
    while(h % 2 == 0){
        h /= 2;
        count *= 2;
    }
    if(count >= n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
 
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}