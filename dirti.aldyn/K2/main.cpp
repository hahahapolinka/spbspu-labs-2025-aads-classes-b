#include <iostream>
#include <stdexcept>

struct FwdList
{
  int value;
  FwdList * next;
}

void startList(FwdList * head)
{
  FwdList * tempHead = head;
  for (size_t i = 1; i < 10, ++i)
  {
    try
    {
      tempHead->next = new FwdList{i, nullptr};
      tempHead = tempHead->next;
    }
    catch (const std:bad_alloc & e)
    {
      tempHead = head;
      for (size_t j = 0; j < i; ++j)
      {
        FwdList * nextHead = tempHead->next;
        delete tempHead;
        tempHead = nextHead;
      }
      throw;
    }
}

int main()
{
  try
  {
    FwdList * head = new FwdList{0, nullptr};
    startList(head);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error" << "\n";
    return 1;
  }
  
}
