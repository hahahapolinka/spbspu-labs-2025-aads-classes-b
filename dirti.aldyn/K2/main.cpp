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
      clear(head);
      throw;
    }
}

void clear(FwdList * head)
{
  while (head->next)
  {
    FwdList * nextHead = head->next;
    delete head;
    head = nextHead;
  }
}

void newList(FwdList * head, size_t number, size_t size)
{
  FwdList * tempHead = head;
  for (size_t i = 1; i < number; ++i)
  {
    tempHead = tempHead->next;
    if (!tempHead)
    {
      clear(head);
      throw;
    }
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
  size_t number = 0;
  size_t size = 0;
  while (std::cin)
  {
    if (std::cin >> number >> size)
    {
      try
      {
        newList(head, number, size);
      }
      catch (const std::exception & e)
      {
        clear(head);
        std::cerr << "Error" << "\n";
        return 1;
      }
    }
  }
}
