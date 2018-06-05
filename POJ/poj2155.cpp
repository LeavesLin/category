#include <cstring>
#include <iostream>
#include <cstdio>
const int kN = 1010;
int n, t;
int tr[kN][kN];
int lowbit(int x) {
	return x&(-x);
}
void add(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			tr[i][j]++;
}
int query(int x, int y) {
	int ret = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		for (int j = y; j >= 1; j -= lowbit(j))
			ret += tr[i][j];
	return ret;
}
int main() {
	int x; std::cin >> x;
	while (x--) {
		scanf("%d%d", &n, &t);
		memset(tr, 0, sizeof(tr));
		while (t--) {
			char s[5];
			scanf("%s", s+1);
			if (s[1] == 'C') {
				int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1); add(x2+1, y2+1); add(x1, y2+1); add(x2+1, y1);
			} else {
				int x1, y1; scanf("%d %d", &x1, &y1);
				int tmp = query(x1, y1);
				if (tmp%2) printf("1\n");
				else printf("0\n");
			}
		}
		printf("\n");
	}
	return 0;
}