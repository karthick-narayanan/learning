#include <bits/stdc++.h>

int main()
{
std::vector<int> v;
int t = 0;
int n=0;
int final_num = 0;
srand((unsigned) time(0));
std::cin >> n;

while(n--){
  //They can be in any order but just for simplicity
  // i am putting them all to gether.
  t = rand()%100;
  int k=0;
  while(k < 3) {
    v.push_back(t);
    k++;
  }
  std::cout << v.back() << " ";
}
t = rand()%100;
v.push_back(t);
std::cout << v.back() << " \n";


for(int i=0; i < 32; i++) {
  int b=1;
  int count = 0;
  b = b<<i;
  for(int j=0; j< v.size(); j++) {
    if((v[j] & b) != 0) {
      count++;
    }
  }
  if(count%3){
    final_num |= b;
  }
}

std::cout << "unique number is : " <<final_num <<'\n';
}
