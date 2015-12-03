#include <bits/stdc++.h>

using namespace std;

vector<vector<long long> > DP;

long long dp(int i, int j) {
   if (DP[i][j] != -1) return DP[i][j];

   if (j == 0){
      DP[i][j] = 0;
   } else if (i == 0) {
      DP[i][j] = 1;
   } else if (j > i) {
      DP[i][j] = dp(i, j-1);
   } else {
      DP[i][j] = dp(i, j-1) + dp(i-j, j/2);
   }

   assert(DP[i][j] != -1);

   return DP[i][j];
}

int main(void){
   int N;
   cin >> N;

   DP.resize(N+1);
   for (int i = 0; i < N+1; i++){
         DP[i].resize(N+1,-1);
   }

   DP[0][0] = 1;
   DP[1][1] = 1;

   cout << dp(N, N) << endl;
}
