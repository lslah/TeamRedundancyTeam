#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;

vector<double> costs[MAXN];
vector<int> edges[MAXN];
int used[MAXN];
double prim[MAXN];
int X[MAXN], Y[MAXN];

double sq(int x) { return x*x; }

double kruskal(int s) {
    set<pair<double, int> > primst;

    used[s] = 1;
    prim[s] = 0;
    primst.insert(make_pair(prim[s], s));
    double sumcost = 0;

    while (!primst.empty()) {
        int cur = primst.begin()->second;
        primst.erase(primst.begin());
        used[cur] = 2;
        sumcost += prim[cur];

        for (int j = 0; j < edges[cur].size(); j++) {
            int next = edges[cur][j];
            double cost = costs[cur][j];
            if (used[next] == 0 || used[next] == 1 && prim[next] > cost) {
                used[next] = 1;
                primst.erase(make_pair(prim[next], next));
                prim[next] = cost;
                primst.insert(make_pair(prim[next], next));
            }
        }
    }

    return sumcost;
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            double cost = sqrt(sq(X[i]-X[j])+sq(Y[i]-Y[j]));
            edges[i].push_back(j);
            costs[i].push_back(cost);
            edges[j].push_back(i);
            costs[j].push_back(cost);
        }
    }

    printf("%.6lf\n", kruskal(0));
}
