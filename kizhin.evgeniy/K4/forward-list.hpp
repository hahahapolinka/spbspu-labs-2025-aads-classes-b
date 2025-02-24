#ifndef SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K4_FORWARD_LIST_HPP
#define SPBSPU_LABS_2025_AADS_CLASSES_B_KIZHIN_EVGENIY_K4_FORWARD_LIST_HPP

namespace kizhin {
  template < typename T >
  struct FwdList
  {
    T value;
    FwdList* next;
  };

  template < typename T >
  void clear(FwdList< T >* head) noexcept
  {
    FwdList< T >* tmp = nullptr;
    while (head != nullptr) {
      tmp = head;
      head = head->next;
      delete tmp;
    }
  }
}

#endif

