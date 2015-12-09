#include <iostream>
#include <vector>

using namespace std;

bool gerade(vector<int> A) {
    int N = A.size();
    vector<bool> seen(N, false);

    int n_cyclen = 0;
    for (int i = 0; i < N; i++) {
        if (seen[i]) continue;


        int j = A[i];
        seen[i] = true;
        while (i != j) {
            seen[j] = true;
            j = A[j];
        }
        n_cyclen++;
    }

    return ((N - n_cyclen) % 2 == 0);
}

int main(void) {
    int N;
    cin >> N;
    vector<int> pos(N, 0);
    vector<int> A(N,0);
    vector<int> B(N,0);
    vector<bool> seen;

    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        A[i] = value-1;
    }

    for (int i = 0; i < N; i++) {
        cin >> value;
        B[i] = value-1;
    }

    if (gerade(A) == gerade(B)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
