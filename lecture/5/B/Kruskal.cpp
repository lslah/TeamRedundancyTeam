#include<bits/stdc++.h>

using namespace std;


const int MAXN = 100001;

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
vector< int > kruskal(vector<edge> &edgelst);

//------------------------------------------------------------------------------
//---------------------------Funktions------------------------------------------
//------------------------------------------------------------------------------


//--------------------------------Main------------------------------------------
int main(){
    int n,m;
    cin >> n >> m;
    
    vector< edge > edgelst;
    edgelst.resize(m);
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edgelst[i].from = a - 1;
        edgelst[i].to = b - 1;
        edgelst[i].cost = i;
    }
    
    for (int i = 0; i < n; i++){
        make_set(i);
    }
    
    vector< int > ret = kruskal(edgelst);
    
    int r = ret.size();
    cout << r << endl;
    if (r > 0){
        for (int i = 0; i < r-1; i++){
            cout << ret[i] + 1 << " ";
        }
        cout << ret[r - 1] + 1<< endl;
    }
}

//------------------------------Edges-------------------------------------------
bool cmp_edges(edge a, edge b){
    return a.cost < b.cost;
}


//------------------------------Union-Find--------------------------------------
void make_set(int v){
    parent[v] = v;
    rang[v] = 1;
}

int find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return find_set(parent[v]);
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

//--------------------------------------Kruskal---------------------------------
vector< int > kruskal(vector<edge> &edgelst){
//    sort(edgelst.begin(), edgelst.end(), cmp_edges);

    vector< int > ret;
    
    for (int i = 0; i < edgelst.size(); i++){
        int a = edgelst[i].from;
        int b = edgelst[i].to;
        int cost = edgelst[i].cost;
        
        if (union_sets(a, b)){
            ret.push_back(i);
        }
    }
    
    return ret;
}
