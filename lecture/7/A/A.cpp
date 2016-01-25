#include<bits/stdc++.h>

using namespace std;

pair < pair < int, int >, int > euklid(int a, int b);


int main(){

    while(true){
        string input;
        getline(cin, input);
        
        
        if (strcmp(input.c_str(), "\n") == -1){
            break;
        }
        
        stringstream stream(input);
        
        int a,b;
        
        stream >> a >> b;
        
        pair < pair < int, int >, int > res = euklid(a,b);
        cout << res.first.first << " " << res.first.second << " " << res.second << endl;
    }
}
    

pair < pair < int, int >, int > euklid(int a, int b){
    if (b == 0){
        return make_pair(make_pair(1,0),a);
    }
    pair < pair < int, int >, int > neu = euklid(b, a % b);
    swap(neu.first.first, neu.first.second);
    
    neu.first.second = neu.first.second - (a/b)*neu.first.first;
    
    return neu;
}