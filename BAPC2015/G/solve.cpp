#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    double res;
    double a, b, c;
    double max = -1;
    int merke = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        res = (b*b)/(4*a) + c;
        if (res > max) {
            max = res;
            merke = i+1;
        }
    }

    cout << merke << endl;

}

int main(void) {
    int N_cases;
    cin >> N_cases;

    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

