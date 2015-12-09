#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100*101;
vector<int> edges[MAXN];

int used[MAXN];
int from[MAXN];

bool bfs(int s) {
    queue<int> q;

    used[s] = 1;
    from[s] = s;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i];

            if (!used[next]) {
                used[next] = used[cur] + 1;
                from[next] = cur;
                q.push(next);
            }
        }
    }
    return true;
}

int M, N;

pair<int, int> coords(int v) {
    return make_pair(v % M, v / M);
}

int main(void) {
    int p,q,x1,y1,x2,y2;
    int ret = scanf("%d %d %d %d %d %d %d %d", &M,&N,&p,&q,&x1,&y1,&x2,&y2);
    assert(8 == ret);
    --x1; --x2; --y1; --y2;

    int posx[] = {p,p,-p,-p,q,q,-q,-q};
    int posy[] = {q,-q,q,-q,p,-p,p,-p};
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int v = x + y*M;
            for (int i = 0; i < 8; i++) {
                int nx = x+posx[i], ny = y+posy[i];
                if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                    int nv = nx + ny*M;
                    edges[v].push_back(nv);
                }
            }
            sort(edges[v].begin(), edges[v].end());
            edges[v].erase(unique(edges[v].begin(), edges[v].end()), edges[v].end());
        }
    }

    int start = x1 + y1*M;
    int target = x2 + y2*M;

    bfs(start);
    if (used[target]) {
        cout << used[target]-1 << endl;
    } else {
        cout << "-1" << endl;
    }
}
