#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <tuple>

using namespace std;

typedef int vertex_t;
typedef int weight_t;
typedef vector<vector<pair<weight_t, vertex_t> > > AdjList;

typedef set<pair<weight_t, vertex_t>> PQueue;

const weight_t maxWeight = numeric_limits<int>::max();

vector<tuple<int, int, int> > prim(const AdjList &adj, vertex_t start) {
    int N = adj.size();
    vector<weight_t> weight(N, maxWeight);
    vector<vertex_t> pred(N, -1);

    weight[start] = 0;
    PQueue Q;
    for (int i = 0; i < N; i++) {
        Q.insert(make_pair(weight[i], i));
    }
    
    weight_t dist;
    vertex_t v;
    weight_t edge_length;
    vertex_t target;

    vector<tuple<vertex_t, vertex_t, weight_t> > result;

    while (!Q.empty()) {
        dist = Q.begin()->first;
        v = Q.begin()->second;
        Q.erase(Q.begin());

        if (pred[v] != -1) result.push_back(make_tuple(v,pred[v],dist));

        auto &neighbors = adj[v];
        for (auto it = neighbors.cbegin(); it != neighbors.cend(); ++it) {
            edge_length = it->first;
            target = it->second;
            auto a = Q.find(make_pair(weight[target], target));
            if (a != Q.end() && weight[target] > edge_length) {
                Q.erase(a);
                Q.insert(make_pair(edge_length, target));
                weight[target] = edge_length;
                pred[target] = v;
            }
        }
    }

    return result;
}

bool solve() {
    int N;
    cin >> N;

    AdjList adjList(N);

    if (cin.eof() || !cin.good()) return false;

    int c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if (j <= i) continue;
            adjList[i].push_back(make_pair(c, j));
            adjList[j].push_back(make_pair(c, i));
        }
    }

    auto res = prim(adjList, 0);
    for (auto p: res) {
        cout << get<0>(p)+1 << " " << get<1>(p)+1 << " " << get<2>(p) << endl;
    }
    cout << endl;

    return true;
}

int main(void) {
    while (solve());
}
