#include <bits/stdc++.h>
const int kN = 5010;
struct Node {
	struct Edge *fir;
}no[kN];
struct Edge {
	Edge *nxt;
	Node *to;
	int val;
	Edge(Node *from, Node *to, int z):nxt(from->fir), to(to), val(z){}
};
void add(Node *a, Node *b, int z) {
	a->fir = new Edge(a, b, z);
	b->fir = new Edge(b, a, z);
}
int k, cnt;
void dfs(Node *u, int mini, Node *fa) {
	if (mini >= k) cnt++;
	for (Edge *e = u->fir; e; e = e->nxt) 
		if (e->to != fa)
			dfs(e->to, std::min(mini, e->val), u);
}
int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(&no[x], &no[y], z);
	}
	for (int i = 1; i <= q; ++i) {
		int v; cnt = 0;
		scanf("%d%d", &k, &v);
		dfs(&no[v], 2147483600, NULL);
		printf("%d\n", cnt-1);
	}
	return 0;
}