#include <bits/stdc++.h>

int main() {
  std::vector<int> v;
  int n;
  int sum;
  int idx1 = 0, idx2=0;

  srand((unsigned) time(0));
  std::cin >> n;

  while(n--){
    v.push_back(rand()%100);
    std::cout << v.back() << " ";
  }
  std::cout  << '\n';

  std::sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++){
    std::cout << v[i] << " ";
  }
    std::cin >> sum;
  idx2 = v.size()-1;
  while(idx1 < idx2){
    //  std::cout << idx1 << " "<<idx2 << '\n';
    if(v[idx1]+v[idx2] == sum) {
      std::cout<<"\n" << idx1 << " "<<idx2 << '\n';
      break;
    }
    if((v[idx1]+v[idx2]) > sum){
      idx2--;
    }
    else {
      idx1++;
    }
  }
}
