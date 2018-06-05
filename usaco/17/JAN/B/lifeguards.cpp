#include <bits/stdc++.h>
struct Shift {
	int l, r;
}a[110];
int ans = 0;
bool cnt[2000];
int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
	int mini = 2147483600, ind = -1;
	for (int i = 1; i <= n; ++i) {
		int tl = a[i].l, tr = a[i].r;
		for (int j = 1; j <= n; ++j) 
			if (j != i) {
				if (a[j].l <= tl && a[j].r >= tr) {
					tl = tr; break;
				}
				if (a[j].l <= tl && a[j].r >= tl && a[j].r <= tr) tl = a[j].r;
				if (a[j].r >= tr && a[j].l <= tr && a[j].l >= tl) tr = a[j].l;
			}
// std::cerr << i << ":" << tl << " " << tr << std::endl;
		if (tr - tl <= mini) {
			mini = tr-tl;
			ind = i;
		}
	}
// std::cerr << ind << std::endl;
	for (int i = 1; i <= n; ++i) 
		if (i != ind) {
			for (int j = a[i].l; j < a[i].r; ++j) {
				cnt[j] = true;
			}
		}
	for (int i = 0; i <= 1000; ++i) if (cnt[i]) ans++;
	printf("%d\n", ans);
}