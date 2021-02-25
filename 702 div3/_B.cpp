#include<bits/stdc++.h>
using namespace std;

#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
#define ll long long

// Note that the numbers in the a array are not important to us, so initially we will calculate the values of c0, c1, c2. Now applying a move for the number ai is equivalent to:

// decreasing cai mod 3 by 1;
// and increasing c(ai+1) mod 3 by 1;
void solve() {
    int n; cin >> n;
    int arr[n];
    vector<int> rem(3);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        rem[arr[i]%3]++;
    }
    int want = n/3, res = 0;
    while(*min_element(rem.begin(), rem.end()) != want) {
        for(int i = 0; i <= 2; i++) {
            if(rem[i] > want) {
                rem[i]--;
                rem[(i+1)%3]++;
                res++;
            }
        }
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