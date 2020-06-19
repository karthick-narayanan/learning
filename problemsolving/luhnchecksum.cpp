/*PROBLEM: LUHN CHECKSUM VALIDATION
The Luhn formula is a widely used system for validating identification numbers. Using
the original number, double the value of every other digit. Then add the values of the
individual digits together (if a doubled value now has two digits, add the digits individually). The identification number is valid if the sum is divisible by 10.
Write a program that takes an identification number of arbitrary length and
determines whether the number is valid under the Luhn formula. The program must
process each character before reading the next one*/


#include <bits/stdc++.h>
#define return_sum(a) ((a >= 5) ? ((a *2) %10 +1) : a*2)

int main() {
  int even = 0;
  int odd = 0;
  int digit = 0;
  int total_count = 0;

  std::cout << "Enter the digit";
  do {
    char c = getchar();
    if(c == '\n') {
      break;
    }
    int digit = c - '0';
    //std::cout << digit << "\n";
    total_count++;
    if(total_count % 2) {

      odd += return_sum(digit);
      even += digit;
    }
    else {
      even += return_sum(digit);
      odd += digit;
    }
    std::cout << even <<"\n";
    //total_count++;
  }while(1);

  if((total_count - 1) % 2) {
    std::cout << odd << "\n";
    std::cout<< even<<"\n";
  } else
  {
    std::cout << odd << "*\n";
    std::cout<< even<<"*\n";
  }

}
