#include <bits/stdc++.h>
const int kN = 1e5+10;
struct Node {
	int x, y;
	char s[5];
}a[kN];
int cnt[2][3000];
int main() {
	// freopen("test.in", "r", stdin);
	int n, k; scanf("%d %d", &n, &k);
	int mini = 1e9+10, ind;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %s", &a[i].x, &a[i].y, a[i].s+1);
		if (a[i].x < mini) {
			mini = a[i].x; ind = i;
		}
	}
	// std::cerr << ind << std::endl;
	int ans = 0;
	for (int j = 1; j <= k; ++j) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			int dx = (a[i].x-a[ind].x)%(2*k);
			if (a[i].y > a[ind].y) {
				int dy = (a[i].y-(a[ind].y-j+1))%(2*k);
				if (dy < k) cnt[(a[i].s[1] == 'W')?0:1][dx]++;
				else cnt[(a[i].s[1] == 'W')?0:1][(dx+k)%(2*k)]++;
			} else {
				int dy = (a[ind].y+2*k-j-a[i].y)%(2*k);
				if (dy < k) cnt[(a[i].s[1] == 'W')?0:1][(dx+k)%(2*k)]++;
				else cnt[(a[i].s[1] == 'W')?0:1][dx]++;
			}
		}
		// for (int i = 0; i < 2*k; ++i) {
		// 	printf("%d ", cnt[0][i]);
		// }
		// printf("\n");
		// for (int i = 0; i < 2*k; ++i) {
		// 	printf("%d ", cnt[1][i]);
		// }
		// printf("\n");
		for (int i = 1; i < 2*k; ++i) cnt[0][i] += cnt[0][i-1], cnt[1][i] += cnt[1][i-1];
		for (int i = 0; i < k; ++i) {
			int size = 0;
			size += cnt[0][i+k-1]-((i == 0)?0:cnt[0][i-1]);
			if (i != 0) size += cnt[1][i-1];
			size += cnt[1][2*k-1]-cnt[1][i+k-1];
			size = std::max(size, n-size);
			ans = std::max(ans, size);
		}
	}
	printf("%d\n", ans);
	return 0;
}