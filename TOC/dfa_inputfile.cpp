/* Program to simulate a DFA machine
 * DFA is  5 tuple Q,Z,D,q0,F
* Q - Set of all states
* Z - set of all alphabets(Events)
* D - D : Q X Z -> Q  - is the transition functions
* q0 - start states
* F - set of all final/accept states
* program takes input file as below format and output wether
* a given string is accepted by this machine
* sample input file
* + --- start state
* ^ --- End state
* q0+,q1,q2,q3^
* a,b
* q0 x a -> q1
* q0 x b -> q0
* q1 x a -> q2
* q1 x b -> q0
* q2 x a -> q3
* q2 x b -> q0
* q3 x a -> q3
* q3 x b -> q0
*/


#include <bits/stdc++.h>

typedef struct fsm {
  int **transition_buf;
  int curr_state;
  int start_state;
  int no_of_events;
  int no_of_states;
  std::vector<std::string> final_states;
  std::map<std::string, int> s_to_i;
  std::map<int, std::string> i_to_s;
  std::map<std::string, int> e_to_i;
  std::map<int, std::string> i_to_e;
}fsm_t;

void print_transition(int** &t, int states, int events/*, char* &events_arr*/)
{

  std::cout<<"***Transitions*****\n\n";
  std::cout<<"  ";
  for(int j=0; j<events; j++){
      std::cout<<" E"<<j;
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

int read_input(std::string i_string, int &no,
                  std::map<std::string, int> &t_to_i) {

  std::stringstream check1(i_string);
  std::string int_st;
  int i = 0;
  while(getline(check1, int_st, ',')) {
    t_to_i[int_st] = i;
    //std::cout<<int_st<<"*";
    i++;
  }
  no= i;
  return true;
}

void parse_states(std::map<std::string, int> &t_to_i,
                  std::vector<std::string> &final_states,
                  int &curr_state) {
  std::map<std::string, int>::iterator it;
  std::string temp_s;
  int s = -1;
  int f = -1;
  for (it = t_to_i.begin(); it != t_to_i.end(); it++) {
    ///std::cout<<"Printing states : " << (it->first  ) << " " << it->second<<"\n";
     s = -1;
     f = -1;
     temp_s = it->first;
     s = temp_s.find('+');
     if(s < temp_s.length()) {
       if(curr_state == -1) {
         curr_state = it->second;
       }
       /* More than 1 start states */
       else {
         curr_state = -1;
         return;
       }
       temp_s.erase(temp_s.begin() + s);
    }
    f = temp_s.find('^');
    if(f < temp_s.length()) {
       //delete last character
       temp_s.pop_back();
       final_states.push_back(temp_s);
     }

     if(s != -1 || f != -1) {
       std::swap(t_to_i[temp_s], it->second);
       it = t_to_i.erase(it);
     }
  }
 return;
}

int build_state_machine(char* file, fsm_t &dfa){

  std::ifstream fl(file);
  std::string st;

  if(!fl){
    std::cout<<"ERR : opening file "<<file<<"\n";
    return false;
  }

 //1st line states
 if(std::getline(fl, st)) {
    if(!read_input(st, dfa.no_of_states, dfa.s_to_i)) {
      std::cout<<"ERR : parsing states from"<<file<<"\n";
      return false;
    }
    std::cout<<"No.of states : " << dfa.no_of_states<<"\n";
    parse_states(dfa.s_to_i, dfa.final_states, dfa.start_state);
    if(dfa.start_state == -1) {
      std::cout<<"ERR : Invalid Start states :"<<file<<"\n";
      return false;
    }
    if(dfa.final_states.size() == 0){
      //std::cout<<"ERR : Invalid Final states : "<<file<<"\n";
      return false;
    }
 }
 else {
   std::cout<<"ERR : reading states from"<<file<<"\n";
   return false;
 }
 //2nd line events
 if(std::getline(fl, st)) {
   if(!read_input(st, dfa.no_of_events, dfa.e_to_i)) {
     std::cout<<"ERR : parsing events from"<<file<<"\n";
     return false;
   }
   std::cout<<"No.of events : " << dfa.no_of_events<<"\n";
 }
 else {
   std::cout<<"ERR : reading events from"<<file<<"\n";
   return false;
 }
//allocate memory for the statemachine
 dfa.transition_buf = (int **)calloc(dfa.no_of_states , sizeof(int *));
 for(int i=0; i< dfa.no_of_states; i++) {
  dfa.transition_buf[i] = (int *)calloc(dfa.no_of_events , sizeof(int));
 }

 //all lines followed will be transitions
 while(std::getline(fl, st)) {
   char f_s[50] =  {0};
   char event[50] = {0};
   char to_s[50] = {0};
   char *t_st = NULL;

  t_st = &st[0];
   //std::cout<<"line : "<<st<<"\n";
   sscanf(t_st ,"%s x %s -> %s",&f_s, &event, &to_s);

   if(dfa.s_to_i.find(f_s) == dfa.s_to_i.end()) {
     std::cout<<"ERR : Invalid from state "<<f_s<<" in "<<st<<"\n";
     return false;
   }
   if(dfa.e_to_i.find(event) == dfa.e_to_i.end()) {
     std::cout<<"ERR : Invalid from event in "<<st<<"\n";
     return false;
   }
   if(dfa.s_to_i.find(to_s) == dfa.s_to_i.end()) {
     std::cout<<"ERR : Invalid to state in "<<st<<"\n";
     return false;
   }

   dfa.transition_buf[dfa.s_to_i[f_s]][dfa.e_to_i[event]] = dfa.s_to_i[to_s];

 }

return true;

}

int run_machine(fsm_t &dfa, std::string &input){
  std::string temp_i;
  for(int i=0; i<input.length(); i++){
    temp_i = input[i];
    //std::cout<<temp_i<<"\n";
    if(dfa.e_to_i.find(temp_i) == dfa.e_to_i.end()){
      std::cout<<"ERR: Invalid input "<<temp_i<<"\n";
      return false;
    }
    dfa.curr_state = dfa.transition_buf[dfa.curr_state][dfa.e_to_i[temp_i]];
  }

  for(auto it = dfa.final_states.begin(); it!= dfa.final_states.end(); it++){
    if(dfa.s_to_i[*it] == dfa.curr_state)
       return true;
  }
  return false;
}
int main(int argc, char *argv[]){

  fsm_t dfa;
  std::string input;
  //memset(&dfa, 0, sizeof(fsm_t));
  dfa.curr_state = -1;
  dfa.start_state = -1;
  if(argc != 2){
    std::cout <<"Input ./dfa input_file.txt";
  }

 if(!build_state_machine(argv[1], dfa)) {
     std::cout<<"Error in building statemachine";
     return 0;
 }

 print_transition(dfa.transition_buf, dfa.no_of_states, dfa.no_of_events);

 while(1) {
    std::cout<<"Enter input string for the machine : \n";
    input = "";
    std::cin.clear();
    getline(std::cin,input);
    std::cout<<"\nReceived string :"<<input<<"\n";
    dfa.curr_state = dfa.start_state;
    if(run_machine(dfa, input)) {
      std::cout<<"\n "<<input<<" string accepted\n";
    } else {
      std::cout<<"\n "<<input<<" string Rejected\n";
    }
  }

 return 0;
}
