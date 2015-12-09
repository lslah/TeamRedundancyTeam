#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20001;
vector<int> edges[MAXN];
int color[MAXN];

void dfs_color ( int v , int comp = 1) {
    color [ v ] = comp ;
    for ( int i = 0; i < edges [ v ]. size () ; i ++) {
        int next = edges [ v ][ i ];
        if (! color [ next ]) {
            dfs_color ( next , comp ) ;
        }
    }
}

vector < int > color_repr ;
int find_cc ( int n ) {
    int cnt = 0;
    for ( int i = 0; i < n ; i ++) {
        if (! color [ i ]) {
            color_repr . push_back ( i ) ;
            cnt ++;
            dfs_color (i , cnt ) ;
        }
    }
    return cnt ;
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
        edges[v2].push_back(v1);
    }

    fill(color, color+N, 0);

    printf("%d\n", find_cc(N));
}
