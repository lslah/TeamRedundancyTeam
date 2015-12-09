#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N_buttons, t;
    cin >> N_buttons >> t;

    vector<int> buttons(N_buttons);
    for (int i = 0; i < N_buttons; i++) {
        cin >> buttons[i];
    }

    if (t == 0) {
        cout << "0 0" << endl;
        return;
    }

    vector<int> count(3601,0);
    queue<int> q;
    q.push(0);
    int pos;
    int newpos;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (int button: buttons) {
            newpos = min(3600, pos+button);
            newpos = max(0, newpos);
            if (newpos == 0) continue;
            if (count[newpos] == 0) {
                count[newpos] = count[pos]+1;
                q.push(newpos);
                if (newpos == t) {
                    cout << count[newpos] << " 0" << endl;
                    return;
                }
            }
        }
    }

    for (int i = t+1; i <= 3600; i++) {
        if (count[i] != 0) {
            cout << count[i] << " " << i-t << endl;
            break;
        }
    }
}

int main(void) {
    int N_cases;
    cin >> N_cases;

    for (int i = 0; i < N_cases; i++) {
        solve();
    }
}

