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

int find_distance(std::string &str1, std::string &str2,int str1_st, int str2_st){
  if(str1_st >= str1.length() && str2_st >= str2.length()){
    return 0;
  }
  if(str1_st == str1.length()){
    return str2.length() - str2_st;
  }
  if(str2_st == str2.length()) {
    return str1.length() - str1_st;
  }

  return std::min(std::min(find_distance(str1, str2, str1_st + 1, str2_st) + 1,
                  find_distance(str1, str2, str1_st, str2_st +1) + 1),
                  find_distance(str1, str2, str1_st + 1, str2_st +1) + cost(str1, str2, str1_st, str2_st));

}

int main() {
  std::string str1 = "LLLLLMOVE";
  std::string str2 = "MOVE";

  std::cout<<find_distance(str1, str2, 0, 0)<<"\n";

}
