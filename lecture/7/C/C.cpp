#include<bits/stdc++.h>

using namespace std;

int euler(int n);

int main(){

    while(true){
        string input;
        getline(cin, input);
        
        
        if (strcmp(input.c_str(), "\n") == -1){
            break;
        }
        
        stringstream stream(input);
        
        int a;
        
        stream >> a;
        
        cout << euler(a) << endl;
    }
}

int euler(int n){
    int result = n;
    
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            while(n % i == 0){
                n = n / i;
            }
            result = result - result / i; 
        }
    }
    
    if (n > 1){
        result = result - result / n;
    }
    
    return result;
}

