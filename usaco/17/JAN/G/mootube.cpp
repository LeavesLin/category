#include <bits/stdc++.h>
const int kN = 1e5+10;
struct Edge {
	int u, v, val;
}e[kN];
struct Que {
	int k, v, id, ans;
}qu[kN];
bool cmp1(Edge a, Edge b) {
	return a.val > b.val;
}
bool cmp2(Que a, Que b) {
	return a.k > b.k;
}
bool cmp3(Que a, Que b) {
	return a.id < b.id;
}
int fa[kN], size[kN];
int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void modi(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
	size[fy] += size[fx];
}
int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].val);
	for (int i = 1; i <= n; ++i) fa[i] = i, size[i] = 1;
	std::sort(e+1, e+n, cmp1);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &qu[i].k, &qu[i].v);
		qu[i].id = i;
	}
	std::sort(qu+1, qu+q+1, cmp2);
	int til = 1;
	for (int i = 1; i <= q; ++i) {
		while (til < n && e[til].val >= qu[i].k) {
			modi(e[til].u, e[til].v);
			til++;
		}
		qu[i].ans = size[find(qu[i].v)];
	}
	std::sort(qu+1, qu+q+1, cmp3);
	for (int i = 1; i <= q; ++i) printf("%d\n", qu[i].ans-1);
	return 0;
}