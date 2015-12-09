#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    int N;

    cin >> N;

    vector<char> line;
    char x;
    while (true) {
        cin >> x;
        if (cin.eof()) break;
        line.push_back(x);
    }

    int count = 0;

    int i;
    int diff = 0;
    while (line.size() > 1) {
        auto c1 = line.begin();
        auto c2 = line.begin()+1;

        if (abs(diff) > N) {
            cout << count-1 << endl;
            return 0;
        }

        if (diff > 0) {
            if (*c1 == 'W') {
                diff--;
                line.erase(c1);
            } else if (*c2 == 'W') {
                diff--;
                line.erase(c2);
            } else {
                diff++;
                line.erase(c1);
            }
        } else {
            if (*c1 == 'M') {
                diff++;
                line.erase(c1);
            } else if (*c2 == 'M') {
                diff++;
                line.erase(c2);
            } else {
                diff--;
                line.erase(c1);
            }
        }

        count++;
    }

    int change = line[0] == 'W' ? -1 : 1;
    if (abs(diff + change) > N) {
        cout << count << endl;
    } else {
        cout << count+1 << endl;
    }
}
