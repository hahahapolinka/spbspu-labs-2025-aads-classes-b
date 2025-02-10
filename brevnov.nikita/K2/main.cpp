#include <iostream>

struct FwdList {
  int value;
  FwdList * next;
};

void addElements(FwdList * head, int a, int b)
{
  FwdList * help = head;
  for (size_t i = 0; i < a - 1; i++)
  {
    help = help->next;
  }
  int value = help->value;
  for (size_t i = 0; i < b; i++)
  {
    help->next = new FwdList{value, help->next};
    help = help->next;
  }
}

int main() 
{
  FwdList * head = new FwdList{0, nullptr};
  FwdList * tail = head;
  for (size_t i = 1; i < 10; i++)
  {
    tail->next = new FwdList{i, nullptr};
    tail = tail->next;
  }
  int size = 10;
  int a = 0, b = 0;
  while (!std::cin.eof())
  {
    std::cin >> a;
    if (std::cin.eof() || std::cin.fail() || a <= 0)
    {
      break;
    }
    std::cin >> b;
    if (std::cin.fail())
    {
      break;
    }
    if (a > size)
    {
      std::cerr << "Index out of range!\n";
      return 1;
    }
    addElements(head, a, b);
    size += b;
  }
}
