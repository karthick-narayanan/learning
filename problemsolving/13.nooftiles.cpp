#include <bits/stdc++.h>

void find_ways(std::vector<std::vector<int>> &v, int m, int n, int sum, int &count){

  if(sum == (v.size() * v[0].size())){
    count++;
    return;
  }
  /*std::cout << '\n';
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[0].size();j++){
      std::cout << v[i][j] << " ";
    }
    std::cout << '\n';
  }*/
  if(m >= v.size()){
    n = n+1;
    m = 0;
  }
  while(v[m][n] == 1){
    m=m+1;
    if(m >= v.size()){
      n = n+1;
      m = 0;
    }
  }

  if(m+1 < v.size()){
    if(v[m][n] != 1 && v[m+1][n] !=1) {
      v[m][n] = 1;
      v[m+1][n] = 1;
      find_ways(v, m+2, n, sum+2, count);
      v[m][n] = 0;
      v[m+1][n] = 0;
    }
  }
  if(n+1 < v[0].size()) {
    if(v[m][n] != 1 && v[m][n+1] != 1) {
      v[m][n] = 1;
      v[m][n+1] = 1;
      find_ways(v, m+1, n, sum+2, count);
      v[m][n] = 0;
      v[m][n+1] = 0;

    }
  }
}

int main() {
  int m , n;
  int count = 0;

  std::cin>>m;
  std::cin>>n;
  std::vector<std::vector<int>> v(m,std::vector<int>(n,0));

  find_ways(v,0,0,0,count);

  std::cout << count << '\n';

}
