#include <bits/stdc++.h>
#define ll long long
ll exgcd(ll a, ll b, ll &x, ll &y) {  
    if (!b) {  
        x = 1, y = 0;  
        return a;  
    }  
    ll t, ret;  
    ret = exgcd(b, a%b, x, y);  
    t = x, x = y, y = t - a / b*y;  
    return ret;  
}  
int main() {
	ll a, b, p, xx, ans = 0; 
	std::cin >> a >> b >> p >> xx;
	ll kP = p*(p-1);
	ll num;
	for (int i = 0; i < p-1; ++i) {
		if (i == 0) num = 1ll;
		else num = num*a%p;
		ll x, y;
		ll tmp = exgcd(num, p, x, y);
		x = ((x*(b/tmp)%p)+p)%p;
		ll min_n = (x*(p-1)%kP*(p-1)%kP+i*p%kP*p%kP)%kP;
		ll res = xx-min_n;
		if (res < 0) continue;
		ans += ((res/kP)+1);
	}
	std::cout << ans << std::endl;
	return 0;
}