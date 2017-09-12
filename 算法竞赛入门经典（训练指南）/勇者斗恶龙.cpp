#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  while(cin >> n >> m){
    if(n==0 && m==0){
      break;
    }
    vector<int> A(n);
    vector<int> B(m);
    for(int i = 0; i < n; i ++){
      cin >> A[i];
    }
    for(int i = 0; i < m; i ++){
      cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int cur = 0, cost = 0;
    for(int i = 0; i < m; i ++){
      if(B[i] >= A[cur]){
        cost += B[i];
        if(++cur == n){
          break;//龙头已经砍完
        }
      }
    }
    if(cur < n){
      cout << "Loowater is dommed!" << endl;
    }
    else{
      cout << cost << endl;
    }
  }
  return 0;
}
