#include "bits/stdc++.h"
using namespace std;
constexpr int N = 200005;
constexpr int D = 52;
constexpr int K = 140608;
int t[300], ct;
int n;
vector<int> g[K + N];
vector<int> rg[K + N];
int get(string &s, int l, int r) {
  int res = 0;
  for (int i = l; i <= r; i ++) {
    res *= D;
    res += t[s[i]];
  }
  return res;
}
int outd[N + K];
bool vis[N + K];
int dp[N + K];
set<int> q;
void add_edge(int u, int v) {
  // cerr << u << ' ' << v << endl;
  g[u].push_back(v);
  rg[v].push_back(u);
}
void destroy(int u) {
  for (int v : rg[u]) {
    if (!vis[v]) {
      outd[v] --;
      if (outd[v] == 0) {
        q.insert(v);
      }
    }
  }
}
void solution() {
  for (char c = 'a'; c <= 'z'; c ++) t[c] = ct ++;
  for (char c = 'A'; c <= 'Z'; c ++) t[c] = ct ++;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    add_edge(get(s, 0, 2), i + K);
    add_edge(i + K, get(s, s.size() - 3, s.size() - 1));
  }
  fill(dp, dp + K + n, 2);
  for (int i = 0; i < K + n; i ++) {
    if (g[i].size() == 0)
      q.insert(i);
    outd[i] = g[i].size();
  }
  while (q.size()) {
    int u = *q.begin();
    q.erase(q.begin());
    vis[u] = true;
    bool flag = false;
    if (u >= K) {
      dp[u] = dp[g[u][0]];
    }
    else {
      for (int v : g[u])
        if (dp[v] == 0) {
          flag = true;
          break;
        }
      if (flag) {
        dp[u] = 1;
      }
      else dp[u] = 0;
    }
    if (dp[u] == 0 && u >= K) {
      for (int v : rg[u]) {
        dp[v] = 1;
        vis[v] = 1;
        destroy(v);
      }
    }
    destroy(u);
  }
  for (int i = K; i < K + n; i ++) {
    if (dp[i] == 1) cout << "Aoki\n";
    else if (dp[i] == 0) cout << "Takahashi\n";
    else cout << "Draw\n";
  }