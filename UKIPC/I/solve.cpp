#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char beginning(char a) {
    vector<pair<int,char> > table;
    table.push_back(make_pair(1,'b'));
    table.push_back(make_pair(2,'c'));
    table.push_back(make_pair(4,'d'));
    table.push_back(make_pair(8, 'g'));
    table.push_back(make_pair(11,'k'));
    table.push_back(make_pair(14,'n'));
    table.push_back(make_pair(17,'p'));
    table.push_back(make_pair(27,'t'));
    int pos = a - 'a';
    for (auto p: table) {
        if (p.first >= pos) {
            return p.second;
        }
    }
}

char secondWithFirstCase(char a, char b) {
    if (isupper(a) ) {
        return toupper(b);
    } else {
        return tolower(b);
    }
}

void ende(char x, char last) {
    string special = "bcdgknpt";
    if (string::npos != special.find(tolower(last))) {
        if (x-'a' < 8) {
            cout << "ah";
        } else if (x-'a' < 18) {
            cout << "oh";
        } else {
            cout << "uh";
        }
    }
}

int main(void) {
    vector<string> words;
    string word;

    while (cin >> word) {
        words.push_back(word);
    }

    int count = 0;
    for (auto word: words) {
        count++;
        char x = beginning(tolower(word[0]));
        cout << secondWithFirstCase(word[0], x);

        auto it = word.begin()+1;
        while( it != word.end() && *it != '-') {
            cout << *it;
            ++it;
        }

        if (it == word.end()) {
            if (word.size() == 1) {
                ende(x,'b');
            }  else {
                ende(*word.rbegin(),*word.rbegin());
            }
            if (count != words.size()) {
                cout << " ";
            }
            continue;
        }
        it++;

        string special = "bcdgknpt";

        while( it != word.end() ) {
            if (*it == '-') {
                ++it;
                continue;
            }
            if (special.find(tolower(*it)) != string::npos) {
                cout << secondWithFirstCase(*it, x);
            } else {
                cout << *it;
            }
            ++it;
        }

        ende(x,*word.rbegin());

        if (count != words.size()) {
            cout << " ";
        }
    }
    cout << endl;
}
