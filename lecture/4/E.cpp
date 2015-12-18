#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent, capacity, need;
vector<vector<int> > childs;

vector<int> getlist(int id) {
    vector<int> result;
    for (int child =0; child < childs[id].size(); ++child) {
        vector<int> x = getlist(childs[id][child]);
        result.insert(result.begin(), x.begin(), x.end());
    }

    if (id == 0) return result;

    if (capacity[id] >= need[id]) {
        result.push_back(need[id]);
    }

    sort(result.begin(), result.end());
    vector<int> res2;
    int sum = 0;
    for (int i = 0; i < result.size(); i++) {
        sum += result[i];
        if (sum > capacity[id]) {
            break;
        }
        res2.push_back(result[i]);
    }
    return res2;
}

int main (void) {
    int N_houses;

    cin >> N_houses;
    if (cin.eof()) return 0;

    childs.resize(N_houses+1);
    parent.resize(N_houses+1);
    need.resize(N_houses+1);
    capacity.resize(N_houses+1);

    int p, c, n;
    for (int i = 1; i <= N_houses; i++) {
        cin >> parent[i];
        cin >> need[i];
        cin >> capacity[i];

        childs[parent[i]].push_back(i);
    }

    vector<int> result = getlist(0);
    cout << result.size() << endl;
}
