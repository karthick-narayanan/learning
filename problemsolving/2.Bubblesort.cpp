
#include <bits/stdc++.h>


int main()
{
  int n;
  int t , temp;
  std::vector<int> v;
  std::cin>>n;
  while(n--) {
    std::cin>>t;
    v.push_back(t);
  }

for(int i = 0; i< v.size(); i++) {
  for(int j=1; j< v.size(); j++) {
      if(v.at(j-1) > v.at(j)) {
        temp = v.at(j-1);
        v.at(j-1) = v.at(j);
        v.at(j) = temp;
      }
  }
}
  for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    /* data */

      std::cout<< *it << " ";
  }


}
