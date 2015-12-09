#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 2000;
struct UnionFind {
    int id;
    int rank;
    int val;
};

UnionFind uf[MAXN];

void combine(int a, int b) {
    uf[b].val = max(uf[b].val, uf[a].val);
}

void build(int n) {
    for (int i = 0; i < n; i++) {
        uf[i].id = i;
        uf[i].rank = 1;
        uf[i].val = 0;
    }
}

int find(int v) {
    if (v == uf[v].id)
        return v;
    return uf[v].id = find(uf[v].id);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (uf[a].rank < uf[b].rank)
            swap(a,b);
            uf[b].id = a;
            combine(a, b);
            if (uf[a].rank == uf[b].rank)
                uf[a].rank++;
            return true;
    }
    return false;
}

int shortestPath(unordered_map<int, vector<pair<int, int> > > adj, int a, int b) {
    queue<int> q;
    q.push(a);
    unordered_map<int, int> from;
    unordered_map<int, int> cost;
    cost[a] = 0;
    from[a] = a;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].second;
            int nextcost = adj[cur][i].first;
            if (cost.count(next) == 0) {
                cost[next] = cost[cur] + nextcost;
                from[next] = cur;
                q.push(next);
                if (next == b) {
                    return cost[b];
                }
            }
        }
    }
}

vector<pair<int, pair<int, int> > > kruskal(vector<pair<int, pair<int, int> > > v) {
    sort(v.begin(), v.end());

    vector<pair<int, pair<int, int> > > result;
    unordered_map<int, vector<pair<int, int> > > adj;

    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first, b = v[i].second.second;
        int c = v[i].first;
        if (unite(a, b)) {
            result.push_back(make_pair(c, make_pair(a, b)));
            adj[a].push_back(make_pair(c, b));
            adj[b].push_back(make_pair(c, a));
        } else {
            if (shortestPath(adj, a, b) > c) {
                result.push_back(make_pair(c, make_pair(a, b)));
                adj[a].push_back(make_pair(c, b));
                adj[b].push_back(make_pair(c, a));
            }
        }
    }
    return result;
}


bool solve() {
    int N;
    cin >> N;

    build(N);

    vector<pair<int, pair<int, int> > > v;

    if (cin.eof() || !cin.good()) return false;

    int c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (j <= i) continue;
            v.push_back(make_pair(c, make_pair(i, j)));
        }
    }

    auto res = kruskal(v);

    if (res.size() != N) {
        cout << res[0].second.first+1 << " " << res[0].second.second+1 << " " << res[0].first << endl;
    }
    for (auto p: res) {
        cout << p.second.first+1 << " " << p.second.second+1 << " " << p.first << endl;
    }
    cout << endl;

    return true;
}

int main(void) {
    while (solve());
}
