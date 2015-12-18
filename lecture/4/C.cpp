#include <bits/stdc++.h>

#define verbose 1
#define inf 1e9

using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN], costs[MAXN];
int used[MAXN], dp[MAXN];

int dfs(int v, int p = -1){
   if (used[v]) return dp[v];
   dp[v] = 0;
   used[v] = 1;
   for (int i = 0; i < edges[v].size(); i++){
      int next = edges[v][i];
      if (next != p){
         dp[v] = max(dp[v], dfs(next, v) + costs[v][i]);
      }
   }
   return dp[v];
}

int main(void){
   int N, M, root;
   cin >> N >> M >> root;
   root--;
   fill(used, used+MAXN, 0);
   fill(dp, dp+MAXN, 0);
   for (int i = 0; i < M; i++){
      int a, b, c;
      cin >> a >> b >> c;
      edges[a-1].push_back(b-1);
      costs[a-1].push_back(c);
   }
   cout << dfs(root) << endl;
}
