#include <bits/stdc++.h>
#define N 5

int main() {

  int a[N][N] = {{3,7,9,2,7},
               {9,8,3,5,5},
               {1,7,9,8,5},
               {3,8,6,4,10},
               {6,3,9,7,8}};
  int sum[N][N] = {{0}};
  int i,j = 0;

  for(i = 0; i<N; i++) {
    for( j=0 ; j<N; j++) {

      int torightsum = 0;
      int todownsum = 0;

      if(i - 1 >=0) {
          torightsum = sum[i-1][j];
      }
      if(j -1 >= 0){
          todownsum = sum[i][j-1];
      }
      sum[i][j] = std::max(torightsum, todownsum) + a[i][j];
    }
  }
  std::cout<<sum[N-1][N-1]<<"\n";
}
