/*
This program is to find the number of different ways n queesn can be placed in the board.
*/
#include <bits/stdc++.h>

int count = 0;

void findn(int row , int n, std::vector<int> &col, std::vector<int> &diag1, std::vector<int> &diag2) {
  if(row == n) {
    count++;
    return;
  }
  for(int i=0; i<n ;i++) {
    if(col[i] || diag1[i+row] || diag2[row-i+(n-1)]){
      continue;
    }
    col[i] = diag1[i+row] = diag2[row-i+(n-1)] = 1;
    findn(row+1, n, col, diag1, diag2);
    col[i] = diag1[i+row] = diag2[row-i+(n-1)] = 0;
  }
}


int main() {
  int n;


  std::cout << "n queen problem , enter n (nxn) ";
  std::cin >> n;

  std::vector <int> col(n,0);
  std::vector <int> diag1(n*2,0);
  std::vector <int> diag2(n*2,0);

  findn(0, n, col, diag1, diag2);
  std::cout<< count <<std::endl;
  return 0;
}
