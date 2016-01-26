#include<bits/stdc++.h>

using namespace std;

vector < pair <int, int> > factorisation(int n);
int countit(int n, int m, int s);

int main(){
    int n,k;
    cin >> n >> k;
    
    vector < pair <int, int> > factors = factorisation(k);
    
    int mini = n;
    for (int i = 0; i < factors.size(); i++){
        //cout << factors[i].first << " " << factors[i].second << endl;
        mini = min(mini, countit(n, factors[i].first, factors[i].second));
    }
    
    cout << mini << endl;
}

vector < pair <int, int> > factorisation(int n){
    vector < pair < int, int > > factors;
    
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            int cnt = 0;
            
            while (n % i == 0){
                cnt++;
                n = n / i;
            }
            
            factors.push_back(make_pair(i, cnt));
        }
    }
    
    if (n > 1){
        factors.push_back(make_pair(n, 1));
    }
    
    return factors;
}

int countit(int n, int m, int s){
    int cnt = 0;
    
    while(n > 0){
        cnt = cnt + n/m;
        n = n/m;
    }
    
    cnt = cnt / s;
    
    return cnt;
}