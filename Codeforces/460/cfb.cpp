#include <bits/stdc++.h>
bool calc_sum(int x) {
	int ans = 0;
	while (x != 0) {
		ans += x%10;
		x = x/10;
		if (ans > 10) return false;
	}
	return (ans == 10);
}
int main() {
	int k; std::cin >> k; int cnt = 0, num = 0;
	while (cnt != k) {
		if (calc_sum(num)) cnt++;
		num++;
	}
	std::cout << num-1 << std::endl;
	return 0;
}