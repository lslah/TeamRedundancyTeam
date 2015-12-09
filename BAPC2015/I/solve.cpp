#include <bits/stdc++.h>

using namespace std;

int fib[43];

void solve() {
    int N;
    cin >> N;
    
    set<pair<int, int> > merke;

    for (int j = 42; j >= 1; j--) {
        int x = fib[j], y = fib[j-1];
        int a, b;
        for (a = 1; a <= N/x; a++) {
            if ( ( N - a*x ) % (x+y) == 0 ) {
                b = (N - a*x) / (x+y);
                a = a + b;
                if (b == 0) {
                    b = a;
                }
                merke.insert(make_pair(a, b));
                break;
            }
        }
    }

    pair<int, int> f = *(merke.begin());
    cout << f.second << " " << f.first << endl;
}

int main(void) {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 43; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }


    int N_cases;
    cin >> N_cases;

    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

