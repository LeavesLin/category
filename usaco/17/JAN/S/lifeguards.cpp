#include <bits/stdc++.h>
const int kN = 1e5+10;
struct cow {
	int l, r;
}a[kN];
bool cmp(cow A, cow B) {
	if (A.l == B.l) return A.r < B.r;
	return A.l < B.l;
}
int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].l, &a[i].r);
	std::sort(a+1, a+n+1, cmp);
	int cnt = a[1].r-a[1].l, mr = a[1].r;
	for (int i = 2; i <= n; ++i)
		if (a[i].l <= mr) {
			if (a[i].r >= mr) {
				cnt += a[i].r-mr;
				mr = a[i].r;
			}
		} else {
			mr = a[i].r;
			cnt += a[i].r-a[i].l;
		}
	int mini;
	if (a[2].l >= a[1].r) mini = a[1].r-a[1].l;
	else mini = a[2].l-a[1].l; 
	for (int i = 1; i <= n; ++i) {
		if (mini == 0 || a[i].r <= a[i-1].l || (a[i].l == a[i-1].l && a[i].r >= a[i-1].r)) {
			std::cout << cnt << std::endl;
			return 0;
		}
		if (i != n) mini = std::min(mini, std::min(a[i].r-a[i].l, (a[i+1].l - a[i-1].r <= 0)?0:a[i+1].l - a[i-1].r));
		else {
			if (a[i-1].r <= a[i].l)
				mini = std::min(mini, a[i].r - a[i].l);
			else 
				mini = std::min(mini, a[i].r - a[i-1].r);
		}
	}
	printf("%d\n", cnt-mini);
	return 0;
}