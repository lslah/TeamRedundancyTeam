#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef std::vector<int> ints;

int sum = 0;

void insert( ints &cont, int value ) {
    ints::iterator it = std::lower_bound( cont.begin(), cont.end(), value, std::greater<int>() ); // find proper position in descending order
    cont.insert( it, value ); // insert before iterator it
}

void nextCookie(set<int> &cookies) {
    int median = sum/cookies.size();
    auto it = cookies.upper_bound(median);

    if (it == cookies.end()) {
        --it;
    }

    if (it != cookies.begin()) {
        --it;
        if (*it != median) {
            ++it;
        }
    }

    sum -= *it;
    cout << *it << endl;
    cookies.erase(it);
}

int main(void) {
    set<int> cookies;

    char x;
    while (true) {
        cin >> x;
        if (cin.eof()) return 0;

        if (x == '#') {
            nextCookie(cookies);
        } else {
            int value = x - '0';
            cookies.insert(value);
            sum += value;
        }
    }
}
