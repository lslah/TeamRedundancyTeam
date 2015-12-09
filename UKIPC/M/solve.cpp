#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

bool doubleEqual (long double a, long double b) {
    return abs(a - b) < 1e-9;
}

int main(void) {

    int M, N;
    cin >> M >> N;
    vector<long long int> t(M,0);
    vector<long long int> x(N,0);
    vector<long long int> dt(M-1,0), dx(N-1,0);

    for (int i = 0; i < M; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    for (int i = 1; i < M; i++) {
        dt[i-1] = t[i] - t[i-1];
    }


    for (int i = 1; i < N; i++) {
        dx[i-1] = x[i] - x[i-1];
    }

    set<long int> startPoints;
    for (int i = 0; i < (N-M)+1; i++) {
        bool add = true;
        long double q = (long double) dx[i] / (long double) dt[0];
        for (int j = 1; j < M-1; j++) {
            if ( ! doubleEqual(q, (long double) dx[i+j]/ (long double) dt[j]) ) {
                add = false;
                break;
            }

        }
        if (add) startPoints.insert(dx[i]);
    }

    cout << startPoints.size() << endl;
    if (startPoints.size() == 0) return 0;

    auto end = startPoints.end();
    end--;
    for (auto it = startPoints.begin(); it != end; ++it) { 
        printf("%ld ", *it);
    }
    printf("%ld\n", *startPoints.rbegin());


}
