#include <bits/stdc++.h>
const int kN = 5010;
int a[kN];
int dp[kN][kN];
int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    dp[1][i] = a[i];
  }
  for (int i = 2; i <= n; ++i) 
    for (int j = 1; j <= n-i+1; ++j) {
      dp[i][j] = dp[i-1][j]^dp[i-1][j+1];
      // printf("%d %d %d\n", i, j, dp[i][j]);
    }
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= n-i+1; ++j)
      dp[i][j] = std::max(dp[i][j], std::max(dp[i-1][j], dp[i-1][j+1]));
  int q; scanf("%d", &q);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    int len = r-l+1;
    printf("%d\n", dp[len][l]);
  }
  return 0;
}