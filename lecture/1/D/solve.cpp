#include <bits/stdc++.h>

using namespace std;

int weights[50];

int dpm[50][50];

int count1 = 0;
int count2 = 0;

int dp(int a, int b) {
    assert(!(b-a < 1));
    if (b - a == 1) {
        return 0;
    }

    if (dpm[a][b] != 0) {
        count2++;
        return dpm[a][b];
    }
    count1++;

    int maxE = 0;
    for (int i = a+1; i <= b-1; i++) {
        maxE = max(dp(a, i) + dp(i, b), maxE);
    }

    dpm[a][b] = maxE + weights[a]*weights[b];
    return dpm[a][b];
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    cout << dp(0, N-1) << endl;
    cout << count2 << endl;
    cout << count1 << endl;
}
