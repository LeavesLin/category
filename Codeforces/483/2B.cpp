#include <bits/stdc++.h>
char mp[110][110];
const int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int n, m; 
int cntboom(int x, int y) {
  int ret = 0;
  for (int i = 0; i < 8; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    if (mp[nx][ny] == '*') ret++;
  }
  return ret;
}
int main() { 
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", mp[i]+1);
  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    if (!flag) break;
    for (int j = 1; j <= m; ++j)
      if (mp[i][j] != '*') {
        int cnt = cntboom(i, j);
        if ((mp[i][j] == '.' && cnt != 0)
            || (mp[i][j] != '.' && mp[i][j]-'0' != cnt)) {
          flag = false;
          break;
        }
      }
  }
  if (flag) puts("YES"); else puts("NO");
  return 0;
}