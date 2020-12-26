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

int build_state_machine(char* file, int** &transition_buf, int &curr_state,
                     int &no_of_events, int &no_of_states,
                     std::map<std::string, int> &s_to_i, std::map<std::string, int> &e_to_i){

  std::ifstream fl(file);
  std::string st;

  //fl.open("file", ios::in);

  if(!fl){
    std::cout<<"ERR : opening file "<<file<<"\n";
    return false;
  }

 //1st line states
 if(std::getline(fl, st)) {
    if(!read_input(st, no_of_states, s_to_i)) {
      std::cout<<"ERR : parsing states from"<<file<<"\n";
      return false;
    }
    std::cout<<"No.of states : " << no_of_states<<"\n";
 }
 else {
   std::cout<<"ERR : reading states from"<<file<<"\n";
   return false;
 }
 //2nd line events
 if(std::getline(fl, st)) {
   if(!read_input(st, no_of_events, e_to_i)) {
     std::cout<<"ERR : parsing events from"<<file<<"\n";
     return false;
   }
   std::cout<<"No.of events : " << no_of_events<<"\n";
 }
 else {
   std::cout<<"ERR : reading events from"<<file<<"\n";
   return false;
 }

 //all lines followed will be transitions
 while(std::getline(fl, st)) {

   std::cout<<"line : "<<st<<"\n";
 }

return true;

}

int main(int argc, char *argv[]){

  int **transition_buf;
  int curr_state;
  int no_of_events;
  int no_of_states;
  std::map<std::string, int> s_to_i;
  std::map<std::string, int> e_to_i;

  if(argc != 2){
    std::cout <<"Input ./dfa input_file.txt";
  }

 if(!build_state_machine(argv[1], transition_buf, curr_state,
                      no_of_events, no_of_states, s_to_i, e_to_i)) {
     std::cout<<"Error in building statemachine";
     return 0;
 }



}
