/* Program to simulate a DFA machine
 * DFA is  5 tuple Q,Z,D,q0,F
* Q - Set of all states
* Z - set of all alphabets(Events)
* D - D : Q X Z -> Q  - is the transition functions
* q0 - start states
* F - set of all final/accept states
*/


#include <bits/stdc++.h>

void print_transition(int** &t, int states, int events, char* &events_arr)
{

  std::cout<<"Transitions\n";
  std::cout<<" ";
  for(int j=0; j<events; j++){
      std::cout<<"  "<<events_arr[j];
  }
  std::cout<<"\n";
  for(int i = 0; i<states; i++) {
      std::cout<<"S"<<i<<" ";
    for(int j=0; j<events; j++){
      std::cout<<t[i][j]<<"  ";
    }
    std::cout<<"\n";
  }
}

int main() {

  int *states ,*events;
  int no_of_states = 0, no_of_events = 0;
  int  **transition_buf;
  char *events_arr;

  std::map<char, int> char_to_idx;
  std::cout<<"Enter no.of states : ";
  std::cin>>no_of_states;
  std::cout<<"Enter no. of events : ";
  std::cin>>no_of_events;

  if(no_of_events == 0 || no_of_states == 0) {
    std::cout << "Invalid Inputs";
    return 0;
  }

  events_arr = (char *)calloc(no_of_events, sizeof(char));
  std::cout<<"Enter all events :";

  for(int i=0; i< no_of_events; i++) {
      std::cin>>events_arr[i];
      char_to_idx[events_arr[i]] = i;
  }

  transition_buf = (int **)calloc(no_of_states , sizeof(int *));
  for(int i=0; i< no_of_states; i++) {
    transition_buf[i] = (int *)calloc(no_of_events , sizeof(int));
  }

  do {
    int f_s,  t_s;
    char e;
    print_transition(transition_buf, no_of_states, no_of_events, events_arr);
    std::cout<<"Enter from state :";
    std::cin>>f_s;
    if(f_s < 0)
        break;
    std::cout<<"Enter event :";
    std::cin>>e;
    std::cout<<"Enter to state :";
    std::cin>>t_s;
    transition_buf[f_s][char_to_idx[e]] = t_s;
  }while(1);

  print_transition(transition_buf, no_of_states, no_of_events, events_arr);


  std::cout<<"****************\n";
  int curr_state = 0;
  char e;

  do {
    std::cout<<"Enter event\n";
    std::cin>>e;
    curr_state = transition_buf[curr_state][char_to_idx[e]];
    std::cout<<"Moving to state :"<<curr_state<<"\n";
  }while(curr_state != -1);

}
