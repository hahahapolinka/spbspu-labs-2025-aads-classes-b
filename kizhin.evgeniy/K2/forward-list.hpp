#ifndef SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K2_FORWARD_LIST_HPP
#define SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K2_FORWARD_LIST_HPP

#include <cstddef>

namespace kizhin {
  struct FwdList
  {
    int value;
    FwdList* next;
  };

  FwdList* initList(int, int);
  FwdList* insertDuplicates(FwdList*, std::size_t, std::size_t);
}

#endif

