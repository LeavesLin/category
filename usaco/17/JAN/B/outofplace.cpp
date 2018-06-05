#include <bits/stdc++.h>
int a[200];
int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	int n, til = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if (i == 1 || x != a[til]) a[++til] = x;
	}
	n = til;
	int mini = 5000;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int k = i-1; k >= 1; --k) {
			cnt++; std::swap(a[k], a[k+1]);
			bool flag = true;
			for (int j = 1; j < n; ++j) 
				if (a[j] > a[j+1]) {
					flag = false;
					break;
				}
			if (flag) mini = std::min(mini, cnt);
		}
		for (int k = 2; k <= i; ++k) std::swap(a[k], a[k-1]);
		cnt = 0;
		for (int k = i+1; k <= n; ++k) {
			cnt++; std::swap(a[k], a[k-1]);
			bool flag = true;
			for (int j = 1; j < n; ++j) 
				if (a[j] > a[j+1]) {
					flag = false;
					break;
				}
			if (flag) mini = std::min(mini, cnt);			
		}
		for (int k = n-1; k >= i; --k) std::swap(a[k], a[k+1]);
	}
	printf("%d\n", mini);
	return 0;
}