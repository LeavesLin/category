#include <bits/stdc++.h>
struct space {
  int u, d, l, r;
}a, b;
int main() {
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  scanf("%d%d%d%d%d%d%d%d", &a.l, &a.d, &a.r, &a.u, &b.l, &b.d, &b.r, &b.u);
  if (b.l <= a.l && b.r >= a.r && b.u >= a.u && b.d <= a.d) {
    printf("0\n");
  } else if (b.d <= a.d && b.u >= a.u && b.l >= a.l && b.l <= a.r && b.r >= a.r) {
    printf("%d\n", (a.u-a.d)*(b.l-a.l));
  } else if (b.d <= a.d && b.u >= a.u && b.r <= a.r && b.r >= a.l && b.l <= a.l) {
    printf("%d\n", (a.u-a.d)*(a.r-b.r));
  } else if (b.l <= a.l && b.r >= a.r && b.u >= a.u && b.d >= a.d && b.d <= a.u) {
    printf("%d\n", (a.r-a.l)*(b.d-a.d));
  } else if (b.l <= a.l && b.r >= a.r && b.d <= a.d && b.u >= a.d && b.u <= a.u) {
    printf("%d\n", (a.r-a.l)*(a.u-b.u));
  } else {
    printf("%d\n",(a.r-a.l)*(a.u-a.d));
  }
	return 0;
}