#include <bits/stdc++.h>
const int kN = 1e6+10;
class SuffixArray {
 public:
  void operator() (int n, int *sa, int *rank, int *height, char *a) {
    for (int i = 1; i <= n; ++i) rank[i] = a[i], tp[i] = i;
    int m = 300; bsort(n, m, sa, rank);
    for (int p = 0, w = 1; p < n; m = p, w += w) {
      p = 0;
      for (int i = n-w+1; i <= n; ++i) tp[++p] = i;
      for (int i = 1; i <= n; ++i) if (sa[i] > w) tp[++p] = sa[i]-w;
      bsort(n, m, sa, rank); tp[sa[1]] = p = 1;
      for (int i = 2; i <= n; ++i) tp[sa[i]] = cmp(rank, sa[i], sa[i-1], w)?p:++p;
      for (int i = 1; i <= n; ++i) rank[i] = tp[i];
    }
    int j, k = 0;
    for (int i = 1; i <= n; height[rank[i++]] = k) 
      for (k = k?k-1:0, j = sa[rank[i]-1]; a[i+k] == a[j+k]; ++k);
  }
 private:
  int tp[kN], cnt[kN];
  bool cmp(int *f, int x, int y, int w) {return f[x] == f[y] && f[x+w] == f[y+w];}
  void bsort(int n, int m, int *sa, int *rank) {
    for (int i = 0; i <= m; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) cnt[rank[i]]++;
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
    for (int i = n; i >= 1; --i) sa[cnt[rank[tp[i]]]--] = tp[i];
  }
}calcsa;
char s[kN];
int rank[kN], sa[kN], height[kN];
int main() {
  scanf("%s", s+1); int n = strlen(s+1);
  calcsa(n, sa, rank, height, s);
  for (int i = 1; i <= n; ++i) printf("%d ", sa[i]);
  printf("\n");
  for (int i = 2; i <= n; ++i) printf("%d ", height[i]);
  printf("\n");
  return 0;
}