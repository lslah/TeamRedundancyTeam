#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int,unordered_set<int> > graph;
unordered_map<int,int> coins;
int maxCoins;

unordered_set<int> intersect(unordered_set<int> s1, unordered_set<int> s2) {
    unordered_set<int> res;
    res.reserve(s1.size());
    for (auto el: s1) {
        if (1 == s2.count(el)) {
            res.insert(el);
        }
    }
    return res;
}

int value(unordered_set<int> R) {
    int val = 0;
    for (auto p: R) {
        val += coins[p];
    }
    return val;
}

void BronKerbosch1(unordered_set<int> R, unordered_set<int> P, unordered_set<int> X) {
    if (P.empty() && X.empty()) {
        // R is maximal clique
        maxCoins = max(value(R), maxCoins);
        return;
    }
    for (auto v = P.begin(); v != P.end();) {
        unordered_set<int> nR(R);
        nR.insert(*v);
        auto N_v = graph[*v];
        auto nP = intersect(P, N_v);
        auto nX = intersect(X, N_v);
        BronKerbosch1(nR, nP, nX);
        X.insert(*v);
        v = P.erase(v);
    }
}

bool solve() {
    int numV, numE;
    cin >> numV >> numE;

    if (!cin.good() || cin.eof()) return false;

    coins.clear();
    coins.reserve(numV);
    graph.clear();
    graph.reserve(numV);
    maxCoins = 0;

    unordered_set<int> R, P, X;
    for (int i = 0; i < numV; i++) {
        cin >> coins[i];
        P.insert(i);
    }

    int p1, p2;
    for (int i = 0; i < numE; i++) {
        cin >> p1 >> p2;
        --p1; --p2;
        graph[p1].insert(p2);
        graph[p2].insert(p1);
    }

    BronKerbosch1(R,P,X);

    cout << maxCoins << endl;

    return true;
}

int main(void) {
    while (solve()) {}
}
