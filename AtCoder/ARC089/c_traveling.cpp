#include <bits/stdc++.h>
const int kN = 1e5+10;
struct Node{
	int t, x, y;
}a[kN];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i].t, &a[i].x, &a[i].y);
	}
	a[0].t = a[0].x = a[0].y = 0;
	for (int i = 1; i <= n; ++i) {
		int dis = std::abs(a[i].x-a[i-1].x)+std::abs(a[i].y - a[i-1].y);
		if (a[i].t-a[i-1].t < dis || (a[i].t-a[i-1].t)%2 != dis%2) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}