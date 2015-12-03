#include <bits/stdc++.h>

using namespace std;

int weight[300+5];
int dp[10000+5][300+5];

int dpi(int S, int N) {
    if (N < 0) return 0;

    if (S - weight[N] < 0) {
        dp[S][N] = dpi(S, N-1);
    } else if (dp[S][N] == -1) {
        dp[S][N] = max(dpi(S, N-1), dpi(S-weight[N], N-1) + weight[N]);
    }

    return dp[S][N];
}

int iterative(int S, int N) {
    sort(weight, weight+N);

    int n = 1;

    for (int s = 0; s < S; s++) {
        if (n < N && weight[n] <= s) n++;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
            } else if (s-weight[i] < 0) {
                dp[s][i] = dp[s][i-1];
            } else {
                dp[s][i] = max(dp[s-weight[i]][i-1]+weight[i], dp[s][i-1]);
            }
        }
    }
}

int solve(int S, int N) {
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i <= S; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dpi(S, N-1) << endl;

    //for (int i = 0; i < S; i++) {
    //    for (int j = 0; j < N; j++) {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //for (int i = 0; i < S; i++) {
    //    for (int j = 0; j < N; j++) {
    //        dp[i][j] = -1;
    //    }
    //}

    //cout << iterative(S, N) << endl;
}

int main(void) {
    int S, N;
    cin >> S >> N;
    solve(S, N);
}
