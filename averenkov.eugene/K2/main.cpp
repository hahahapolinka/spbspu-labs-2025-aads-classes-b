#include <iostream>

struct FwdList
{
  int value;
  FwdList* next;
};

FwdList* ListManip(FwdList* head, size_t number, size_t count)
{
  FwdList* correct = head;
  for (size_t i = 0; i < number; i++)
  {
    correct = correct->next;
  }
  FwdList* point = correct;
  FwdList* dubl = correct->next;
  for (size_t i = 0; i < count; i++)
  {
    correct->next = correct;
    correct = correct->next;
  }
  correct->next = dubl;
  return point;
}

int main()
{
  constexpr size_t size = 10;
