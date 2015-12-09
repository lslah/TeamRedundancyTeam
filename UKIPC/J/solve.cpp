#include <bits/stdc++.h>

using namespace std;

void print_map(int image[60][60], int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << image[j][i];
        }
        cout << endl;
    }
}

void processGuard(int map[60][60], int image[60][60], pair<int, int> pos, int C, int R) {
    int x = pos.first;
    int y = pos.second;
    image[x][y] = 0;
    for (int i = x; i < C; i++) { if (map[i][y] == 1) {image[i][y] = 0;} else {break;} }
    for (int i = x; i >= 0; i--) { if (map[i][y] == 1) {image[i][y] = 0;} else {break;} }
    for (int i = y; i < R; i++) { if (map[x][i] == 1) {image[x][i] = 0;} else {break;} }
    for (int i = y; i >= 0; i--) { if (map[x][i] == 1) {image[x][i] = 0;} else {break;} }
}


int main(void) {
    int R, C;
    cin >> R >> C;
    pair<int, int> bed;
    pair<int, int> fridge;

    int image[60][60];

    int x1, x2, x3, x4;

    cin.ignore(100,'(');
    cin >> x1 >> x2;
    cin.ignore(100,'(');
    cin >> x3 >> x4;
    cin.ignore(100,')');
    bed.first = x1-1;
    bed.second = x2-1;
    fridge.first = x3-1;
    fridge.second = x4-1;

    string line;
    getline(cin, line);
    for (int i = 0; i < R; i++) {
        getline(cin, line);
        for (int j = 0; j < C; j++) {
            if (line[j] == '.') {
                image[j][i] = true;
            } else {
                image[j][i] = false;
            }
        }
    }

    int p;
    cin >> p;

    vector<pair<int, int> > guard[p];
    for (int i = 0; i < p; i++) {
        int stepN;
        cin >> stepN;
        int x, y;
        for (int j = 0; j < stepN; j++) {
            cin.ignore(100,'(');
            cin >> x >> y;
            guard[i].push_back(make_pair(x-1,y-1));
        }
        cin.ignore(100,')');
    }

    int maps[120][60][60];
    for (int i = 0; i < 120; i++){
        for (int k = 0; k < C; k++) {
            for (int j = 0; j < R; j++) {
                maps[i][k][j] = 1;
            }
        }
        for (int j = 0; j < p; j++) {
            int m = guard[p].size();
            int n = max((m-1)*2, 1);
            int t = i%n;
            if (t > m) {
                t = 2*(m-1)-t;
            }
            processGuard(image, maps[i], guard[j][t], C, R);
        }
        print_map(maps[i],C,R);
    }
}
