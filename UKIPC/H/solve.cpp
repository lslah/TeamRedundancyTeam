#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<double> x(N,0);
    vector<double> h(N,0);
    vector<pair<double, double> > pairs;
    vector<double> left(N,0);
    vector<double> right(N,0);

    for (int i = 0; i < N; i++) {
        double x_, h_;
        cin >> x_;
        cin >> h_;
        pairs.push_back(make_pair(x_, h_));
    }
    //sort(pairs.begin(), pairs.end());
    for (int i = 0; i < N; i++) {
        x[i] = pairs[i].first;
        h[i] = pairs[i].second;
    }


    vector<int> important;
    double maxH = h[0];
    for (int i = 0; i < N; i++) {
        double hour = 6;
        double dx, dh, tmp;
        vector<int>::iterator imin = important.end();
        if (!important.empty()) {
            for (auto it = important.rbegin(); it != important.rend(); ++it) {
                int im = *it;
                if (h[im] <= h[i]) {
                    imin = it.base();
                    imin--;
                    continue;
                }
                dx = x[i] - x[im];
                dh = h[im] - h[i];
                tmp = (1 - atan(dh/dx) * (2 / acos(-1.0))) * 6;
                if (tmp <= hour) {
                    hour = tmp;
                    imin = it.base();
                } else {
                    break;
                }
            }
            important.erase(imin, important.end());
        }

        important.emplace_back(i);

        left[i] = hour;
    }

    important.clear();
    maxH = h[N-1];
    for (int i = N-1; i >= 0; i--) {
        double hour = 6;
        double dx, dh, tmp;
        vector<int>::iterator imin = important.end();
        if (!important.empty()) {
            for (auto it = important.rbegin(); it != important.rend(); ++it) {
                int im = *it;
                if (h[im] <= h[i]) {
                    imin = it.base();
                    imin--;
                    continue;
                }
                dx = x[im] - x[i];
                dh = h[im] - h[i];
                tmp = (1 - atan(dh/dx) * (2 / acos(-1.0))) * 6;
                if (tmp <= hour) {
                    hour = tmp;
                    imin = it.base();
                } else {
                    break;
                }
            }
            important.erase(imin, important.end());
        }

        important.emplace_back(i);

        right[i] = hour;
    }

    for (int i = 0; i < N; i++) {
        printf("%lf\n", left[i]+right[i]);
    }
}
