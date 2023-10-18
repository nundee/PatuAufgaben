#include <iostream>

int main() {
 
  unsigned int m;
  std::cin >> m;
  unsigned int n_1 = 1;
  unsigned int n_2 = 1;
  unsigned int prime_counter = 0;
 
  for (unsigned int i = 2; i <= m; i = n_1 + n_2){
    n_2 = n_1;
    n_1 = i;
    std::cout << "testing " << i << std::endl;
    bool is_prime=true;
    for (unsigned int n = 2; n*2 <= i; n++) {                   //check if prime
      if (i%n == 0) {
        //n = i*3;                                                //exit loop
        is_prime=false;
        break;;
      }
     
    //   if (n*2 == i && n != i*3) {
       
    //     std::cout << i;
    //     std::cout << ", ";
    //     prime_counter++;
       
    //   }
    }
    if(is_prime)
    {
        std::cout << i;
        std::cout << ", ";
        prime_counter++;
    }
    //std::cout << i << ", ";

  }
 
  std::cout <<  " Amount of primes: " << prime_counter << std::endl;
 
}
