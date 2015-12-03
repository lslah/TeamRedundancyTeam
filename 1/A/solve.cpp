#include <bits/stdc++.h>

using namespace std;

int solve(int endA, int notEndA, int N) {
    if (N == 0) return endA+notEndA;
    return solve(endA+notEndA, endA*1+notEndA*2, N-1);
}

int solve2(int N) {
    int endA = 0, notEndA = 1;
    while (N > 0) {
        N--;
        endA += notEndA;
        notEndA = endA + notEndA;
    }
    return endA + notEndA;
}

int main(void) {
    int N;
    cin >> N;
    cout << solve(0, 1, N) << endl;
}
