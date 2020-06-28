#include <bits/stdc++.h>

struct node {
  char character;
  int ct;
  struct node *left;
  struct node *right;
  node(char character, int ct)
    :character(character), ct(ct), left(NULL), right(NULL)
    {

    }
};

struct Comparecount {
    bool operator()(node const& p1, node const& p2)
    {
        return p1.ct > p2.ct;
    }
};

void print_tree(struct node *root, std::string &str) {
    if(root == NULL){
      return;
    }
    //std::cout<<root->character<<":" <<root->ct << str <<"\n";
    str.push_back('0');
    print_tree(root->left, str);
    str.pop_back();
    str.push_back('1');
    print_tree(root->right, str);
    str.pop_back();
    //if(root->character != 0) {
      std::cout<<root->character<<":" <<root->ct << str <<"\n";
    //}
}

int main()
{
  int t;
  char c;
  int ct;
  std::string s;
  /* Need to check why this declaration has to be like this*/
  std::priority_queue<struct node*, std::vector<node>, Comparecount> pq;
  std::cin>>t;
  while(t--) {
       struct node tmp;
        std::cin>>c;
        std::cin>>ct;
        tmp = node(c,ct);
        pq.push(&tmp);;
  }

  while(pq.size() > 1){
    std::cout<<(pq.top()).ct<<"\n";
    struct node* t1 = pq.top();
    pq.pop();
    struct node* t2 = pq.top();
    pq.pop();
    node t3 = node(0,t1.ct+t2.ct);
    //std::cout<<t1<<t2 <<"\n";
    t3.left = t1;
    t3.right = t2;
    pq.push(&t3);
  }
  node t1 = pq.top();
  print_tree(&t1,s);

}
