#include <bits/stdc++.h>

int solve_m(std::vector<int> &v, std::vector<int> &coins,int m){

  if(v[m] != INT_MAX) {
    return v[m];
  }

  for(auto c : coins) {
    if(m-c){
      v[m] = std::min(v[m], solve_m(v, coins, m-c)+1);
    }
  }
  return v[m];
}

int main(){
  std::vector<int> v;
  std::vector<int> coins;
  int n,m;
  std::cout<<"no of coins :";
  std::cin>>n;
  std::cout<<"find m wasy for:";
  std::cin>>m;
  v.assign(m+1, INT_MAX);
  while(n--){
    int t;
    std::cin>>t;
    coins.push_back(t);
    v[t] = 1;
  }

  /* we are calculating for all possible combiatnions. lets calculate only what we want.
    for(int i=1; i<v.size(); i++){
    for(int j=0;j<coins.size(); j++) {
      if(i-coins[j] > 0) {
        v[i] = std::min(v[i],v[i-coins[j]]+1);
      }
    }
  }*/
  solve_m(v, coins, m);
  std::cout<<v[m];
}
