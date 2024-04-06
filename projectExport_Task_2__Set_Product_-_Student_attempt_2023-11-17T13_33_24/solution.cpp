#include <string>
#include <vector>

#include "set.h"
#include "solution.h"



StringSet set_product(const std::vector<CharSet>& sets) {

  if (sets.size() == 0) {
    return StringSet ("");
  }
  StringSet result;
  if (sets.size() == 1) {
    const CharSet& set0 = sets.at(0);
    for (unsigned int i = 0; i < set0.size(); ++i) {
      const char ci = set0.at(i);
      std::string si {ci};
      result.insert (si);
    }
  }

  else {
    std::vector<CharSet> new_vec = sets;
    CharSet last_set = new_vec.back();
    new_vec.pop_back();

    StringSet temp = set_product (new_vec);

    for (unsigned int i = 0; i < temp.size(); ++i) {
      for (unsigned int j = 0; j < last_set.size(); ++j) {
        const char cj = last_set.at(j);
        result.insert(temp.at(i) + cj);
      }
    }
  }
  return result;
}