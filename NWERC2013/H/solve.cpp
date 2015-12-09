#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool solve() {

    int n_cars;
    cin >> n_cars;

    if (cin.eof() || !cin.good()) return false;

    vector<tuple<int, int, double> > car_times;
    vector<pair<int, int> > sort_by_start_time;
    vector<pair<double, int> > sort_by_end_time;
    car_times.reserve(n_cars);
    int t1, v;
    double t2;
    vector<bool> done(n_cars, false);
    for (int i = 0; i < n_cars; i++) {
        cin >> t1;
        cin >> v;
        t2 = t1 + 100.0/v;
        car_times.push_back(make_tuple(t1, v, t2));
        sort_by_start_time.push_back(make_pair(t1, i));
        sort_by_end_time.push_back(make_tuple(t2, i));
    }

    sort(sort_by_start_time.begin(), sort_by_start_time.end());
    sort(sort_by_end_time.begin(), sort_by_end_time.end());

    int carId;
    double endTime;
    double colOrt;
    for (auto it = sort_by_start_time.begin(); it != sort_by_start_time.end(); ++it) {
        carId = it->second;
        endTime = get<2>(car_times[carId]);
        vector<tuple<int, int, double> > currentCars;
        vector<double> currentCollisions;
        done[carId] = true;
        for (auto it2 = sort_by_end_time.begin(); it2 != sort_by_end_time.end(); ++it) {
            if (it2->first > endTime) break;
            if (done[it2->second]) continue;
            done[it2->second] = true;
            myCar = car_times[it2->second];
            for (auto colCar: currentCars) {
                if (get<0>(myCar) < get<0>(colCar)) {
                    colOrt = 
                } else {
                }
            }
            currentCars.push_back(myCar);
        }
    }

    return true;
}

int main(void) {
    while (solve()) {}
}
