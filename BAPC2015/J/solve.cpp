#include <bits/stdc++.h>

using namespace std;

void solve() {
    bool matrix[200][400] = {0};

    string line;
    getline(cin, line);

    char current;
    int xpos = 0, ypos = 100;
    int maxX = 0, maxY = 100, minY = 100;
    // 0 - East
    // 1 - South
    // 2 - West
    // 3 - North
    int xdir = 1;
    int ydir = 0;
    for (int i = 0; i < line.size(); i++) {
        current = line[i];
        if (current == 'L') {
            int swap = xdir;
            xdir = ydir;
            ydir = -swap;
        }
        else if (current == 'R') {
            int swap = xdir;
            xdir = -ydir;
            ydir = swap;
        } else if (current == 'B') {
            xdir = -xdir;
            ydir = -ydir;
        }

        xpos += xdir;
        ypos += ydir;

        maxX = max(maxX, xpos);
        maxY = max(maxY, ypos);
        minY = min(minY, ypos);

        matrix[xpos][ypos] = true;
    }

    int cols = maxX + 2; 
    int rows = maxY - minY + 3;
    cout << rows << " " << cols << endl;
    for (int j = minY-1; j <= maxY+1; j++) {
        for (int i = 0; i <= maxX+1; i++) {
            if (matrix[i][j]) {
                cout << ".";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }

}

int main(void) {
    int N_cases;
    cin >> N_cases;
    cout << N_cases << endl;

    string line;
    getline(cin, line);
    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

