#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    vector<long long> array(N,0);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &array[i]);
    }

    int M;
    scanf("%d", &M);

    vector<pair<int, int> > queries;
    queries.reserve(M);

    for (int i = 0; i < M; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        queries.push_back(make_pair(l, r));
    }

    vector<long long> partial(N+1,0);
    partial_sum(array.begin(), array.end(), partial.begin()+1);

    for (int i = 0; i < M; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        long long summe = partial[r]-partial[l-1];

        cout << summe << endl;
    }
}
