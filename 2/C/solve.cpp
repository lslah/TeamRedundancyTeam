#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > AdjList;

const int MAXN = 100000;
vector<int> edges[MAXN];

int used[MAXN];
int path[MAXN];

vector<int> cyclepath;

bool dfs_cycle(int v, int h = 0) {
    used[v] = 1;
    path[h] = v;

    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];

        if (used[next] == 1 && cyclepath.empty()) {
            int curh = h;
            while (path[curh] != next) {
                curh--;
            }

            while (curh <= h) {
                cyclepath.push_back(path[curh]);
                curh++;
            }

            return false;
        } else if (used[next] == 0) {
            if (!dfs_cycle(next, h+1)) {
                return false;
            }
        }
    }

    used[v] = 2;
    return true;
}

int main(void) {
    int N, M;
    int ret;
    ret = scanf("%d %d\n", &N, &M);
    assert(2 == ret);

    for (int i = 0; i < M; i++) {
        int v1, v2;
        ret = scanf("%d %d\n", &v1, &v2);
        assert(2 == ret);
        assert(1 <= v1 && v1 <= N);
        assert(1 <= v2 && v2 <= N);
        --v1; --v2;
        edges[v1].push_back(v2);
    }

    fill(used, used+N, 0);
    fill(path, path+N, 0);

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        if (!dfs_cycle(i)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

}
