#include <bits/stdc++.h>

using namespace std;

double dist[2002][2002];
vector<int> P;

double DP[2002];

double dp(int N) {
    if (N == 0) return 0;

    if (DP[N] != 0) return DP[N];

    double mini = 200000;
    for (int i = 0; i < N; i++) {
        double res = dp(i) + 1 + dist[i][N] + P[N-1] - P[i];
        mini = min(mini, res);
    }
    return (DP[N] = mini);
}

double solve(int N) {
    fill(DP, DP+N+2, 0);
    vector<int> X(N+2), Y(N+2);
    P.resize(N+1);
    X[0] = 0; Y[0] = 0; P[0] = 0;
    X[N+1] = 100; Y[N+1] = 100;
    for (int i = 1; i < N+1; i++) {
        int p;
        cin >> X[i] >> Y[i];
        cin >> p;
        P[i] = P[i-1] + p;
    }

    for (int i = 0; i < N+2; i++) {
        for (int j = i; j < N+2; j++) {
            dist[j][i] = sqrt(pow(X[i]-X[j], 2) + pow(Y[i]-Y[j], 2));
            dist[i][j] = dist[j][i];
        }
    }

    return dp(N+1);
}

int main(void) {
    int N;

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        printf("%.3lf\n", (double) round(solve(N)*1000)/1000.0);
    }
}
