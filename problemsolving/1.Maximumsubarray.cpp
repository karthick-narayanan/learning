/* Program to print the maximum subarray */

#include <bits/stdc++.h>

int count = 0;

int main()
{
  int n, i, max_sum = 0, sum = 0;
  int t;
  std::vector<int> v;
  std::cin>>n;
  while(n--) {
    std::cin>>t;
    v.push_back(t);
  }
  for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it) {
    sum = std::max(sum,sum + *it);
    max_sum = std::max (max_sum, sum);
  }
  std::cout<< max_sum;
}
