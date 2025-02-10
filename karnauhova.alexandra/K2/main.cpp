#include <cstddef>
#include <iostream>
struct FwdList {
  int value;
  FwdList * next;
};
void outputList(FwdList* head);
FwdList* editList(FwdList* head, int element, size_t count);
FwdList* createList();
void clear(FwdList* head);

int main()
{
  try
  {
    FwdList* head = createList();
    int element = 0;
    size_t count = 0;
    while (std::cin >> element && !std::cin.eof())
    {
      if (element > 10)
      {
        std::cerr << "Element out of range\n";
        return 1;
      }
      if (std::cin >> count && !std::cin.eof())
      {
        editList(head, element, count);
      }
    }
    outputList(head);
  }
  catch (std::bad_alloc& e)
  {
    std::cerr << "Out of memmory\n";
    return 1;
  }
}

void outputList(FwdList* head)
{
  std::cout << head->value;
  head = head->next;
  while (head)
  {
    std::cout << " " << head->value;
    head = head->next;
  }
  std::cout << "\n";
}
FwdList* editList(FwdList* head, int element, size_t count)
{
  FwdList* now = head;
  while (now->value != (element - 1))
  {
    now = now->next;
  }
  try
  {
    for (size_t i = 0; i < count; i++)
    {
      FwdList* new_element = new FwdList{element - 1, nullptr};
      new_element->next = now->next;
      now->next = new_element;
    }
  }
  catch (std::bad_alloc& e)
  {
    clear(head);
    throw;
  }
  return now;
}

FwdList* createList()
{
  FwdList* head = nullptr;
  try
  {
    head = new FwdList{0, nullptr};
    FwdList* now = head;
    for (int i = 1; i < 10; i++)
    {
      now->next = new FwdList{i, nullptr};
      now = now->next;
    }
    return head;
  }
  catch (std::bad_alloc& e)
  {
    clear(head);
    throw;
  }
}

void clear(FwdList* head)
{
  while (head)
  {
    FwdList* now = head->next;
    delete head;
    head = now;
  }
}
