#ifndef SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K4_IO_UTILS_HPP
#define SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K4_IO_UTILS_HPP

#include <iostream>
#include "forward-list.hpp"

namespace kizhin {
  template < typename T >
  FwdList< T >* inputFwdList(std::istream& in)
  {
    FwdList< T >* result = nullptr;
    try {
      T currentData;
      in >> currentData;
      if (in.eof()) {
        return nullptr;
      }
      result = new FwdList< T >{ currentData, nullptr };
      FwdList< T >* currentNode = result;
      while (in >> currentData) {
        currentNode = new FwdList< T >{ currentData, nullptr };
      }
    } catch (...) {
      clear(result);
      throw;
    }
    return result;
  }
}

#endif

