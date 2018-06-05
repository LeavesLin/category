#include <bits/stdc++.h>
const int kN = 2010;
char s[kN][kN];
int sum[kN];
int calc(int *a, int n, int len) {
	int cnt = 0;
	for (int i = 1; i <= n-len+1; ++i) 
		if (a[i+len-1]-a[i-1] == len) cnt++;
	return cnt;
}
int main() {
	int n, m, k; scanf("%d%d%d ", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i]+1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(sum, 0, sizeof(sum));
		for (int j = 1; j <= m; ++j) 
			sum[j] = sum[j-1]+((s[i][j] == '.')?1:0);
		ans += calc(sum, m, k);
	}
	if (k != 1) {
	for (int j = 1; j <= m; ++j) {
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; ++i) 
			sum[i] = sum[i-1]+((s[i][j] == '.')?1:0);
		ans += calc(sum, n, k);
	}
	}
	std::cout << ans << std::endl;
	return 0;
}