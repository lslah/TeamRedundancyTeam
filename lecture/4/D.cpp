#include <bits/stdc++.h>

#define verbose 1
#define inf 1e9

using namespace std;

const int MAXN = 100001;
int J;
bool oper[MAXN], changeable[MAXN], value[MAXN];
// oper is 1 = AND, 0 = OR

bool evalOperation(bool operation, bool left, bool right) {
    return (  (operation && (left && right))
           || (!operation && (left || right))
           );
}

bool evaluate(int vertex){
   if (vertex > J) return value[vertex];

   value[vertex] = evalOperation(oper[vertex], evaluate(vertex*2), evaluate(vertex*2 + 1));
   return value[vertex];
}


int dp(int vertex, bool des_val){

   if (vertex > J){
      if (value[vertex] == des_val){
         return 0;
      }
      else return inf;
   }

   bool left = value[2*vertex];
   bool right = value[2*vertex + 1];
   bool operation = oper[vertex];
   // if it is alright
   if (value[vertex] == des_val) return 0;

   if (!changeable[vertex]){
      // try to change child values

      if ((des_val && operation) || (!des_val && !operation))
          return dp(2*vertex, des_val) + dp(2*vertex+1, des_val);
   }
   // (des_val != operation)
   if ((des_val && !operation) || (!des_val && operation))
       return min(dp(2*vertex, des_val), dp(2*vertex+1, des_val));

   return min(1+dp(2*vertex, des_val), 1+dp(2*vertex+1, des_val));
}

int main(void){
   int N, desired_root;
   cin >> N >> desired_root;
   J = (N-1)/2;
   for (int i = 1; i <= J; i++){
      cin >> oper[i] >> changeable[i];
   }
   for (int i = 1; i <= (N+1)/2; i++){
      cin >> value[i + J];
   }
   if (desired_root == evaluate(1)){
      cout << 0 << endl;
      return 0;
   }
   int count = dp(1, desired_root);
   if (count >= inf) cout << "IMPOSSIBLE" << endl;
   else cout << count << endl;
}
