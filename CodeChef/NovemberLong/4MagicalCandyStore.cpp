#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int

void my(){
 ll n; cin>>n;
 vector<ll>r(n);
 vector<ll>p(n);
 for(int i=0;i<n;i++)
  cin>>r[i];

 ll res = 0;
 bool flg =false;
 
 if(r[0] == 1 && n>1)
  flg = true;
 else{

  for(int i=0;i<n-1;i++){
   if(r[i]==1){
    if(r[i-1]&1==1)
     p[i] = p[i-1];
    else
     p[i] = p[i-1] +1;

   }
   else if(r[i+1]==1 && i<n-2){
    if(r[i]&1==1){
     res += r[i];
     p[i] = res;
    }
    else{
     p[i] = res + r[i];
     res += r[i] - 1;
    }
   }
   else if(r[i]&1==1){
    p[i] = res + r[i];
    res += r[i] - 1;
   }
   else{
    res += r[i];
    p[i] = res;
   }
  }
  if(r[n-1]&1==1){
   res += r[n-1];
   p[n-1] = res;
  }
  else{
   p[n-1] = res + r[n-1];
   res += r[n-1] - 1;

  }
 }

 ll q; cin>>q;
 while(q--){
  ll r; cin>>r;
  ll div = r/n;
  ll rem = r%n;

  if(flg == true){
   if(div==0&&rem==1){
    cout<<1<<"\n"; continue;
   }
   if(rem>1){
    ll ans = (div+1)%M;
    cout<<ans<<"\n";
   }
   else{ ll ans = div%M;
    cout<<ans<<"\n";
   }
   continue;
  }
  if(div == 0)
   cout<<p[rem-1]%M<<"\n";
  else{
   if(rem == 0){
    ll ans = (((div - 1)*res) + p[n-1])%M;
    cout<<ans<<"\n";
   }
   else{
    ll ans  = (((div)*res) + p[rem-1])%M;
    cout<<ans<<"\n";
   }
  }
 }

}

int main(){
 ios::sync_with_stdio(false);
 cin.tie(0); cout.tie(0);

 //#ifndef ONLINE_JUDGE 
     //freopen("input.txt", "r", stdin); 
     //freopen("output.txt", "w", stdout);
 //#endif
 
 ll t; cin>>t;
 
 while(t--)
  my();

    return 0;
}

// Chef and Chefu are at a magical candy store playing a game with the following rules:

// There are two candy counters; each of them stores an infinite number of candies. At any time, only one of the counters is open and the other is closed.
// Exactly one player is present at each of the counters. Initially, Chef is at the open counter and Chefu is at the closed counter.
// There is a sequence of N distinct integers A1,A2,…,AN. The game consists of R turns; in the i-th turn, the open counter offers only C=A(i−1)%N+1 candies to the player present at this counter. This player should choose a positive number of candies M to accept, where 1≤M≤C.
// If this player accepts an odd number of candies, the players have to swap their positions (each player goes to the other counter).
// After each N turns, the counter which was currently open is closed and the counter which was currently closed is opened.
// The primary goal of each player is to maximise his own number of candies after R turns. As a second priority, each player wants to minimise the number of candies his opponent has after R turns.
// You should process Q queries. In each query, you are given R and you should find the number of candies Chef has after R turns, assuming that both players play the game optimally. Since this number could be very large, compute it modulo 109+7.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-separated integers A1,A2,…,AN.
// The third line contains a single integer Q.
// Each of the next Q lines contains a single integer R describing a query.
// Output
// For each query, print a single line containing one integer ― the maximum number of candies Chef can get, modulo 109+7.

// Constraints
// 1≤T≤25
// 1≤N≤105
// 1≤Ai≤109 for each valid i
// A1,A2,…,AN are pairwise distinct
// 1≤Q≤105
// 1≤R≤1012
// the sum of N+Q over all test cases does not exceed 106