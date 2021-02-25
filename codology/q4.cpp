#include<bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
const ll MX = 1000000000;
using namespace std;

void funct(ll& a,ll& b, ll& c, ll i, ll val){
    if(i == 6)    {a+=val;b+=val;c+=val;}
    else if(i == 5)    {b+=val;c+=val;}
    else if(i == 4)    {a+=val;c+=val;}
    else if(i == 3)    {a+=val;b+=val;}
    else if(i == 2)    {c+=val;}
    else if(i == 1)    {b+=val;}
    else if(i == 0)    {a+=val;}
    else cout<<"N/A";
}

int main(){
    ll num; cin>>num;
    ll arr[7]    =    {3,5,7,8,10,12,15};
    ll a,b,c;    a=b=c=0;
    for(int i=0;i<=6;++i)    {
        for(int j=0;j<=6;++j){
            for(int k=0;k<=6;++k){
                if(((num%arr[i])%arr[j])%arr[k] == 0){
                    funct(a,b,c,i, floor(num/arr[i]));
                    num=num%arr[i];
                    funct(a,b,c,j, floor(num/arr[j]));
                    num=num%arr[j];
                    funct(a,b,c,k, floor(num/arr[k]));
                    num=num%arr[k];
                    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"-1\n";
    return 0;
}