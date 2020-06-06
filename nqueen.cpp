/*
This program is to find the number of different ways n queesn can be placed in the board.
*
#include <bits/stdc++.h>

using namespace std;
int count = 0;
int findn(int row , int n, std::vector<int> col, std::vector<int> diag1, std::vector<int> diag2) {
  if(row == n) {
    count++;
  }

  for(int i=0; i<n ;i++) {
    if(col[i] || diag1[i+row] || diag2[row-i+(n-1)])){
      continue;
    }
    col[i] = diag1[i+row] = diag2[row-i+(n-1)] = 1;
    findn(row+1, n, col, diag1, diag2)
    col[i] = diag1[i+row] = diag2[row-i+(n-1)] = 0;
  }
}


int main() {
  int n;
  vector <int> col;
  vector <int> diag1;
  vector <int> diag2;


  count << "n queen problem , enter n (nxn) "
  cin >> n;
  findn(0, n, col, diag1, diag2);
  cout << count;
}
