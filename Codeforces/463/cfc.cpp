#include <bits/stdc++.h>
#define ll long long
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g = exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
int main() {
	ll n, a, b; std::cin >> n >> a >> b;
	ll x, y;
	if (n%a == 0) {
		x = n/a; y = 0;
	} else if (n%b == 0){
		x = 0; y = n/b;
	} else {
		ll g = exgcd(a, b, x, y);
		if (n%g != 0) {
			puts("-1");
			return 0;
		}
		x = x*(n/g); y = y*(n/g);
		b/=g;
		x = (x%b+b)%b; y = (n-a*x)/(b*g);
		b*=g;
		if (x < 0 || y < 0) {
			puts("-1");
			return 0;		
		}
	}
	int base = 0;
	for (int i = 1; i <= x; ++i) {
		printf("%I64d ", i*a+base);
		for (int j = 2; j <= a; ++j) 
			printf("%I64d ", (i-1)*a+j-1+base);
	}
	base = a*x;
	for (int i = 1; i <= y; ++i) {
		printf("%I64d ", i*b+base);
		for (int j = 2; j <= b; ++j) 
			printf("%I64d ", (i-1)*b+j-1+base);
	}
	std::cout << std::endl;
	return 0;
}
