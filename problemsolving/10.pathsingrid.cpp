#include <bits/stdc++.h>
#define N 5
struct pair_sum{
  int x;
  int y;
  int sum;
  pair_sum(int x,int y, int sum)
  :x(x), y(y), sum(sum){

  }
};

int main() {
  std::queue<struct pair_sum> max_sumpath_q;
  int max = 0;

  int a[N][N] = {{3,7,9,2,7},
               {9,8,3,5,5},
               {1,7,9,8,5},
               {3,8,6,4,10},
               {6,3,9,7,8}};


  max_sumpath_q.push(pair_sum(0,0,0));

  while(!max_sumpath_q.empty()) {

    int sum;
    struct pair_sum temp = max_sumpath_q.front();
    max_sumpath_q.pop();
    sum =  temp.sum + a[temp.x][temp.y];
    if(temp.x == N -1 && temp.y == N-1) {
      max = std::max(sum,max);
    }
    else{
      if(temp.x+1 < N) {
        max_sumpath_q.push(pair_sum(temp.x+1, temp.y, sum));
      }
      if(temp.y+1 < N) {
        max_sumpath_q.push(pair_sum(temp.x, temp.y+1, sum));
      }
    }
  }
  std::cout<<"\n  "<<max<<"\n";
}
