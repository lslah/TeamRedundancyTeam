#include <bits/stdc++.h>


using namespace std;

int main(void) {
    string line1, line2;
    int N;

    cin >> N;
    getline(cin, line1);
    getline(cin, line1);
    getline(cin, line2);

    int prev_above = 1, prev_below = 0;
    int tmp;
    for (int i = 0; i < N; i++) {
        tmp = prev_above;
        if (line1[i] == 'W') {
            prev_above = 0;
        } else {
            prev_above = max(prev_below, prev_above);
        }

        if (line2[i] == 'W') {
            prev_below = 0;
        } else {
            prev_below = max(tmp, prev_below);
        }
    }

    if (prev_above > 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
