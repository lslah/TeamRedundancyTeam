#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    assert(1 <= N && N <= 200);

    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        assert(b[i] <= 10000);
    }

    int DP[N][N];

    if (N == 1) {
        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DP[i][j] = 0;
        }
        DP[i][i] = 1;
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            DP[i][j] = 2;
        }
    }

    int res = 1;
    for (int i = 0; i < N; i++) {
        for (int k = i-1; k >= 0; k--) {
            for (int j = k; j >= 0; j--) {
                if (2*b[k] <= b[j] + b[i]) {
                    DP[k][i] = max(DP[k][i], DP[j][k] + 1);
                }
            }
            res = max(res, DP[k][i]);
        }
    }

    cout << res << endl;
}

int main(){

    int K;
    cin >> K;

    for (int i = 0; i < K; i++){
        solve();
    }
}


