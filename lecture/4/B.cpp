#include <bits/stdc++.h>

#define verbose 1
#define inf 1e9

using namespace std;

const int MAXN = 100001;
vector<int> edges[MAXN];
int a[MAXN];

int dfs(int v, int p = -1){
   int sum = 0;
   for (int i = 0; i < edges[v].size(); i++){
      int next = edges[v][i];
      if (next != p){
         sum += dfs(next, v);
      }
   }
   return max(0, sum+a[v]);
}

int main(void){
   int N, root;
   cin >> N >> root;
   root--;
   for (int i = 0; i < N; i++) { cin >> a[i]; }
   for (int i = 0; i < N-1; i++){
      int da, b;
      cin >> da >> b;
      edges[da-1].push_back(b-1);
      edges[b-1].push_back(da-1);
   }
   cout << dfs(root) << endl;
}
