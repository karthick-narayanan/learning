/*Let q(n) denote the number of ways to place n queens on an n× n chessboard.
The above backtracking algorithm tells us that, for example, q(8) = 92. When
n increases, the search quickly becomes slow, because the number of solutions
increases exponentially. For example, calculating q(16) = 14772512
*/
#define DOWN 1
#define UP 2
#define RIGHT 3
#define LEFT 4

#include <bits/stdc++.h>
void find_no_ways(int row, int col, std::vector<std::vector<int>> &v,int visited, int *total_count, int movement) {

    if(row == (v.size() - 1) && col == (v.size() -1)){
      if(visited == (v.size() * v.size()) - 1) {
          (*total_count)++;
      }
      return;
    }

    /*for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++)
        std::cout << v[i][j] << " ";
    std::cout << "\n";
  }
    std::cout << " *** \n";*/
    // setting visited
    if(((row + 1 == v.size() || v[row+1][col] == 1) && movement == DOWN) ||
          ((((row-1) == -1) || v[row-1][col] == 1) && movement == UP)) {
      if(((col - 1)  >= 0) && ((col + 1) < v.size())){
        if(v[row][col-1] == 0 && v[row][col+1] == 0){
          return;
        }
      }
    }
    if((((col + 1) == v.size() || v[row][col+1] == 1) && movement == RIGHT) ||
      (((col - 1) < 0 || v[row][col-1] == 1) && movement == LEFT)) {
      if((((row - 1)) >=0) && ((row +1) > v.size())) {
        if(v[row-1][col] == 0 && v[row+1][col] ==0) {
          return;
        }
      }
    }
    v[row][col] = 1;
    visited++;
    if(row+1 < v.size() && v[row + 1][col] == 0 ) {
      find_no_ways(row+1,col, v,visited,total_count, DOWN);
    }
    if(col+1 < v.size() && v[row][col + 1] == 0 ) {
      find_no_ways(row,col+1, v,visited,total_count, RIGHT);
    }
    if(row-1 >= 0  && v[row - 1][col] == 0 ) {
      find_no_ways(row-1,col, v ,visited,total_count, UP);
    }
    if(col-1 >= 0  && v[row][col - 1] == 0 ) {
      find_no_ways(row,col-1, v ,visited,total_count, LEFT);
    }
    //resetting visited
    visited--;
    v[row][col] = 0;
    return;
}



int main(){
  int n;
  int total_count = 0;
  std::cin>>n;

  std::vector<std::vector<int>> matrix(n,std::vector<int> (n,0));
  //
  //optimization 1 - move one position down and then multiply result by 2 - this is symmetry
  matrix[0][0]=1;
  find_no_ways(1,0,matrix,1,&total_count, DOWN);
  std::cout<<  total_count*2<<"\n";


}
