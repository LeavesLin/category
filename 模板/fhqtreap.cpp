#include <bits/stdc++.h>
struct TreapNode {
  TreapNode *ch[2];
  int val, rnd, size;
  TreapNode(int x) {
    val = x; rnd = rand(); size = 1;
    ch[0] = ch[1] = NULL;
  }
};
void update(TreapNode *u) {
  u->size = 1;
  if (u->ch[0]) u->size += u->ch[0]->size;
  if (u->ch[1]) u->size += u->ch[1]->size;
}
void split(TreapNode *u, int k, TreapNode *&x, TreapNode *&y) {
  if (u == NULL) x = y = NULL;
  else {
    if (u->val <= k) {
      x = u; split(u->ch[1], k, u->ch[1], y);
    } else {
      y = u; split(u->ch[0], k, x, u->ch[0]);
    }
    update(u);
  }
}
TreapNode* merge(TreapNode *x, TreapNode *y) {
  if (x == NULL) return y;
  else if (y == NULL) return x;
  if (x == NULL && y == NULL) return NULL;
  if (x->rnd < y->rnd) {
    x->ch[1] = merge(x->ch[1], y);
    update(x);
    return x;
  } else {
    y->ch[0] = merge(x, y->ch[0]);
    update(y);
    return y;
  }
}
TreapNode *root = NULL, *x = NULL, *y = NULL, *z = NULL;
int findkth(TreapNode *u, int rk) {
  if (u->ch[0]) {
    if (u->ch[0]->size >= rk) return findkth(u->ch[0], rk);
    rk -= u->ch[0]->size;
  }
  if (rk == 1) return u->val;
  return findkth(u->ch[1], rk-1);
}
void dfs(TreapNode *u, int dep) {
  if (u->ch[1] != NULL) dfs(u->ch[1], dep+1);
  printf("size : %2d |", u->size);
  for (int i = 1; i <= dep; ++i) printf(" ");
  printf("%d\n", u->val);
  if (u->ch[0] != NULL) dfs(u->ch[0], dep+1);
}
void print() {
  printf("--------ST---------\n");
  dfs(root, 0);
  printf("--------ED---------\n");
}
int main() {
  // freopen("input1.in", "r", stdin);
  srand(time(0));
  int n; scanf("%d", &n);
  while (n--) {
    int op, num; scanf("%d%d", &op, &num);
    if (op == 1) {
      split(root, num, x, y);
      root = merge(merge(x, new TreapNode(num)), y);
    } else if (op == 2) {
      split(root, num, x, z);
      split(x, num-1, x, y);
      y = merge(y->ch[0], y->ch[1]);
      root = merge(merge(x, y), z);
    } else if (op == 3) {
      split(root, num-1, x, y);
      if (x == NULL) printf("1\n");
      else printf("%d\n", x->size+1);
      root = merge(x, y);
    } else if (op == 4) {
      printf("%d\n", findkth(root, num));
    } else if (op == 5) {
      split(root, num-1, x, y);
      printf("%d\n", findkth(x, x->size));
      root = merge(x, y);
    } else {
      split(root, num, x, y);
      printf("%d\n", findkth(y, 1));
      root = merge(x, y);
    }
    // print();
  }
  return 0;
}