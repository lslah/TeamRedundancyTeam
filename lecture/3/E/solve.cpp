#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;

const long long INF = 1ll << 62;

vector<int> edges[MAXN];
vector<long long> costs[MAXN];
long long d[MAXN];

bool ford_bellman(int s, int n) {
    bool cycle = false;
    
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[s] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (d[j] == INF) {
                continue;
            }
            
            for (int k = 0; k < edges[j].size(); k++) {
                int next = edges[j][k];
                long long cost = costs[j][k];
                
                if (d[next] > d[j] + cost) {
                    d[next] = max(-INF, d[j] + cost);
                }
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (d[j] == INF) {
                continue;
            }
            
            for (int k = 0; k < edges[j].size(); k++) {
                int next = edges[j][k];
                long long cost = costs[j][k];
                
                if (d[next] > d[j] + cost) {
                    cycle = true;
                    d[next] = - INF;
                }
            }
        }
    }
    
    return cycle;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    int a, b; long long c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--; b--;
        edges[a].push_back(b);
        costs[a].push_back(-c);
    }

    ford_bellman(0, N);
    int to = N-1;
    if (d[to] == INF) {
        cout << ":(" << endl;
    } else if (d[to] == -INF) {
        cout << ":)" << endl;
    } else {
        cout << -d[to] << endl;
    }
}
