#include <bits/stdc++.h>

using namespace std;

struct Cross {
    pair<int, int> s1, s2;
    bool v1, v2;

    int next(int from) {
        if (s1.first == from) { v1 = true; return s1.second; }
        if (s1.second == from) { v1 = true; return s1.first; }

        if (s2.first == from) { v2 = true; return s2.second; }
        if (s2.second == from) { v2 = true; return s2.first; }

        assert(false);
    }
    
    bool done() {
        return v1 && v2;
    }
};

void solve() {
    int N;
    int g;
    cin >> N >> g;

    vector<Cross> cross(N);

    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        cross[i].s1 = make_pair(a-1, c-1);
        cross[i].s2 = make_pair(b-1, d-1);
        cross[i].v1 = false;
        cross[i].v2 = false;

    }

    int nr_cycles = 0;
    int last_pos;
    queue<int> q;
    int pos = g - 1;
    last_pos = pos;
    cross[pos].v1 = true;
    for (int j = cross[pos].s1.first; j != pos; ) {
        int swap = j;
        j = cross[j].next(last_pos);
        if (!cross[swap].done()) {
            q.push(swap);
        }
        last_pos = swap;
    }

    last_pos = pos;
    cross[pos].v2 = true;
    for (int j = cross[pos].s2.first; j != pos; ) {
        int swap = j;
        j = cross[j].next(last_pos);
        if (!cross[swap].done()) {
            q.push(swap);
        }
        last_pos = swap;
    }

    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        if (!cross[pos].v1) {
            last_pos = pos;
            cross[pos].v1 = true;
            for (int j = cross[pos].s1.first; j != pos; ) {
                int swap = j;
                j = cross[j].next(last_pos);
                if (!cross[swap].done()) {
                    q.push(swap);
                }
                last_pos = swap;
            }
            nr_cycles++;
        }

        if (!cross[pos].v2) {
            last_pos = pos;
            cross[pos].v2 = true;
            for (int j = cross[pos].s2.first; j != pos; ) {
                int swap = j;
                j = cross[j].next(last_pos);
                if (!cross[swap].done()) {
                    q.push(swap);
                }
                last_pos = swap;
            }
            nr_cycles++;
        }
    }

    cout << nr_cycles << endl;

}

int main(void) {
    int N_cases;
    cin >> N_cases;

    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

