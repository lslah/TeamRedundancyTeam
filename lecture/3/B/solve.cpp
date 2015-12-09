#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;

vector<int> edges[MAXN];
vector<int> costs[MAXN];
int used[MAXN];
int deik[MAXN];
int from[MAXN];

void dijkstra_set(int s) {
    set<pair<int, int> > deikst;
    
    used[s] = 1;
    deik[s] = 0;
    from[s] = -1;
    deikst.insert(make_pair(deik[s], s));
    
    while (!deikst.empty()) {
        int cur = deikst.begin()->second;
        deikst.erase(deikst.begin());
        
        used[cur] = 2;
        
        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i];
            int cost = costs[cur][i];
            
            if (used[next] == 0 || used[next] == 1 && deik[next] > deik[cur] + cost) {
                used[next] = 1;
                
                deikst.erase(make_pair(deik[next], next));
                
                deik[next] = deik[cur] + cost;
                from[next] = cur;
                deikst.insert(make_pair(deik[next], next));
            }
        }
    }
}

int main(void) {
    int N, from, to;
    cin >> N >> from >> to;
    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (x != -1) {
                costs[i].push_back(x);
                edges[i].push_back(j);
            }
        }
    }

    from--; to--;
    dijkstra_set(from);
    if (!used[to]) {
        cout << -1 << endl;
    } else {
        cout << deik[to] << endl;
    }
}
