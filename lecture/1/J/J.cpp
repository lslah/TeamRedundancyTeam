#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int> > > DP;

int main(void){
    string sequence;
    cin >> sequence;

    int R, W, N = sequence.length();
    cin >> R >> W;

    DP.resize(N);
    for (int i = 0; i < N; i++) {
        DP[i].resize(2);
        DP[i][0].resize(R+1);
        DP[i][1].resize(W+1);
    }

    for (int j = 0; j <= R; j++) {
        DP[0][0][j] = (sequence[0] == 'G');
    }
    for (int j = 0; j <= W; j++) {
        DP[0][1][j] = (sequence[0] != 'G');
    }

    for (int i = 1; i < N; i++) {
        int maxi = 0;
        bool g = (sequence[i] == 'G');

        for (int j = 1; j < R; j++) {
            DP[i][0][j+1] = DP[i-1][0][j] + 1*g;
            maxi = max(maxi, DP[i-1][0][j]);
        }
        maxi = max(maxi, DP[i-1][0][R]);

        DP[i][1][1] = maxi + (1-g);

        maxi = 0;
        for (int j = 1; j < W; j++) {
            DP[i][1][j+1] = DP[i-1][1][j] + (1-g);
            maxi = max(maxi, DP[i-1][1][j]);
        }
        maxi = max(maxi, DP[i-1][1][W]);
        DP[i][0][1] = maxi + g;
    }

    int maxi = 0;
    for (int j = 1; j <= R; j++) {
        maxi = max(DP[N-1][0][j], maxi);
    }
    for (int j = 1; j <= W; j++) {
        maxi = max(DP[N-1][1][j], maxi);
    }

    cout << maxi << endl;
}
