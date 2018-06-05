#include <bits/stdc++.h>
const int kN = 3e5+10;
struct Node {
	struct Edge *fir;
	int in, id;
	int cntt[30];
}no[kN];
struct Edge {
	Node *to;
	Edge *nxt;
	Edge(Node *from, Node *to) : to(to), nxt(from->fir){
	}
};
void add(Node *x, Node *y) {
	x->fir = new Edge(x, y);
}
int n, m;
char s[kN];
int main() {
	scanf("%d%d ", &n, &m);
	for (int i = 1; i <= n; ++i) no[i].in = 0, no[i].id = i;
	scanf("%s", s+1);
	for (int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(&no[x], &no[y]);
		no[y].in++;
	}
	int qu[kN], l = 1, r = 0, cnt = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (no[i].in == 0) qu[++r] = i;
	}
	while (l <= r) {
		Node *v = &no[qu[l++]]; cnt++;
		v->cntt[s[v->id]-'a'+1]++;
		for (int i = 1; i <= 26; ++i) ans = std::max(ans, v->cntt[i]);
		// printf("%d\n", v->id);
		for (Edge *e = v->fir; e; e = e->nxt) {
			e->to->in--;
			if (e->to->in == 0) {
				qu[++r] = e->to->id;
			}
			for (int i = 1; i <= 26; ++i) e->to->cntt[i] = std::max(e->to->cntt[i], v->cntt[i]); 
		}
	}
	if (cnt != n) {
		puts("-1");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}