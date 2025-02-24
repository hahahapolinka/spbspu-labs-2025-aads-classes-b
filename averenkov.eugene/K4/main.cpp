#include <iostream>

int main(int arg)
{
  int data;
  std::cin >> data;
  if (std::cin.fail())
  {
    std::cerr << "error\n";
    return 1;
  }
  if (std::cin.eof())
  {
    return 0;
  }
  List* head = new List { data, nullptr };
  List* current = head;
  while (std::cin >> data)
  {
    try
    {
      current->next = new List { data, nullptr };
      current = current->next;
    }
    catch (...)
    {
      std::cerr << "memory error\n";
      return 1;
    }
  }
}
