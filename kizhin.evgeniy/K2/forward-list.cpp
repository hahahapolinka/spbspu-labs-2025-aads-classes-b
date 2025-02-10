#include "forward-list.hpp"
#include <cassert>

namespace kizhin {
  void clear(FwdList*) noexcept;
}

kizhin::FwdList* kizhin::initList(int start, const int stop)
{
  FwdList* head = new FwdList{ start++, nullptr };
  FwdList* current = head;
  try {
    for (; start != stop; ++start) {
      current->next = new FwdList{ start, nullptr };
      current = current->next;
    }
  } catch (...) {
    clear(head);
    throw;
  }
  return head;
}

void kizhin::clear(FwdList* head) noexcept
{
  assert(head);
  FwdList* tmp = head;
  while (head->next) {
    tmp = head->next;
    delete head;
    head = tmp;
  }
  delete head;
}

