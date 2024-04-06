#include <iostream>
#include <string>
#include <vector>

#include "set.h"
#include "solution.h"

int main() {

  unsigned int n;
  std::cout << "Number of sets: ";
  std::cin >> n;

  std::vector<CharSet> sets;
  for (unsigned int i = 0; i < n; ++i) {
    std::cout << "Set " << i << ": ";
    CharSet set;
    std::cin >> set;
    sets.push_back(set);
  }

  StringSet product = set_product(sets);
  std::cout << "Product Set:" << std::endl << product << std::endl;

  return 0;
}