#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
const ll MX = 1000000000;
using namespace std;

int main(){
    ll tt;    cin>>tt;
    while(tt--){
        ll n,m;    cin>>n>>m;
        ll arr[n][m],res=0;

        for(ll i=0;i<n;++i)    for(ll j=0;j<m;++j)    cin>>arr[i][j];

        vector<int> tmp;
        int t1,t2;

        for(ll i=0;i<n/2;++i){
            for(ll j=0;j<m/2;++j){
                if(arr[i][j]    ==    arr[n-i-1][j]    &&     arr[i][m-j-1]    ==    arr[n-i-1][m-j-1] && arr[i][j]    ==    arr[i][m-j-1])    continue;

                tmp.push_back(arr[i][j]);
                tmp.push_back(arr[n-i-1][j]);
                tmp.push_back(arr[i][m-j-1]);
                tmp.push_back(arr[n-i-1][m-j-1]);

                sort(tmp.begin(),tmp.end());

                t1=tmp[(tmp.size()-1)/2];
                for(auto it:tmp)    res+=abs(it-t1);

                arr[i][j]    =    arr[n-i-1][j]    =    arr[i][m-j-1]    =    arr[n-i-1][m-j-1]    =    t1;
                tmp.clear();
            }
        }

        if(n%2    !=    0){
            t1=0;    t2=m-1;
            while(t1<t2)    {res+=abs(arr[n/2][t1]-arr[n/2][t2]);    ++t1; --t2;}
        }
        if(m%2 !=    0){
                t1=0;    t2=n-1;
                while(t1<t2)    {res+=abs(arr[t1][m/2]-arr[t2][m/2]);    ++t1; --t2;}
        }

        cout<<res<<endl;
    }
    return 0;
}