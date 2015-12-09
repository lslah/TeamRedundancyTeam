#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector< vector<int> > adj(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
}

int main(void) {
    int N_cases;
    cin >> N_cases;

    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

