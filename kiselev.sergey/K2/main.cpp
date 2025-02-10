#include <exception>
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
FwdList* createList(FwdList* head)
{
  try
  {
    FwdList* head = new FwdList { 1, nullptr };
    FwdList* head_ = head;
    const size_t size = 10;
    for (int i = 2; i < size; ++i)
    {
      head->next = new FwdList { i, nullptr };
      head = head->next;
    }
    return head_;
  }
  catch (...)
  {
    throw;
  }
}
FwdList* addNumber(FwdList* head, size_t number, size_t count)
{
  FwdList* element = nullptr;
  for (size_t i = 0; i < number + 1; ++i)
  {
    element = head;
    head = head->next;
  }
  for (size_t i = 0; i < count; ++i)
  {
    try
    {
      FwdList* node = new FwdList { element->value, nullptr };
      node->next = element->next;
      element->next = node;
    }
    catch (...)
    {
      throw;
    }
  }
  return element;
}
bool isRange(FwdList* head, size_t number)
{
  for (size_t i = 1; i < number; ++i)
  {
    if (!head->next)
    {
      return true;
    }
    head = head->next;
  }
  return false;
}
std::ostream& outputList(std::ostream& out, FwdList* head)
{
  out << head->value;
  head = head->next;
  while (head)
  {
    out << " " << head->value;
    head = head->next;
  }
  return out;
}
int main()
{
  FwdList* head = nullptr;
  size_t number = 0;
  size_t count = 0;
  try
  {
    head = createList(head);
    while (std::cin >> number >> count)
    {
      if (isRange(head, number))
      {
        deleteList(head);
        return 1;
      }
      addNumber(head, number, count);
    }
    outputList(std::cout, head) << "\n";
  }
  catch (const std::exception&)
  {
    deleteList(head);
    return 1;
  }
  deleteList(head);
  return 0;
}
