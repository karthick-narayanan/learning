#include <bits/stdc++.h>

int main() {
  std::vector<int> v;
  std::vector<int> org;
  int n;
  int window;
  int t_window = 0;
  int t_num = 0;
  int min_window = INT_MAX;
  srand((unsigned) time(0));
  std::cin >> n;
  std::cin >> window;

  while(n--) {
    while(t_window < window) {
      t_num = rand()%100;

      org.push_back(t_num);
      std::cout << t_num << " ";
      if(t_num < min_window){
        v.clear();
        min_window = t_num;
      }
      while(!v.empty() && v.back() > t_num){
        v.pop_back();
      }
      v.push_back(t_num);
      t_window++;
    }
    std::cout << v[0] << "\n ";
    if(v[0] == org[org.size() - (window)]) {
      v.erase(v.begin());
      if(!v.empty()) {
        min_window = v[0];
      }
    }
    t_window--;
  }
}
