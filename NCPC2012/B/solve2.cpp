#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    int N;
    cin >> N;
    vector<int> pos(N, 0);
    vector<int> l2;
    l2.reserve(N);

    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        pos[value-1] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> value;
        l2[i] = value-1;
    }

    int count = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (pos[l2[i]] > pos[l2[j]]) {
                count++;
            }
        }
    }

    if (count % 2 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
