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
   // Already correct?
   if (value[vertex] == des_val) return 0;
   // Not correct and leaf? Too bad.
   if (vertex > J) return inf;

   bool operation = oper[vertex];

   // (want 1 with OR) or (want 0 with AND)
   // => Need to change exactly one child to 0
   if (des_val != operation)
      return min(dp(2*vertex, des_val), dp(2*vertex+1, des_val));

   // Want 0 with OR  => Both childs need to be 0
   // Want 1 with AND => Both childs need to be 1

   // Better to switch operation if possible
   if (changeable[vertex])
      return 1+min(dp(2*vertex, des_val), dp(2*vertex+1, des_val));

   // No way, we have to change both childs
   return dp(2*vertex, des_val) + dp(2*vertex+1, des_val);
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
