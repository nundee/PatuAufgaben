#pragma once

// Defines CharSet and StringSet.
using CharSet = Set<char>;
using StringSet = Set<std::string>;

StringSet set_product(const std::vector<CharSet>& sets);