#include <bits/stdc++.h>

using namespace std;


int main(){
    int N;
    cin >> N;

    int dp[N+1];

    dp[0] = 1;
    for (int i = 1; i <= N; i++){
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j];
            for (int k = i/3+1; k <= j; k++) {
                dp[i] -= dp[j-k];
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        cout << dp[i] << endl;
    }
}
