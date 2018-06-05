#include <bits/stdc++.h>
const int kN = 1e5+10;
struct Node {
	struct Edge *fir;
	int need, len;
}no[kN];
struct Edge {
	Edge *nxt;
	Node *to;
	Edge(Node *from, Node *to) : nxt(from->fir), to(to) {}
};
void add(Node *x, Node *y) {
	x->fir = new Edge(x, y);
	y->fir = new Edge(y, x);
}
void dfs(Node *v, Node *fa, int dis) {
	v->len = 2147483600; int sum = 0;
	for (Edge *e = v->fir; e; e = e->nxt) 
		if (e->to != fa) {
			dfs(e->to, v, dis+1);
			v->len = std::min(v->len, e->to->len+1);
			sum += e->to->need;
		}
	if (v->len == 2147483600) {v->len = 0; v->need = 1;}
	if (dis < v->len) {
		v->need = sum;
	} else {
		v->need = 1;
	}
}
int main() {
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	int n, k; scanf("%d%d", &n, &k); int cnt = 0;
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(&no[x], &no[y]);
		if (x == k || y == k) cnt++;
	}
	if (cnt <= 1) {printf("1\n");return 0;} 
	for (int i = 1; i <= n; ++i) no[i].need = 0;
	dfs(&no[k], NULL, 0);
	printf("%d\n", no[k].need);
	return 0; 
}