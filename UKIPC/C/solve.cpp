#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

struct classcomp {
  bool operator() (const pair<int,string>& lhs, const pair<int,string>& rhs) const
  {
      if (lhs.first < rhs.first) {
          return true;
      } else if (lhs.first > rhs.first) {
          return false;
      } else {
          if (lhs.second > rhs.second) {
              return true;
          } else {
              return false;
          }
      }
  }
};

int main(void) {

    unordered_map<string, set<string> > userWords;
    unordered_map<string, int> wordCounts;

    int N;
    cin >> N;

    string line;
    string word, name;
    getline(cin, line);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        istringstream iss (line);
        iss >> name;
        while (iss >> word) {
            userWords[name].insert(word);
            wordCounts[word]++;
        }
    }

    set<string> allHaveThis = userWords.begin()->second;
    for (auto it = allHaveThis.begin(); it != allHaveThis.end();) {
        bool erased = false;
        for (auto user: userWords) {
            set<string> hisWords = user.second;
            if (0 == hisWords.count(*it)) {
                it = allHaveThis.erase(it);
                erased = true;
                break;
            }
        }
        if (!erased) ++it;
    }

    if (allHaveThis.empty()) {
        cout << "ALL CLEAR" << endl;
    }

    set<pair<int, string>, classcomp> withCounts;
    for (auto word: allHaveThis) {
        withCounts.insert(make_pair(wordCounts[word], word));
    }

    for (auto it = withCounts.rbegin(); it != withCounts.rend(); ++it) {
        cout << it->second << endl;
    }
}
