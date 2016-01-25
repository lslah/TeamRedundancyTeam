#include<bits/stdc++.h>

using namespace std;

int solve(vector < int > numbers);
int euklid(int a, int b);


int main(){
    
    while(true){
        string input;
        getline(cin, input);
        
        stringstream stream(input);
        
        vector< int > numbers;
        while(true) {
            int n;
            stream >> n;
            if(n == 0){
                break;
            }
            numbers.push_back(n);
        }
        if (numbers.size() == 0){
            break;
        }
        cout << solve(numbers) << endl;
    }

    
    
}

int solve(vector < int > numbers){
    int a = numbers[0];
    for (int i = 1; i < numbers.size(); i++){
        a = min(numbers[i], a);
    }
    
    for (int i = 0; i < numbers.size(); i++){
        numbers[i] = numbers[i] - a;
    }
    
    int d = numbers[0];
    for(int i = 0; i < numbers.size(); i++){
        d = euklid(numbers[i], d);
    }
    
    return d;
}

int euklid(int a, int b){
    if (b == 0){
        return a;
    }
    
    return euklid(b, a % b);
}