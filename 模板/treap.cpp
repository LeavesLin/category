#include <bits/stdc++.h>
struct TreapNode {
  TreapNode *ch[2];
  int num, cnt, rnd;
  int size;
  TreapNode(int x) {
    num = x; rnd = rand();
    size = cnt = 1;
    ch[0] = ch[1] = NULL;
  }
  void maintain() {
    size = cnt;
    if (ch[0]) size += ch[0]->size;
    if (ch[1]) size += ch[1]->size;
  }
  int cmp(int x) {
    if (x == num) return -1;
    return x<num?0:1;
  } 
};
class Treap {
 public:
  TreapNode *root;
  void insert(TreapNode *&u, int x) {
    if (u == NULL) {
      u = new TreapNode(x);
    } else {
      int d = u->cmp(x);
      if (d == -1) {
        u->cnt++;
      } else {
        insert(u->ch[d], x);
        if (u->ch[d]->rnd > u->rnd) rotate(u, d^1);
      }
    }
    u->maintain();
  }
  void erase(TreapNode *&u, int x) {
    int d = u->cmp(x);
    if (d == -1) {
      if (u->cnt > 1) 
        u->cnt--;
      else {
        if (u->ch[0] != NULL && u->ch[1] != NULL) {
          int d2 = (u->ch[0]->rnd > u->ch[1]->rnd)?1:0;
          rotate(u, d2); erase(u->ch[d2], x);
        } else {
          TreapNode *tmp = u;
          if (u->ch[0]) u = u->ch[0]; else u = u->ch[1];
          delete tmp;
        }
      }
    } else
      erase(u->ch[d], x);
    if (u) u->maintain();
  }
  int rank(TreapNode *u, int x) {
    if (u == NULL) return 1;
    int d = u->cmp(x);
    if (d == -1) {
      int ret = 1;
      if (u->ch[0]) ret += u->ch[0]->size;
      return ret;
    } else {
      int ret = rank(u->ch[d], x);
      if (d == 1) {
        if (u->ch[0]) ret += u->ch[0]->size;
        ret += u->cnt;
      }
      return ret;
    } 
  }
  int select(TreapNode *u, int rk) {
    if (u->ch[0]) {
      if (rk <= u->ch[0]->size) return select(u->ch[0], rk);
      rk -= u->ch[0]->size;
    }
    if (rk <= u->cnt) return u->num;
    else rk -= u->cnt;
    return select(u->ch[1], rk);
  }
  int findpre(TreapNode *u, int x) {
    if (u == NULL) return -214748364;
    if (u->num < x) return std::max(findpre(u->ch[1], x), u->num); 
    else return findpre(u->ch[0], x);
  }
  int findsuf(TreapNode *u, int x) {
    if (u == NULL) return 214748364;
    if (u->num > x) return std::min(findsuf(u->ch[0], x), u->num);
    else return findsuf(u->ch[1], x);
  }
 private:
  void rotate(TreapNode *&u, int d) {
    TreapNode *tmp = u->ch[d^1]; u->ch[d^1] = tmp->ch[d]; tmp->ch[d] = u;
    u->maintain(); tmp->maintain(); u = tmp;
  }
}treap;
void dfs(TreapNode *u, int dep) {
  if (u->ch[1] != NULL) dfs(u->ch[1], dep+1);
  printf("size : %2d cnt : %2d|", u->size, u->cnt);
  for (int i = 1; i <= dep; ++i) printf(" ");
  printf("%d\n", u->num);
  if (u->ch[0] != NULL) dfs(u->ch[0], dep+1);
}
void print() {
  dfs(treap.root, 0);
  printf("-------------------\n");
}
int main() {
  // freopen("test.in", "r", stdin);
  srand(time(0)); // treap.root = NULL;
  int n; scanf("%d", &n);
  while (n--) {
    int op, x; scanf("%d%d", &op, &x);
    if (op == 1) {
      treap.insert(treap.root, x);
    } else if (op == 2) {
      treap.erase(treap.root, x);
    } else if (op == 3) {
      printf("%d\n", treap.rank(treap.root, x));
    } else if (op == 4) {
      printf("%d\n", treap.select(treap.root, x));
    } else if (op == 5) {
      printf("%d\n", treap.findpre(treap.root, x));
    } else if (op == 6) {
      printf("%d\n", treap.findsuf(treap.root, x));
    }
    // print();
  }
  return 0;
}