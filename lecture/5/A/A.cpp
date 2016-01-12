#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;

int used[MAXN];
int prim[MAXN];
vector < pair < int, int > > edges[MAXN];

int solve();
int build(int i, int j, int n, int m, int p1, int p2);


int main(){
    int n,m,p1,p2;

    cin >> n >> m >> p1 >> p2;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            build(i, j, n, m, p1, p2);
        }
    }

    cout << solve() << endl;
}


int build(int i, int j, int n, int m, int p1, int p2){
    int calc;
    if (i != n - 1){
        calc = ((i + 1)*(i + 2) + p1*(j + 1)*(j + 1)) % p2;
        edges[i*m + j].push_back(make_pair((i + 1)*m + j, calc));
        edges[(i + 1)*m + j].push_back(make_pair(i*m + j, calc));
    }
    if (i != n - 1 && j != m - 1){
        calc = ((i + 1)*(i + 2) + p1*(j + 1)*(j + 2)) % p2;
        edges[i*m + j].push_back(make_pair((i + 1)*m + j + 1, calc));
        edges[(i + 1)*m + j + 1].push_back(make_pair(i*m + j, calc));
    }
    if (j != m - 1){
        calc = ((i + 1)*(i + 1) + p1*(j + 1)*(j + 2)) % p2;
        edges[i*m + j].push_back(make_pair(i*m + j + 1, calc));
        edges[i*m + j + 1].push_back(make_pair(i*m + j, calc));
    }
    return 1;
}


int solve(){
    
    set < pair < int, int > > primset;
    
    used[0] = 1;
    primset.insert(make_pair(0, 0));
    int sumcost = 0;
    
    while (!primset.empty()){
        int cur = primset.begin()->second;
        primset.erase(primset.begin());
        sumcost = sumcost + prim[cur];
        used[cur] = 2; 
        
        for (int i = 0; i < edges[cur].size(); i++){
            int next = edges[cur][i].first;
            int cost = edges[cur][i].second;
            if (used[next] == 0 || used[next] == 1 && prim[next] > cost){
                used[next] = 1;
                primset.erase(make_pair(prim[next], next));
                prim[next] = cost;
                primset.insert(make_pair(prim[next], next));
            }
        }
    }
    
    return sumcost;
}
