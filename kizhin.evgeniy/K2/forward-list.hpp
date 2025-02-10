#ifndef SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K2_FORWARD_LIST_HPP
#define SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K2_FORWARD_LIST_HPP

namespace kizhin {
  struct FwdList
  {
    int value;
    FwdList* next;
  };

  FwdList* initList(int, int);
}

#endif

