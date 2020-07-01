#include <bits/stdc++.h>

int find_sum(std::vector<int> v, int idx1, int sum){

    int idx2 = v.size()-1;

    while(idx1 < idx2) {
      if(v[idx1] + v[idx2] == sum){
        std::cout <<v[idx1]<<" " << v[idx2];
        return 1;
      }
      if(v[idx1] + v[idx2] > sum){
        idx2--;
      }
      else{
        idx1++;
      }
    }
    return 0;
}
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

  for(int i=0; i<v.size(); i++){
    if(find_sum(v, i+1, sum - v[i])) {
      std::cout <<" "<< v[i] << "\n";
      break;
    }
  }



}
