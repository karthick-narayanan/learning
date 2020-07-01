#include <bits/stdc++.h>

int main() {
  std::vector<int> v;
  int n;
  int sum;
  int cur_sum = 0;
  int idx1=0, idx2 = 0;
  std::cin >> n;
  srand((unsigned) time(0));
  while(n--){
    v.push_back(rand()%100);
    std::cout << v.back() << " ";
  }
  std::cout<< '\n';

  std::cin>>sum;

  while(idx2 < v.size()){

    if(cur_sum < sum){
      cur_sum += v[idx2];
      idx2++;
    }
    else if(cur_sum > sum){
      cur_sum -= v[idx1];
      idx1++;
    }

    if(cur_sum == sum){
      std::cout << idx1<<" "<<idx2-1 << '\n';
      cur_sum += v[idx2];
      idx2++;
    }
  }
}
