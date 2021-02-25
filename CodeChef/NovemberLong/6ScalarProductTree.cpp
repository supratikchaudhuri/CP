#include <bits/stdc++.h>
using namespace std;
#define ll long
const int N = 500005;
#define M2 (1LL << 32)
#define vll vector<int>

int n, M, K, cur, Arr[N], LVL[N], DP[20][N];
int BL[N << 1], ID[N << 1], HMM[N];
ll l[N], r[N], lol[N], sos[N],  ANS[N], dd[N], ror[N];;
bool VIS[N];
vll adj[N];

inline int64_t motu(int x, int y, int pow, int rot) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rot) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rot + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = motu(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query{
	int id, l, r, lc;
	int64_t ord;

	inline void calcOrder() {
		ord = motu(l, r, 21, 0);
	}
}Q[N];

inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}
void dfs(int u, int par, int h){
	l[u] = ++cur;
	ID[cur] = u;
	LVL[u] = h;
	for (int i = 1; i < 20; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (v == par) continue;
		DP[0][v] = u;
		dfs(v, u, h + 1);
	}
	r[u] = ++cur; ID[cur] = u;
}
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = 20 - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = 20 - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

inline void check(long  x, long& res){
	if((VIS[x]))
	{
		if(HMM[LVL[x]] == 2)
		{
			HMM[LVL[x]]--; res -= lol[LVL[x]];
			res += M2; res %= M2;
			sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
			ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]); 	ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
		}
		else if(HMM[LVL[x]] == 3)
		{
			HMM[LVL[x]]--;
			sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
		    ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]); ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
			res += ror[LVL[x]]; res %= M2; lol[LVL[x]] = ror[LVL[x]];
		}
		else {
			HMM[LVL[x]]--;
			sos[LVL[x]] -= Arr[x]; sos[LVL[x]] += M2; sos[LVL[x]] %= M2;
			ror[LVL[x]] -= (Arr[x] * sos[LVL[x]]); 	ror[LVL[x]] += M2; ror[LVL[x]] %= M2;
		}
	}
	else
	{
		if(HMM[LVL[x]] == 1) {
			HMM[LVL[x]]++; ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
			res += ror[LVL[x]]; res %= M2;
			sos[LVL[x]] += Arr[x]; sos[LVL[x]] %= M2;
			lol[LVL[x]] = ror[LVL[x]];
		}
		else if(HMM[LVL[x]] == 2) {
			HMM[LVL[x]]++;
			ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
			sos[LVL[x]] += Arr[x]; sos[LVL[x]] %= M2;
			res -= lol[LVL[x]]; res += M2; res %= M2;
		}
		else {
			HMM[LVL[x]]++;
			ror[LVL[x]] += (Arr[x] * sos[LVL[x]]); ror[LVL[x]] %= M2;
			sos[LVL[x]] += Arr[x];  sos[LVL[x]] %= M2;
		}
	}

	VIS[x] ^= 1;
}

void dfsc(int v, int p);

void calc(){
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 0;

	for (int i = 0; i < M; i++){

		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);

		int u = ID[curL], v = ID[curR];
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);

		ANS[Q[i].id] = (res + dd[Q[i].lc]) % M2;

		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}

	for (int i = 0; i < M; i++) printf("%ld\n", ANS[i]);
}

int main(){

	int u, v, x;

	while (scanf("%d %d", &n, &M) != EOF){
		for (int i = 1; i <= n; i++) scanf("%d", &Arr[i]);
		for (int i = 1; i < n; i++){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		DP[0][1] = 1;
		dfs(1, -1, 1);
		dd[1] = Arr[1] * Arr[1];
		dd[1] %= M2;

		dfsc(1, 0);

		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
			Q[i].calcOrder();
		}

		sort(Q, Q + M);
		calc();
	}
}

void dfsc(int v, int x)
{
	for(auto i: adj[v])
	{
		if(i != x) {
		   dd[i] = (dd[v] + (Arr[i] * Arr[i]) % M2) % M2;
		   dfsc(i, v);
	    }
	}
}


// Chef has a tree with N vertices (numbered 1 through N). The tree is rooted at the vertex 1. For each valid i, the weight of the i-th vertex is wi.

// For a vertex u with depth d (the root has depth 1), let's denote the sequence of vertices on the path from u to the root by (v1,v2,…,vd), where v1=u and vd=1. Then, let Fu be the vector (i.e. sequence) (wv1,wv2,…,wvd), where the i-th element is Fu,i=wvi for each valid i.

// For any two vertices u and v with the same depth d, let's define the dot product Fu⋅Fv=∑di=1Fu,i⋅Fv,i.

// Your task is to answer Q queries. In each query, you are given two vertices u and v with the same depth, and you should find Fu⋅Fv. Since the dot product can be large, compute it modulo 232.

// Input
// The first line of the input contains two space-separated integers N and Q.
// The second line contains N space-separated integers w1,w2,…,wN.
// Each of the next N−1 lines contains two space-separated integers u and v denoting that vertices u and v are connected by an edge.
// Q lines follow. Each of these lines contains two space-separated integers u and v describing a query.
// Output
// For each query, print a single line containing one integer Fu⋅Fv modulo 232.

// Constraints
// 1≤N,Q≤3⋅105
// 1≤wi≤109 for each valid i
// 1≤u,v≤N
// in each query, u and v have the same depth
// Subtasks
// Subtask #1 (15 points, time limit 1 second): N,Q≤1,000
// Subtask #2 (45 points, time limit 2 seconds): N,Q≤105
// Subtask #3 (40 points, time limit 3.5 seconds): original constraints

// Example Input
// 5 2
// 5 4 3 2 1
// 1 2
// 1 3
// 2 4
// 2 5
// 2 3
// 4 5
// Example Output
// 37
// 43
// Explanation
//         1:5
//     2:5     3:3
// 4:2    5:1

// In the first query, F2=(4,5) and F3=(3,5), so the scalar product is 4⋅3+5⋅5=37.

// In the second query, F4=(2,4,5) and F5=(1,4,5), so the scalar product is 2⋅1+4⋅4+5⋅5=43.