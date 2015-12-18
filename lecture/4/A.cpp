#include <bits/stdc++.h>

#define verbose 0
#define inf 1e9

using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN];
vector<int> value;
vector<int> nbr_pred;

int dfs(int v, int  p = -1){
   if (value[v]!= 0) return value[v];
   int maxdp = 0   ;
   for (int i = 0; i < edges[v].size(); i++){
      int next = edges[v][i];
      if (next != p){
         maxdp = max(maxdp, dfs(next, v)+1);
      }
   }
   value[v] = maxdp;
   return maxdp;
}
int main(void){
   int N, M;
   cin >> N >> M;
   nbr_pred.resize(N,0);
   value.resize(N,0);
   for (int i = 0; i < M; i++){
      int a, b;
      cin >> a >> b;
      edges[a-1].push_back(b-1);
      nbr_pred[b-1]++;
   }

   int maxval = 0;
   for (int i = 0; i < N; i++){
      if (nbr_pred[i] == 0){
         maxval = max(maxval, dfs(i));
      }
   }
   cout << maxval << endl;
}
