#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

#define _USE_MATH_DEFINES

using namespace std;
int main(void) {
    int N;
    double g;
    cin >> N;
    cin >> g;

    vector<int> x;
    vector<int> as;
    x.resize(N+1);
    as.resize(N+1);
    for (int i = 1; i < N+1; i++) {
        int y;
        cin >> y;
        x[i] = y;
        cin >> y;
        as[i] = y;
    }

    for (int i = 1; i < N+1; i++) {
        vector<double> a;
        vector<double> t;
        vector<double> v;
        a.resize(N+1);
        t.resize(N+1);
        v.resize(N+1);
        for (int j = 0; j < i; j++) {
            v[j] = 0;
        }
        for (int j = i; j < N+1; j++) {
            a[j] = g*cos((double)as[j] / (double)180 * acos(-1.0));

            t[j] = - (double) v[j-1] / a[j] + sqrt((double) (v[j-1]*v[j-1]) / (a[j]*a[j]) + 2*(double)x[j]/a[j]);
            v[j] = v[j-1] + a[j]*t[j];
        }
        printf("%lf\n", v[N]);
    }
}
