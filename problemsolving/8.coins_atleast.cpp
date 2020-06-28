#include <bits/stdc++.h>

int solve_m(std::vector<int> &v, std::vector<int> &coins, std::vector<int> &print_coins, int m){

  if(v[m] != INT_MAX) {
    return v[m];
  }

  for(auto c : coins) {
    if(m-c){
      int ct = std::min(v[m], solve_m(v, coins, print_coins, m-c)+1);
      if(ct<v[m]) {
        v[m] = ct;
        print_coins[m] = c;
      }
    }
  }
  return v[m];
}

int main(){
  std::vector<int> v;
  std::vector<int> coins;
  std::vector<int> print_coins;
  int n,m;
  std::cout<<"no of coins :";
  std::cin>>n;
  std::cout<<"find m wasy for:";
  std::cin>>m;
  v.assign(m+1, INT_MAX);
  print_coins.assign(m+1, -1);
  while(n--){
    int t;
    std::cin>>t;
    coins.push_back(t);
    v[t] = 1;
    print_coins[t] = t;
  }

  /* we are calculating for all possible combiatnions. lets calculate only what we want.
    for(int i=1; i<v.size(); i++){
    for(int j=0;j<coins.size(); j++) {
      if(i-coins[j] > 0) {
        v[i] = std::min(v[i],v[i-coins[j]]+1);
      }
    }
  }*/
  solve_m(v, coins, print_coins, m);
  std::cout<<v[m]<<"\n";
  while(print_coins[m] > 0) {
    std::cout<<print_coins[m]<< " " ;
    m = m - print_coins[m];
  }
}
