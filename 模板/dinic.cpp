#include <bits/stdc++.h>
#define ll long long
const ll oo = 2147483648ll;
struct Node {
  struct Edge *fir, *curr;
  int level;
}no[150];
struct Edge {
  Node *to;
  Edge *nxt, *res;
  int flow;
}pool[11000], *til = pool;
void add(int x, int y, int z) {
  (++til)->to = &no[y]; til->res = til+1; til->flow = z; 
  til->nxt = no[x].fir; no[x].fir = til;
  (++til)->to = &no[x]; til->res = til-1; til->flow = 0;
  til->nxt = no[y].fir; no[y].fir = til;
}
class Dinic {
 public:
  ll operator() (int s, int t, int n) {
    ll max_flow = 0;
    while (bfs(&no[s], &no[t], n)) {
      max_flow += dfs(&no[s], &no[t]);
      // std::cerr << max_flow << std::endl;
    }
    return max_flow;
  }
 private:
  bool bfs(Node *s, Node *t, int n) {
    for (int i = 1; i <= n; ++i) no[i].level = -1, no[i].curr = no[i].fir;
    std::queue<Node*> q; s->level = 1; q.push(s);
    while (!q.empty()) {
      Node *v = q.front(); q.pop();
      for (Edge *e = v->fir; e; e = e->nxt)
        if (e->flow && e->to->level == -1) {
          e->to->level = v->level+1;
          if (e->to == t) return true;
          q.push(e->to);
        }
    }
    return false;
  }
  ll dfs(Node *s, Node *t, ll limit = oo) {
    if (s == t) return limit;
    ll cnt_flow = 0;
    for (Edge *&e = s->curr; e; e = e->nxt)
      if (e->flow && e->to->level == s->level+1) {
        ll flow = dfs(e->to, t, std::min(limit-cnt_flow, (ll)e->flow));
        cnt_flow += flow; e->flow -= flow; e->res->flow += flow;
        if (cnt_flow == limit) return limit; 
      }
    if (cnt_flow != limit) s->level = -1;
    return cnt_flow;
  }
}dinic;
int main() {
  int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; ++i) {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }
  std::cout << dinic(s, t, n) << std::endl;
  return 0;
}