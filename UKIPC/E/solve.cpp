#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>


using namespace std;

int f(int t, vector<int> &partial) {
    int mini = partial[t-1];
    for (int i = 0; i < partial.size()-t; i++) {
        mini = min(mini, partial[i+t] - partial[i]);
    }
    return mini;
}

int main(void) {
    int T;
    double e, x;

    cin >> T;
    cin >> e >> x;

    vector<int> v(T,0);
    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    vector<int> partial(T,0);
    partial_sum(v.begin(), v.end(), partial.begin());
    double K = e * (x*x*60*60);
    double C;

    double minimum = numeric_limits<double>::infinity();

    for (int t = T; t > 0; t--) {
        C = K/(double)t;
        //if (C > minimum) {
        //    cout << minimum << endl;
        //    return 0;
        //}

        minimum = min(minimum, C + f(t, partial));
    }
    cout << minimum << endl;
}
