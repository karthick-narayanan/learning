#include <bits/stdc++.h>

int main(){
  std::vector<int> v;
  std::stack <int> s;
  int n;

  std::cin >> n;
  srand((unsigned) time(0));
  while(n--) {
    v.push_back(rand()%100);
    std::cout <<v.back() <<" ";
  }

  std::cout << '\n';

  s.push(v[0]);

  for(int i=1; i < v.size(); i++) {
    //std::cout <<v[i] << " \n";
    while(!s.empty() && s.top() >= v[i]) {
      s.pop();
    }

    if(s.empty()) {
      s.push(v[i]);
    }

    else if (s.top() < v[i]) {
      std::cout <<v[i] <<" " << s.top() << "\n";
      s.push(v[i]);
    }

  }
}
