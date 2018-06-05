#include <bits/stdc++.h>
char ch[70000];
int main() {
	scanf("%s", ch+1);
	int n = strlen(ch+1);
	for (int i = n; i >= 1; --i) {
		ch[n+n-i+1] = ch[i];
	}
	std::cout << ch+1 << std::endl;
}