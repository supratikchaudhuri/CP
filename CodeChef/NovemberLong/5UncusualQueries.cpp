#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define all(x) (x).begin(),(x).end()

#define M 1000000007


int b[100001];
int a[100001];
int p[100001];
int n,q,si;
int stx=0;
struct fg
{
 int val,lazy,rc,lc;
}Node[5000000];

void s(int v,int p,int ch)
{
 
    if(ch==1)
       { Node[++stx]=Node[Node[p].rc];
        Node[p].rc=stx; 
       }
        else
      { Node[++stx]=Node[Node[p].lc];
        Node[p].lc=stx; 
       }
 
}


int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
  

void update(int v,int L,int R,int l,int r,int x)
{
 if(l==L&&r==R)
 {
   Node[v].lazy+=x;
   return;
 }
   else
   {  int mid=(L+R)/2;
 if(l>mid)
 {
 s(Node[v].rc,v,1);
 update(Node[v].rc,mid+1,R,l,r,x);
 }
    else if(r<=mid)
 {
 s(Node[v].lc,v,0);
 update(Node[v].lc,L,mid,l,r,x);
 }


    else 
 {
 s(Node[v].rc,v,1);
 s(Node[v].lc,v,0);
 update(Node[v].rc,mid+1,R,mid+1,r,x);
 update(Node[v].lc,L,mid,l,mid,x);
 }
 Node[v].val=max(Node[Node[v].rc].val+Node[Node[v].rc].lazy,Node[Node[v].lc].val+Node[Node[v].lc].lazy);

   }
}

int get(int v,int L,int R,int l,int r)
{   if(v==0)
    return 0;
 if(L==l&&R==r)
 return Node[v].val+Node[v].lazy;
    
    else
    {  int mid=(L+R)/2;
      if(l>mid)
      return get(Node[v].rc,mid+1,R,l,r)+Node[v].lazy;
      else if(r<=mid)
      return get(Node[v].lc,L,mid,l,r)+Node[v].lazy;
      else
      {
           return max(get(Node[v].rc,mid+1,R,mid+1,r)+Node[v].lazy,get(Node[v].lc,L,mid,l,mid)+Node[v].lazy);
      }
    }
}
int main()
{   int c;
    b[0]=0;
    p[0]=0;
 cin>>n>>q>>si;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    a[0]=100001;
    for(int i=1;i<=n;i++)
     {  
      c=i-1;
      while(a[c]<a[i])
      c=p[c];
      p[i]=c;
     }
     for(int i=1;i<=n;i++)
     {
     Node[b[i]=++stx]=Node[b[i-1]];
     update(b[i],1,n,p[i]+1,i,1);
     }
int l,r;
     if(si==0)
     {
        for(int i=1;i<=q;i++)
       { cin>>l>>r;
         if(r<l)
          swap(l,r);
        cout<<get(b[r],1,n,l,r)<<endl;}
     }
     else
     {  int last=0;

       for(int i=1;i<=q;i++)
        {cin>>l>>r;
          l=(l+last-1)%n+1;
          r=(r+last-1)%n+1;
          if(r<l)
          swap(l,r);
        last=get(b[r],1,n,l,r);
        cout<<last<<endl;}
     }
}


// There are N mountains in Chefland, arranged in a line and numbered 1 through N from left to right. For each valid i, the i-th mountain from the left has a height Hi.

// Chef wants to choose a contiguous sequence of mountains l,l+1,…,r and visit them in this order. He has a notebook where he writes down some heights of mountains. Initially, the notebook contains only the integer 0 and each time he visits a new mountain whose height is strictly greater than all the integers written in the notebook so far, he writes its height in the notebook. The satisfaction Chef gets from travelling is the number of positive integers written in the notebook at the end. For example, if the mountains have heights (1–,5–,2,5,3,7–,2,9–), Chef's satisfaction is 4 and the integers written in the notebook at the end are 0,1,5,7,9.

// Your task is to answer Q queries. In each query, Chef gives you two integers L and R (1≤L≤R≤N) and you should find the maximum satisfaction he can get if he can choose to visit any contiguous sequence of mountains from l to r such that L≤l≤r≤R. Note that the queries are encoded in such a way that they have to be processed online.

// Input
// The first line of each test case contains three space-separated integers N, Q and s.
// The second line contains N space-separated integers H1,H2,…,HN.
// Each of the following Q lines contains two space-separated integers x and y describing a query. The parameters L and R for this query can be computed as follows:
// Let last be the answer to the previous query, or 0 if this is the first query in this test case.
// Set L to (x+s⋅last−1)%N+1.
// Set R to (y+s⋅last−1)%N+1.
// If L>R, swap L and R.
// Output
// For each query, print a single line containing one integer — the maximum satisfaction Chef can get.

// Constraints
// 1≤N,Q≤105
// 0≤s≤1
// 1≤Hi≤105 for each valid i
// 1≤x,y≤N