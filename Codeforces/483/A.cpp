#include <bits/stdc++.h>
#define ll long long
ll gcd(ll a, ll b) {
  if (a < b) std::swap(a, b);
  ll c;
  while (b != 0) {
    c = a%b;
    a = b; b = c;
  }
  return a;
}
int main() {
  ll t;  scanf("%I64d", &t);
  // std::cin >> t;
  while (t--) {
    ll p, q, b; 
    scanf("%I64d%I64d%I64d", &p, &q, &b);
    // std::cin >> p >> q >> b;
    ll g = gcd(p, q);
    p /= g; q /= g; 
    if (p%q == 0) {
      puts("Finite");
    } else {
      while (q != 1) {
        ll g = gcd(q, b);
        if (g == 1) break;
        while (q%g == 0) q /= g;
      }
      puts((q == 1)?"Finite":"Infinite");
    }
  }
  return 0;
}