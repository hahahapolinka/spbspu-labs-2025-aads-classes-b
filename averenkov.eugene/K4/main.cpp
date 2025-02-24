#include <iostream>
#include "list.hpp"

template < class T>
void deleteList(List< T >* head)
{
  while(head)
  {
    List< T >* fake = head;
    head = head->next;
    delete fake;
  }
}

template < class T >
void printList(List< T >* head)
{
  if (!head)
  {
    return;
  }
  std::cout << head->data;
  head = head->next;
  while(head)
  {
    std::cout << " " << head->data;
    head = head->next;
  }
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "Error!!\n";
    return 1;
  }
  int data = 0;
  std::cin >> data;
  if (std::cin.fail())
  {
    return 1;
  }
  List< int >* head = new List< int > { data, nullptr };
  List< int >* current = head;
  while (std::cin >> data)
  {
    try
    {
      current->next = new List< int > { data, nullptr };
      current = current->next;
    }
    catch (...)
    {
      std::cerr << "memory error\n";
      deleteList(head);
      return 1;
    }
  }
  if (std::atoi(argv[1]) == 0)
  {
    try
    {
      head = reverse_with_list(head);
    }
    catch (...)
    {
      std::cerr << "error\n";
      deleteList(head);
      return 1;
    }
  }
  else if (std::atoi(argv[1]) == 1)
  {
    head = reverse_cleanly(head);
  }
  else if (std::atoi(argv[1]) == 2)
  {
    head = reverse_recursively(head);
  }
  else
  {
    head = reverse_cleanly(head);
    std::cerr << "bad input!!\n";
  }
  printList(head);
  std::cout << "\n";
  deleteList(head);
  return 0;
}
