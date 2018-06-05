#include <bits/stdc++.h>
#define ll long long
const int kN = 1e6+10;
int c[kN], r[kN];
int n, m, R;
struct Store {
	int q, p;
}s[kN];
bool cmp1(int a, int b) {
	return a>b;
}
bool cmp2(Store a, Store b) {
	return a.p > b.p;
}
bool cmp3(int a, int b) {
	return a<b;
}
int til1, til2;
ll sale() {
	return (ll)r[til2++];
}
ll milk(int rest) {
	ll cnt = 0ll;
	while (rest > 0 && til1 <= m) {
		if (s[til1].q <= rest) {
			rest -= s[til1].q;
			cnt += s[til1].q*s[til1].p;
			til1++;
		} else {
			s[til1].q -= rest;
			cnt += rest*s[til1].p;
			rest = 0;
		}
	}
	return cnt;
}
int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &R);
	for (int i = 1; i <= n; ++i) scanf("%d", c+i);
	for (int i = 1; i <= m; ++i) scanf("%d %d", &s[i].q, &s[i].p);
	for (int i = 1; i <= R; ++i) scanf("%d", r+i);
	std::sort(c+1, c+n+1, cmp3);
	std::sort(s+1, s+m+1, cmp2);
	std::sort(r+1, r+R+1, cmp1);
/*
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", c[i]);
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d %d\n", s[i].q, s[i].p);
	}
	for (int i = 1; i <= R; ++i) {
		printf("%d\n", r[i]);
	}
*/
	til1 = til2 = 1;
	ll ans = 0;
	int i = 1;
	while (i <= n) {
		if (til1 > m) {
			ans += sale();
			++i;
		} else if (til2 > R) {
			ans += milk(c[i]);
			++i;
		} else {
			ll re2 = r[til2], re1 = 0ll, rest = c[i], tp = til1;
			// std::cerr << "::" << c[i] << std::endl;
			while (rest > 0 && tp <= (ll)m) {
				if (s[tp].q <= rest) {
					rest -= s[tp].q;
					re1 += s[tp].q*s[tp].p;
					tp++;
				} else {
					re1 += rest*s[tp].p;
					rest = 0;
				}
			}
			// std::cerr << re1 << " " << re2 << std::endl;
			if (re1 > re2) {ans += milk(c[n]);n--;}
			else {ans += sale();++i;}
			// std::cerr << til1 << "***" << s[til1].q << std::endl;
		}
		if (til1 > m && til2 > R) break;
	}
	std::cout << ans << std::endl;
	return 0;
}