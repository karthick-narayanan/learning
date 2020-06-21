/*
A classic
problem is as follows: Given n events with their starting and ending times, find a
schedule that includes as many events as possible. It is not possible to select an
event partially. For example, consider the following events:
event starting time ending time
A 1 3
B 2 5
C 3 9
D 6 8
In this case the maximum number of events is two. For example, we can select
events B and D as follows:

*/
#include <bits/stdc++.h>

bool compare(const std::pair<int,int> &a, const std::pair <int,int> &b) {
  return a.second<b.second;
}

int main() {

    std::vector< std::pair<int,int> > v;
    unsigned int t,s,e;
    int count = 1, last_end = 0;
    srand((unsigned) time(0));

    std::cin >> t;
    while(t--) {
      s = rand()%100;
      e = s+(rand()%100);
      v.push_back(std::make_pair(s,e));
      std::cout<<s<<","<<e<<" ";
    }
    std::cout << "\n";
    std::sort(v.begin(),v.end(),compare);
    last_end = v[0].second;
    for(int i=1; i<v.size(); i++) {
      if(last_end < v[i].first) {
        count++;
        last_end = v[i].second;
      }
    }

    std::cout << count << "\n";



}
