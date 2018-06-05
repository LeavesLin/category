#include <bits/stdc++.h>
const int kN = 1e6+10;
int cnt[12][kN];
int f[kN];
int calc(int x) {
	int y = x;
	if (f[x] != 0) return f[x];
	int nxt = 1;
	while (x != 0) {
		int digit = x%10;
		if (digit != 0) nxt *= digit;
		x = x/10;
	}
	f[y] = calc(nxt);
	return f[y];
}
int main() {
	for (int i = 1; i <= 9; ++i) {
		f[i] = i;
		cnt[i][i] = 1;
	}
	for (int i = 10; i <= 1e6; ++i) {
		calc(i);
		cnt[f[i]][i] = 1;
	}
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 1e6; ++j)
			cnt[i][j] += cnt[i][j-1];
	}
	// for (int i = 1; i <= 62; ++i) if (f[i] == 4) std::cout << i << std::endl;
	// 	std::cout << cnt[4][3] << " " << cnt[4][14] << std::endl;
	int q; std::cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", cnt[k][r]-cnt[k][l-1]);
	}

	return 0;
}