#include <bits/stdc++.h>

int cost(std::string &str1, std::string &str2,int str1_st, int str2_st){
  if (str1_st >= str1.length()){
    return 1;
  }
  if (str2_st >= str2.length()) {
    return 1;
  }
  if(str1[str1_st] == str2[str2_st]){
    return 0;
  }
  return 1;
}

int find_distance(std::vector<std::vector<int>> &matrix, std::string &str1, std::string &str2,int str1_st, int str2_st){
  if(str1_st >= str1.length() && str2_st >= str2.length()){
    return 0;
  }
  if(str1_st == str1.length()){
    return str2.length() - str2_st;
  }
  if(str2_st == str2.length()) {
    return str1.length() - str1_st;
  }
  if(matrix[str1_st][str2_st] != INT_MAX) {
    //std::cout<<"*"<<str1_st<<" "<<str2_st<<" "<<matrix[str1_st][str2_st]<<"\n";
    return matrix[str1_st][str2_st];
  }
  matrix[str1_st][str2_st] = std::min(std::min(find_distance(matrix, str1, str2, str1_st + 1, str2_st) + 1,
                  find_distance(matrix, str1, str2, str1_st, str2_st +1) + 1),
                  find_distance(matrix, str1, str2, str1_st + 1, str2_st +1) + cost(str1, str2, str1_st, str2_st));
  //std::cout<<str1_st<<" "<<str2_st<<" "<<matrix[str1_st][str2_st]<<"\n";
  return matrix[str1_st][str2_st];
}

int main() {
  std::string str1 = "LOVE";
  std::string str2 = "MOVVE";
  std::vector<std::vector<int>> matrix(str1.length(), std::vector<int>(str2.length(), INT_MAX));
  std::cout<<find_distance(matrix, str1, str2, 0, 0)<<"\n";

}
