#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> seq, dp;
    seq.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());

    dp[0] = 1;
    int maxDDP = 1;
    for (int i = 1; i < N; i++) {
        int maxDP = 1;
        for (int j = 0; j < i; j++) {
            if (2*seq[j] > seq[i] && seq[j] < 2*seq[i]) {
                maxDP = max(maxDP, dp[j]+1);
            }
        }
        dp[i] = maxDP;
        maxDDP = max(maxDDP, maxDP);
    }

    cout << maxDDP << endl;
}
