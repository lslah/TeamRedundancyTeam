#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
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
            } else if (used[next] && from[cur] != next) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    int N, M;
    int ret;
    ret = scanf("%d %d\n", &N, &M);
    assert(2 == ret);

    fill(used, used+N, 0);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        ret = scanf("%d %d\n", &v1, &v2);
        assert(2 == ret);
        assert(1 <= v1 && v1 <= N);
        assert(1 <= v2 && v2 <= N);
        --v1; --v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }


    if (false == bfs(0)) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (0 == used[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
