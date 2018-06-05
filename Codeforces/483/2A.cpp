#include <bits/stdc++.h>
int a[5000];
int main() {
  int n; std::cin >> n; 
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::sort(a+1, a+n+1);
  std::cout << a[(n+1)/2] << std::endl;
}