#include <bits/stdc++.h>


int main() {
  int t, i=0;
  std::vector<int> sequence;
  std::vector<int> max_sum_sequence;

  std::cin>>t;
  max_sum_sequence.assign(t,0);
  while(i < t) {
      int val = 0;
      int max = 0;
      std::cin>>val;
      sequence.push_back(val);

      for(int j=i-1; j>= 0 ; j--) {
        if(sequence[j] < val ) {
            max = std::max(max, max_sum_sequence[j]);
        }
      }
      max_sum_sequence[i] = max + val;
      i++;
  }
  for(int i=0;i < sequence.size(); i++) {
    std::cout<<sequence[i]<<" ";
  }
  std::cout<<"\n";
  for(int i=0;i < max_sum_sequence.size(); i++) {
    std::cout<<max_sum_sequence[i]<<" ";
  }

}
