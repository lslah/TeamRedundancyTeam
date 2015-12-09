#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int d[100][100];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> d[i][j];
        }
    }

    for ( int k = 0; k < N ; k ++) {
        for ( int i = 0; i < N ; i ++) {
            for ( int j = 0; j < N ; j ++) {
                d [ i ][ j ] = min(d [ i ][ j ], d [ i ][ k ] + d [ k ][ j ]) ;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            cout << d[i][j] << " ";
        }
        cout << d[i][N-1];
        cout << endl;
    }
}
