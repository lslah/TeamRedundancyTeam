#include <bits/stdc++.h>

using namespace std;

int numbers[200];
int A1[200][200];
int A2[200][200];

int makeA1(int N){

    int result[200][200];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++){
            result[i][j] = numbers[j] - numbers[i];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
             A1[i][j] = result[i][j];
        }    
    }
    return 1;
}

int makeA2(int N){

    int result[200][200];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++){
            if (j = 0) {
                result[i][j] = 2;
                continue;
            }
            int 	maxR = 2;
            for (int k = 0; k < j; k++){
                maxR = max(result[j][k] + 1, maxR); 
            }
            result[i][j] = maxR;
        }
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
             A2[i][j] = result[i][j];
        }
    }
    return 1 ;
}

int solve(){
    int N;
    cin >> N;
    
    int numbers[200];

    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    
    makeA1(N);
    int maxA = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
             maxA = max(maxA, A2[i][j]);
        }
    }
    
    cout << maxA << endl;
}


int main(){

    int R;
    cin >> R;
    
    for (int i = 0; i < R; i++){
        solve();
    } 
}


