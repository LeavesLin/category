#include <bits/stdc++.h>
const int kN = 1e5+10;
struct Node {
  Node *ch[2];
  int val, pri, size;
  void maintain() {
    size = 1;
    if (ch[0]) size += ch[0]->size;
    if (ch[1]) size += ch[1]->size;
  }
}pool[kN];
int cnt = 0;
class FhqTreap {
 public:
  Node *root, *x, *y, *z;
  void insert(int val) {
    split(root, val, x, y);
    root = merge(merge(x, getNewNode(val)), y);
  }
  void del(int val) {
    split(root, val, x, z); split(x, val-1, x, y);
    y = merge(y->ch[0], y->ch[1]);
    root = merge(merge(x, y), z);
  }
  int rank(int v) {
    split(root, v-1, x, y);
    int ret = (!x)?1:x->size+1;
    root = merge(x, y); 
    return ret;
  }
  int kth(Node *u, int rk) {
    if (u->ch[0]) {
      if (u->ch[0]->size >= rk) return kth(u->ch[0], rk);
      rk -= u->ch[0]->size;
    }
    if (rk == 1) return u->val;
    return kth(u->ch[1], rk-1);
  }
  void print(Node *u, int dep = 0) {
    if (!u) return;
    print(u->ch[0], dep+1);
    for (int i = 1; i <= dep; ++i) printf(" "); printf("%d\n", u->val);
    print(u->ch[1], dep+1);
  }
  int pre(int val) {
    split(root, val-1, x, y);
    int ret = kth(x, x->size);
    root = merge(x, y);
    return ret;
  }
  int nxt(int val) {
    split(root, val, x, y);
    int ret = kth(y, 1);
    root = merge(x, y);
    return ret;
  }
 private:
  Node* getNewNode(int x) {
    pool[++cnt].val = x;
    pool[cnt].pri = rand();
    pool[cnt].size = 1;
    return &pool[cnt];
  }
  void split(Node *now, int k, Node* &x, Node* &y) {
    if (!now) {x = y = NULL; return;}
    if (now->val <= k) 
      x = now, split(now->ch[1], k, now->ch[1], y);
    else
      y = now, split(now->ch[0], k, x, now->ch[0]);
    now->maintain();
  }
  Node* merge(Node *x, Node *y) {
    if (!x || !y) return (!x)?y:x;
    if (x->pri < y->pri) {
      x->ch[1] = merge(x->ch[1], y);
      x->maintain(); return x;
    } else {
      y->ch[0] = merge(x, y->ch[0]);
      y->maintain(); return y;
    }
  }
}tr;
int main() {
  srand(time(0));
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int op, val; scanf("%d%d", &op, &val);
    switch (op) {
      case 1 :
        tr.insert(val);
      break;
      case 2 :
        tr.del(val);
      break;
      case 3:
        printf("%d\n", tr.rank(val));
      break;
      case 4:
        printf("%d\n", tr.kth(tr.root, val));
      break;
      case 5:
        printf("%d\n", tr.pre(val));
      break;
      case 6:
        printf("%d\n", tr.nxt(val));
      break;
    }
  }
  return 0;
}