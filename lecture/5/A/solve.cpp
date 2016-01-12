#include<bits/stdc++.h>

using namespace std;


const int MAXN = 1000001;

int parent[MAXN];
int rang[MAXN];


struct edge{
    int from, to;
    int cost;
};

bool cmp_edges(edge a, edge b);
void make_set(int v);
int find_set(int v);
bool union_sets(int a, int b);
int prim(vector<edge> &edgelst);

int main(){
    int n,m,p1,p2;
    cin >> n >> m >> p1 >> p2;

    vector< edge > edgelst;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i+1 < n) {
                edge e;
                e.from = i*m+j;
                e.to = (i+1)*m+j;
                e.cost = ((i+1)*(i+2) + p1*(j+1)*(j+1)) % p2;
                edgelst.push_back(e);
            }

            if (j+1 < m) {
                edge e;
                e.from = i*m+j;
                e.to = i*m+j+1;
                e.cost = ((i+1)*(i+1) + p1*(j+1)*(j+2)) % p2;
                edgelst.push_back(e);
            }

            if (i+1 < n && j+1 < m) {
                edge e;
                e.from = i*m+j;
                e.to = (i+1)*m+j+1;
                e.cost = ((i+1)*(i+2) + p1*(j+1)*(j+2)) % p2;
                edgelst.push_back(e);
            }
        }
    }

    for (int i = 0; i < n*m; i++) {
        make_set(i);
    }

    cout << prim(edgelst) << endl;
}

bool cmp_edges(edge a, edge b){
    return a.cost < b.cost;
}

void make_set(int v){
    parent[v] = v;
    rang[v] = 1;
}

int find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return (parent[v] = find_set(parent[v]));
}

bool union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    
    if (a != b){
        if (rang[a] < rang[b]){
            swap(a,b);
        }
        
        parent[a] = b;
        if (rang[a] == rang[b]){
            rang[a]++;
        }
        return true;
    }
    
    return false;
}

int prim(vector<edge> &edgelst){
    sort(edgelst.begin(), edgelst.end(), cmp_edges);

    int sumcost = 0;

    for (int i = 0; i < edgelst.size(); i++){
        int a = edgelst[i].from;
        int b = edgelst[i].to;
        int cost = edgelst[i].cost;

        if (union_sets(a, b)) {
            sumcost += cost;
        }
    }

    return sumcost;
}
