#include <bits/stdc++.h>

using namespace std;

double DP[2002];
vector<int> corr;

int W, R;

int correct(int N) {
    if (0 <= N && N < corr.size()) {
        return corr[N];
    } else {
        return 0;
    }
}

int dp(int n, int r) {
    if (n < 0) return 0;

    int maxi = 0;
    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < R; j++) {
            int res = dp(n - r - 1 - i, j) + correct(n-1) - 2*correct(n-r-1) + correct(n-r-1-i);
            maxi = max(maxi, res);
        }
    }
    return maxi;
}

int main(void) {
    string line;
    getline(cin, line);
    corr.resize(line.size()+1);
    corr[0] = 0;
    for (int i = 1; i < line.size()+1; i++) {
        corr[i] = corr[i-1];
        if (line[i-1] == 'G') corr[i] += 1;
    }
    cin >> R >> W;

    cout << dp(line.size()+1, 0) << endl;
}
