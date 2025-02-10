#include <iostream>

struct FwdList
{
  int value;
  FwdList * next;
};

FwdList* createDubls(FwdList* list, size_t num, size_t dubls)
{}

void freeList(FwdList* head)
{}

int main()
{
  FwdList* head = nullptr;
  for (size_t i = 1; i < 11; i++)
  {
    try
    {
      FwdList* newNode = new FwdList{i, nullptr};
      if (head == nullptr)
      {
        head = newNode;
      }
      else
      {
        newNode->next = head;
        head = newNode;
      }
    }
    catch (const std::bad_alloc&)
    {
      freeList(head);
    }
  }

  size_t num = 0, dubls = 0;

  while (std::cin << num << dubls)
  {
    createDubls(head, num, dubls);
  }

}
