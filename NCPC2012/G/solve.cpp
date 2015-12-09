#include <iostream>
#include <vector>

using namespace std;

struct Gerade {
    int x1, y1;
    int x2, y2;
    pair<int, int> anstieg() {
        return make_pair(x1-x2, y1-y2);
    }
};

typedef pair<int,int> Vector;

bool verschiedener_anstieg(Gerade g1, Gerade g2) {
    auto a1 = g1.anstieg();
    auto a2 = g2.anstieg();
    int a = a1.first; // a
    int b = a1.second; // b
    int c = a2.first; // c
    int d = a2.second; // d

    return (a*d - b*c != 0);
}

bool echt_parallel(Gerade g1, Gerade g2) {
    auto anstieg = g1.anstieg();
    int a = g1.x1 - g2.x1;
    int b = g1.y1 - g2.y1;
    int c = anstieg.first; 
    int d = anstieg.second;

    return (a*d - b*c != 0);
}

int main(void) {
    int W, N_g;

    cin >> W;
    cin >> N_g;
    vector<Gerade> geraden;

    for (int i = 0; i < N_g; i++) {
        Gerade a;
        cin >> a.x1;
        cin >> a.y1;
        cin >> a.x2;
        cin >> a.y2;
        geraden.push_back(a);
    }

    bool alle_parallel = true;
    int different_geraden = 0;
    for (int i = 0; i < N_g; i++) {
        bool different = true;
        for (int j = i+1; j < N_g; j++) {
            if (verschiedener_anstieg(geraden[i], geraden[j])) {
                alle_parallel = false;
            } else {
                if (!echt_parallel(geraden[i], geraden[j])) {
                    different = false;
                }
            }
        }

        if (different) {
            different_geraden++;
        }
    }

    int result;
    if (!alle_parallel) {
        result = max(0, (W+1)/2 - different_geraden);
    } else {
        if (different_geraden+1 >= W) {
            result = 0;
        } else {
            result = max(1, (W+1)/2 - different_geraden);
        }
    }

    cout << result << endl;
}
