#include <iostream>

struct FwdList {
  int value;
  FwdList * next;
};

void addElements(FwdList * head, int a, int b)
{

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
    if (a > size)
    {
      std::cerr << "Index out of range!\n";
      return 1;
    }
    addElements(head, a, b);
    size += b;
  }
}
