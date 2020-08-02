#include <bits/stdc++.h>

int find_sum(std::vector<int> &v, int idx) {
  if(idx == 0){
    return 0;
  }
  return v[idx] + find_sum(v, (idx & (idx -1)));

}

void build_idx(std::vector<int> &v) {

      for(int i=1; i< v.size(); i++){
        //int t_index =  (((i ^ (i -1)) + 1) >> 1) + i;
        int t_index = (i & (-i)) + i;

        if(t_index < v.size()) {
          v[t_index] += v[i];
        }
      }
}


int main() {
  int n;
  int start = 0, end = 0;
  std::vector<int> v;
  std::cin >> n;
  //std::vector<int> build_binary_index(n+1, 0);
  srand((unsigned) time(0));
  v.push_back(0); // push 0 so that first value stats with binary value index 0001
  while(n--){
    v.push_back(rand()%100);
    std::cout << v.back() << " ";
  }
  std::cin>>start;
  std::cin>>end;
  std::cout << '\n';
  build_idx(v);

  for(int i = 1; i< v.size(); i++) {
    std::cout << v[i] << " ";
  }
  //std::cout << '\n';
  std::cout << "sum is " <<find_sum(v, end) - find_sum(v, start-1) ;
  //build

}
