#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BIGM = 9999999;

int main(void) {
    int N_filme;
    int M_horror;
    int K_similar;

    cin >> N_filme;
    cin >> M_horror;
    cin >> K_similar;

    vector<vector<int> > adj(N_filme);

    queue<int> pqueue;
    vector<int> index(N_filme, BIGM);
    int tmp;
    for (int i = 0; i < M_horror; i++) {
        cin >> tmp;
        index[tmp] = 0;
        pqueue.push(tmp);
    }

    for (int i = 0; i < K_similar; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    while (!pqueue.empty()) {
        int v = pqueue.front();
        pqueue.pop();
        for (auto w: adj[v]) {
            if (index[w] > index[v]+1) {
                index[w] = index[v]+1;
                pqueue.push(w);
            }
        }
    }

    int max_index = -1, max_value = -1;
    for (int i = 0; i < N_filme; i++) {
        if (index[i] > max_value) {
            max_value = index[i];
            max_index = i;
        }
    }

    cout << max_index << endl;
}
