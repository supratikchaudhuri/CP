#include<bits/stdc++.h>
using namespace std;
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define LLINF (long long)1e18
#define INF (int)1001001001
 
 
typedef long long int  ll;
 
 
 
/*+++++++Modular Arithmetic start+++++++*/
 
#define MOD 1000000007
#define MOD2 998244353
 
inline ll fastpow(ll base,ll power,ll modulo=MOD){
    base%=modulo;
    if (base<0LL) base+=modulo;
    ll x=base,cnt=power,ans=1LL;
    while(cnt){
        if (cnt&1LL) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1LL;
    }
    // int tmp=ans;
    return ans;
}
 
inline ll inv(ll base,ll modulo=MOD){
    return fastpow(base,modulo-2LL,modulo);
}
 
inline ll modadd(ll a, ll b, ll m = MOD)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}
 
inline ll modmul(ll a, ll b, ll m = MOD)
{
    return ((a % m) * (b % m)) % m;
}
 
/*+++++++Modular Arithmetic end+++++++*/
 
 
ll gcd(ll a,ll b){
	if(a == 0){
		return b;
	}
	return gcd(b%a,a);
}
 
 
vector<int> adj[200002];
vector<int> vis(200002);
vector<int> dis(200002);
vector<int> d(200002);
//Start
 
void dfs(int u){
	vis[u] = 1;
	d[u] = dis[u];
	for(int v: adj[u]){
		if(!vis[v] && dis[v] > dis[u]){
			dfs(v);
		}
		if(dis[v] > dis[u]){
			d[u] = min(d[u],d[v]);
		}
		else{
			d[u] = min(d[u],dis[v]);
		}
	}
}
 
void solve(){
	//Code
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		adj[i].clear();
		vis[i] = 0;
		dis[i] = 1e6;
		d[i] = 1e6;
	}
	dis[0] = 0;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].pb(v);
	}
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
 
		for(int v: adj[u]){
			if(!vis[v]){
				dis[v] = dis[u]+1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
 
}
 
 
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

// 1472G - Moving to the Capital
// Find the distances to all vertices and construct a new graph that has only edges that goes from a vertex with a smaller distance to a vertex with a larger distance. Such a graph cannot contain cycles.

// Next, you need to run a dynamic programming similar to finding bridges in an undirected graph. First, we write the minimum distance from each vertex to the capital using no more than one edge. This distance is either equal to the distance from the capital to the vertex itself, or the distance to the vertex connected to us by one of the remote edges. We can't go through more than one remote edge.

// The real answer for a vertex v is the minimum of such values in all vertices reachable from v in the new graph. Since the new graph is acyclic, we can calculate the answer using dynamic programming and a depth-first search started from the capital.