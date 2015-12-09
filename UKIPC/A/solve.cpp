#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const double INF = numeric_limits<double>::max() / 4;

struct MinCostMaxFlow {
    int N;
    VVD cap, flow;
    VVD cost;
    VI found;
    VD dist, pi, width;
    VPII dad;

    MinCostMaxFlow(int N):
    N(N), cap(N, VD(N)), flow(N, VD(N)), cost(N, VD(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(int from, int to, double cap, double cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, double cap, double cost, int dir) {
        double val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k]) {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min((double) cap, width[s]);
        }
    }

    double Dijkstra(int s, int t) {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1) {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++) {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }
        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], (double) INF);
        return width[t];
    }

    pair<double, double> GetMaxFlow(int s, int t) {
        double totflow = 0;
        double totcost = 0;
        while (L amt = Dijkstra(s,t)) {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first) {
                if (dad[x].second == 1) {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                } else {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt*cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};

typedef tuple<int, int, int> hill;
typedef pair<double, int> Edge;
typedef vector<Edge> Adj;
typedef vector<Adj> AdjList;

double dist(hill const &h1, hill const &h2) {
    return
        sqrt( pow((double) get<0>(h1)+get<0>(h2), 2)
            + pow((double) get<1>(h1)+get<1>(h2), 2)
             );
}

unordered_map<int, Edge> dijkstra(AdjList const &graph, int startPoint) {
    unordered_map<int, double> deik;
    unordered_map<int, Edge> result;
    deik[startPoint] = 0;

    unordered_set<int> used;
    used.insert(startPoint);

    unordered_map<int, int> from;
    from[startPoint] = -1;

    set<Edge> deikst;
    deikst.insert(make_pair(deik[startPoint], startPoint));

    while (!deikst.empty()) {
        int cur = deikst.begin()->second;
        double dist = deikst.begin()->first;
        deikst.erase(deikst.begin());
        if (deik[cur] > dist) continue;

        for (Edge v: graph[cur]) {
            int next = v.second;
            double cost = v.first;
            if (used.count(next) == 0 || result[next].first > dist + cost) {
                used.insert(next);
                result[next] = make_pair(dist+cost, cur);
                deikst.insert(make_pair(deik[next], next));
            }
        }
    }

    return result;
}

int main(void) {
    int N, S, T, Q;
    cin >> N >> S >> T >> Q;

    int x, y, h;
    vector<hill> hills(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> h;
        hills[i] = make_tuple(x, y, h);
    }

    vector<int> source(S,0);
    vector<int> town(T,0);
    for (int i = 0; i < S; i++) {
        cin >> source[i];
    }

    for (int i = 0; i < T; i++) {
        cin >> town[i];
    }

    sort(hills.begin(), hills.end(), [](const hill &h1, const hill &h2) -> bool {
        return get<2>(h1) > get<2>(h2);
    });

    // first - length, second vertex
    AdjList edges(N);
    double cost;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            assert(get<2>(hills[i]) >= get<2>(hills[j]));
            if (get<2>(hills[j]) == get<2>(hills[j])) {
                continue;
            }
            cost = dist(hills[i], hills[j]);
            edges[i].push_back(make_pair(cost, j));
        }
    }

    MinCostMaxFlow flow(N+2);
    for (auto s: source) {
        flow.AddEdge(N,s,1,0);
    }
    for (auto t: town) {
        flow.AddEdge(t,N+1,1,0);
    }
    for (auto s: source) {
        auto res = dijkstra(edges, s);
        for (auto t: town) {
            if (res.count(t) != 0) {
                flow.AddEdge(s,t,1,res[t].first);
            }
        }
    }
    auto res = flow.GetMaxFlow(N, N+1);
    cout << res.first << endl;
    cout << res.second << endl;
}
