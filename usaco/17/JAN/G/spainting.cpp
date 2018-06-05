#include <bits/stdc++.h>
#define ll long long
const ll kP = 1e9+7;
ll po(ll a, ll b) {
	if (b <= 0) return 1;
	ll ans = 1ll;
	while (b) {
		if (b&1) ans = ans*a%kP;
		a = a*a%kP;
		b >>= 1;
	}
	return ans;
}
int main() {
	freopen("spainting.in", "r", stdin);
	freopen("spainting.out", "w", stdout);
	ll n, m, k, ans = 0ll;
	std::cin >> n >> m >> k;
	if (k > n) {printf("0\n"); return 0;}
	for (int len = k; len <= n; ++len) {
		// ll delta = 1ll;
		for (int i = 1; i <= n-len+1; ++i) {
			ll delta = 1ll;
			if (i != 1) delta = delta*(m-1)%kP*po(m, i-2)%kP;
			if (i != n-len+1) delta = delta*(m-1)%kP*po(m, n-i-len)%kP;
			// std::cerr << len << " " << i << " " << delta << std::endl;
			ans = (ans+delta*m%kP)%kP;			
		}
	}
	std::cout << ans << std::endl;
	return 0;
}