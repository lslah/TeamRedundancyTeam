#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int sum = 0;

priority_queue<int, vector<int>, less<int> > above;
priority_queue<int, vector<int>, greater<int> > below;

void insert(int value) {
    if (value >= above.top()) {
        above.push(value);
        if (above.size() > below.size() + 1) {
            below.push(above.top());
            above.pop();
        }
    } else {
        below.push(value);
        if (above.size() < below.size()) {
            above.push(below.top());
            below.pop();
        }
    }
}

int main(void) {
    string x;
    int value;
    while (true) {
        cin >> x;
        if (cin.eof()) return 0;

        if (x.compare("#") == 0) {
            cout << above.top() << endl;
            above.pop();
            if (above.size() < below.size()) {
                above.push(below.top());
                below.pop();
            }
        } else {
            value = atoi(x.c_str());
            if (above.empty()) {
                above.push(value);
            } else {
                insert(value);
            }
        }
    }
}
