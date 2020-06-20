/*As an example, consider a problem where we are given a list of n numbers
and a number x, and we want to find out if it is possible to choose some numbers
from the list so that their sum is x. For example, given the list [2,4,5,9] and
x = 15, we can choose the numbers [2,4,9] to get 2+4+9 = 15.
*/
#include <bits/stdc++.h>

void print_all_sums(std::vector<int> &v, std::vector<int> &all_sum, int idx, int sum) {
  if(idx == v.size()) {
    //std::cout<<sum<<"\n";
    all_sum.push_back(sum);
    return;
  }
  //for(int i = idx ; i < v.size(); i++) {
    print_all_sums(v, all_sum, idx+1, sum);
    print_all_sums(v, all_sum, idx+1, sum+v[idx]);
  //}
}

int main(){
  int n ,t, find_sum = 0;;
  std::vector<int> v;
  std::vector<int> left;
  std::vector<int> right;
  std::vector<int> left_sum;
  std::vector<int> right_sum;

  std::cin>>n;
  t = n;
  srand((unsigned) time(0));
  while(t--){
    v.push_back(rand()%100);
  }
  for(int i=0;i<v.size();i++) {
    std::cout << v[i] <<" ";
    if(v[i] == 0) {
      continue;
    }
    if(i < (v.size()/2)) {
      left.push_back(v[i]);
    }
    else{
      right.push_back(v[i]);
    }

  }
  std::cin>>find_sum;
  std::cout <<"\n";
  print_all_sums(left, left_sum, 0, 0);
  print_all_sums(right, right_sum,0 ,0);

  std::sort(left_sum.begin(), left_sum.end());
  std::sort(right_sum.begin(), right_sum.end());

  for(int i=0; i<left_sum.size(); i++){
    std::cout<<left_sum[i] << " ";
    if (binary_search(right_sum.begin(),right_sum.end(), find_sum - left[i])) {
      std::cout<<"found";
    }
  }
  std::cout << "\n";
  for(int i=0; i<right_sum.size(); i++){
    std::cout<<right_sum[i] << " ";
  }

}
