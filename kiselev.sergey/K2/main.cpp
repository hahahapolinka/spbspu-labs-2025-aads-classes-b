#include <iostream>
#include <stddef.h>
struct FwdList
{
  int value;
  FwdList* next;
};
void deleteList(FwdList* list)
{
  while (list)
  {
    FwdList* temp = list->next;
    delete list;
    list = temp;
  }
}
FwdList* createList()
{
  try
  {
    FwdList* head = new FwdList { 0, nullptr };
    FwdList* head_ = head;
    const size_t size = 10;
    for (int i = 1; i < size; ++i)
    {
      head->next = new FwdList { i, nullptr };
      head = head->next;
    }
    return head_;
  }
  catch (...)
  {
    deleteList(head_);
    throw;
  }
}
int main()
{
  size_t number = 0;
  size_t count = 0;
  if (!(std::cin >> number >> count))
  {
    std::cerr << "Incorrect input\n";
    return 1;
  }
  FwdList* head = createList();
}
