#include <bits/stdc++.h>

#define verbose 1
#define inf 1e9

using namespace std;

const int MAXN = 100001;
int J;
bool oper[MAXN], changeable[MAXN], value[MAXN];
// oper is 1 = AND, 0 = OR

bool evaluate(int vertex){
   if (vertex > J){
      return value[vertex];
   }
   else{
      if (oper[vertex]){
         value[vertex] = evaluate(vertex*2) & evaluate(vertex*2 + 1);
      }
      else{
         value[vertex] = evaluate(vertex*2) | evaluate(vertex*2 + 1);
      }
   }
   return value[vertex];
}


int dp(int vertex, bool des_val){

   if (vertex > J){
      if (value[vertex] == des_val){
         return 0;
      }
      else return inf;
   }
   else{
      bool left = value[2*vertex];
      bool right = value[2*vertex + 1];
      // if it is alright
      if (oper[vertex] && ((left & right) == des_val)) return 0;
      if (!oper[vertex] && ((left | right) == des_val)) return 0;

      if (!changeable[vertex]){
         // try to change values
         if (des_val){
            if (oper[vertex]){
               int sum = 0;
               if (!left) sum += dp(2*vertex, 1);
               if (!right) sum += dp(2*vertex+1, 1);
               return sum;
            }
            else{
               // case OR
               return min(dp(2*vertex,1), dp(2*vertex+1, 1));
            }
         }
         else{
            // we want to have 0
            if (oper[vertex]){
               return min(dp(2*vertex,0), dp(2*vertex+1, 0));
            }
            else{
               // case OR
               int sum = 0;
               if (left) sum += dp(2*vertex, 0);
               if (right) sum += dp(2*vertex+1, 0);
               return sum;
            }
         }
      }
      // if changeable
      // want 0, have AND, and not alright --> currently we have (1,1)
      if (!des_val && oper[vertex]) return min(dp(2*vertex, 0), dp(2*vertex+1, 0));

      // want 1, have OR, and not alright --> currently we have (0,0)
      if (des_val && !oper[vertex]) return min(dp(2*vertex, 1), dp(2*vertex+1, 1));

      // want 0, have OR, and not alright --> currently we have (1,1), (0,1) or (1,0)
      // --> change to AND and look
      if (!des_val && !oper[vertex]){
         if (0 == (left & right)) return 1;
         else{
            // case (1,1)
            return min(1+dp(2*vertex, 0), 1+dp(2*vertex+1, 0));
         }
      }
      // want 1, have AND, and not alright --> currently we have (1,1), (0,1) or (1,0)
      // --> change to OR and look
      if (des_val && oper[vertex]){
         if (1 == (left | right)) return 1;
         else{
            // case (1,1)
            return min(1+dp(2*vertex, 1), 1+dp(2*vertex+1, 1));
         }
      }
   }
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
