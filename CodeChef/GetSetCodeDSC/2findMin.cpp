#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int minsum = INT_MAX;

        int lo = 1, hi = n-1;
        while(lo < hi) {
            if(lo*hi == n){
                minsum = min (minsum, lo+hi);
                lo++;
                hi--;
            }

            else if (lo*hi > n) hi--;
            else lo++;
        }
        cout<<minsum<<endl;
    }
    return 0;
}