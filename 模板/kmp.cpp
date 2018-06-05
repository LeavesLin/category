#include <bits/stdc++.h>
const int kN = 1e6+10;
char s1[kN], s2[kN];
int nxt[kN];
int main() {
  scanf("%s\n%s", s1+1, s2+1);
  int n = strlen(s1+1), m = strlen(s2+1);
  nxt[1] = 0; int j = 0;
  for (int i = 2; i <= m; ++i) {
    while (j > 0 && s2[j+1] != s2[i]) j = nxt[j];
    if (s2[j+1] == s2[i]) ++j; 
    nxt[i] = j;
  }
  int cnt = 0; j = 0;
  for (int i = 1; i <= n; ++i) {
    while (j > 0 && s1[i] != s2[j+1]) j = nxt[j];
    if (s1[i] == s2[j+1]) ++j;
    if (j == m) {
      cnt++;
      j = nxt[j];
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}