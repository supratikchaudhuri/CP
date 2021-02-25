#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pb push_back
 
using namespace std;

  
vector <ll> SieveOfEratosthenes(ll n) 
{ 

    bool prime[n+1]; 
    vector <ll> vect;
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 

        if (prime[p] == true) 
        { 

            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          vect.push_back(p);
    return vect;
} 

void its_Function(vector <ll> prime,ll n)
{
 vector<ll> vect(n);
 for(ll i =0;i<n;i++)
 {
     cin>>vect[i];
 }
 

 
 for(ll i =0;i<n;i++)
 {
     if(vect[i]!=i+1)
     {
         cout<<prime[vect[i]-1]<<" ";
     }
     else
     {
         cout<<prime[i]<<" ";
     }
 }

}
 
int main() 
{ 
    vector <ll> prime,vect2;
    prime = SieveOfEratosthenes(5000000); 
    ll t;
	cin>>t;
	while(t--)
	{
    ll n;
    cin>>n;
    vect2.assign(prime.begin(), prime.begin()+n);
    its_Function(vect2,n);
	cout<<"\n";
	}
    return 0; 
}


// Alice has a very complex machine ― when fed with a sequence A1,A2,…,AN, it produces a sequence B1,B2,…,BN, where for each valid i, Bi is the largest index j such that Ai divides Aj (since Ai divides itself, such an index always exist). For example, if the machine is fed with A=[2,6,5,3,4], it produces B=[5,2,3,4,5].

// Alice gave you a sequence B that was produced by the machine. Find an integer sequence A such that when it is fed into the machine, then the machine produces the sequence B. Alice does not like huge integers, so make sure that 1≤Ai≤4⋅106 holds for each valid i.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-separated integers B1,B2,…,BN.
// Output
// For each test case, print a single line containing N space-separated integers A1,A2,…,AN. For each valid i, 1≤Ai≤4⋅106 should hold.

// If there are multiple solutions, you may print any of them. It is guaranteed that at least one solution exists.

// Constraints
// 1≤T≤2⋅104
// 1≤N≤105
// 1≤Bi≤N for each valid i
// the sum of N over all test cases does not exceed 2⋅105