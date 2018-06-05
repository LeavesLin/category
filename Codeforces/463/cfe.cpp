#include <bits/stdc++.h>
#define ll long long
const int kP = 1e9+7;
ll f[5010][5010];
ll n, k; 
ll po(ll a, ll b) {
	ll ans = 1ll;
	while (b) {
		if (b&1) ans = ans*a%kP;
		a = a*a%kP;
		b >>= 1;
	}
	return ans;
}
ll calc(ll a, ll b) {
	if (f[a][b] != -1) return f[a][b];
	ll c = n-b;
	if (a == 0) {
		return (f[a][b] = po(2, c));
	}
	return f[a][b] = ((c?c*calc(a-1, b+1):0ll)%kP+(b?b*calc(a-1, b):0ll)%kP)%kP;
}
int main() {
	memset(f, -1, sizeof(f));
	// std::cout << f[1][1] << std::endl;
	std::cin >> n >> k;
	std::cout << calc(k, 0) << std::endl;
	return 0;
}