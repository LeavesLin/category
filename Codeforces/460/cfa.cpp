#include<bits/stdc++.h>
int main() {
	int n, m; std::cin >> n >> m; double ans = 214748360.0;
	for (int i = 1; i <= n; ++i) {
		int a, b; std::cin >> a >> b;
		ans = std::min(ans, 1.0*a*m/b);
	}
	printf("%.9lf\n", ans);
	return 0;
}