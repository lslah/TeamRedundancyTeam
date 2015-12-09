#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef set<set<int> > Chaingroup;

bool contains(set<int> a, set<int> b) {
    for (auto it: b) {
        if (a.count(it) == 0) {
            return false;
        }
    }
    return true;
}

Chaingroup makeBigger(Chaingroup &current, unordered_map<int,int> &vessels, unordered_map<int,set<int> > &graph) {
    Chaingroup copy;
    Chaingroup result;
    for (auto cg: current) {
        set<int> members = cg;

        for (auto p: graph) {
            int point = p.first;
            set<int> adjacentTo = p.second;
            if (members.count(point) != 0) { continue; }

            if (contains(adjacentTo, members)) {
                // adjacentTo contains all members
                set<int> newCG(members);
                newCG.insert(point);
                result.insert(newCG);

                for (auto p: newCG) {
                    set<int> u(newCG);
                    u.erase(p);
                }
            }
        }
    }
    return result;
}

int cost(set<int> chain, unordered_map<int,int> vessels) {
    int res = 0;
    for (auto el: chain) {
        res += vessels[el];
    }
    return res;
}

bool solve() {
    int v, e;

    cin >> v;
    cin >> e;

    if (cin.eof()) return false;

    unordered_map<int,int> vessels;
    unordered_map<int,set<int> > graph;

    for (int i = 1; i <= v; i++) {
        cin >> vessels[i];
    }

    int s1, s2;
    Chaingroup cg2;

    for (int i = 0; i < e; i++) {
        cin >> s1;
        cin >> s2;
        graph[s1].insert(s2);
        graph[s2].insert(s1);
        set<int> g({s1,s2});
        cg2.insert(g);
    }

    for (auto it = graph.begin(); it != graph.end(); ++it) {
        if(it->second.size() < 2) {
            it = graph.erase(it);
        }
    }

    auto cg3 = makeBigger(cg2, vessels, graph);

    for (auto it = graph.begin(); it != graph.end(); ++it) {
        if(it->second.size() < 3) {
            it = graph.erase(it);
        }
    }

    auto cg4 = makeBigger(cg3, vessels, graph);

    Chaingroup all(cg2);
    all.insert(cg3.begin(), cg3.end());
    all.insert(cg4.begin(), cg4.end());

    //vector<int> maxCosts;

    //if (cg1.size() > 0)
    //    maxCosts.push_back(maxi(cg1));

    //if (cg2.size() > 0)
    //    maxCosts.push_back(maxi(cg2));
    //if (cg3.size() > 0)
    //    maxCosts.push_back(maxi(cg3));
    //if (cg.size() > 0)
    //    maxCosts.push_back(maxi(cg));


    //auto max = max_element(maxCosts.begin(), maxCosts.end());

    //cout << *max << endl;

    int maxi = 0;
    for(set<int> chain: all) {
        int c = cost(chain, vessels);
        maxi = max(c, maxi);
    }

    cout << maxi << endl;

    //for_each(all.begin(), all.end(), [](set<int> g) {
    //    for_each(g.begin(), g.end(), [](int x) {
    //        cout << x << " ";
    //    });
    //    cout << endl;
    //});

    
    return true;
}

int main(void) {
    while (solve()) {}
}
