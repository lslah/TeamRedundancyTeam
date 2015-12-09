#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > AdjList;

const int MAXN = 100000;
vector<int> edges[MAXN];

int used[MAXN];

// Returns whether the current component of connectivity contains a cycle or
// not.  true means it contains a cycle.
bool dfs(int v) {
    used[v] = 1;

    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];

        if (used[next] == 1) {
            return true;
        } else if (used[next] == 0) {
            if (dfs(next)) {
                return true;
            }
        }
    }

    used[v] = 2;
    return false;
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

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        if (dfs(i)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}
