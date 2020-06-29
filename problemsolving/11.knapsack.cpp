#include <bits/stdc++.h>

int main() {
  std::vector<int> v;
  std::vector<int> sum_array;
  int sum = 0;
  int n;

  std::cin>>n;

  srand((unsigned) time(0));
  while(n--){
    v.push_back(rand()%20);
    sum += v.back();
    std::cout<<v.back()<<" ";
  }

  std::cout<<"\n";

  sum_array.assign(sum+1,0);

  sum_array[0] = 1;

  for(int i=0; i<v.size(); i++){
    for(int j=sum; j>=0; j--) {
      if(sum_array[j]){
        sum_array[j+v[i]] = 1;
      }
    }
  }

  for(int i=0; i<=sum ;i++) {
    if(sum_array[i]) {
      std::cout<<i<<" ";
    }
  }
  std::cout<<"\n";

}
