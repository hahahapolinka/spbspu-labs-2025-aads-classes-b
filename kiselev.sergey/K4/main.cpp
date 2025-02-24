#include <exception>
#include <iostream>
#include <new>
#include <ostream>
#include <stdexcept>
template< class T >
struct List
{
  T data;
  List< T >* next;
};

template< typename T >
void deleteList(List< T >* list)
{
  while (list)
  {
    List< T >* temp = list->next;
    delete list;
    list = temp;
  }
}

template< typename T >
List< T >* createList(std::istream& input, List< T >* list)
{
  List< T >* head = list;
  try
  {
    while (!(input.eof()))
    {
      int a = 0;
      input >> a;
      if (!input)
      {
        throw std::logic_error("Incorrect number");
      }
      list = new List< T >{ a, nullptr };
      list = list->next;
    }
    return head;
  }
  catch (const std::exception&)
  {
    deleteList(head);
    throw;
  }
}

template< typename T >
List< T >* reverse_with_list(List< T >* head)
{
  List< T >* stack = nullptr;
  List< T >* temp = head;
  try
  {
    while (temp != nullptr)
    {
      List< T >* node = new List< T >{ temp->data, stack };
      stack = node;
      temp = temp->next;
    }
    return stack;
  }
  catch (const std::bad_alloc&)
  {
    deleteList(stack);
    throw;
  }
}

template < typename T >
List< T >* reverse_cleanly(List< T >* head) noexcept
{
  List< T >* prev = nullptr;
  List< T >* temp = head;
  List< T >* next = nullptr;
  while (temp != nullptr)
  {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  return prev;
}

template< typename T >
List< T >* reverse_recursively(List< T >* head) noexcept
{
  List< T >* temp = reverse_recursively(head->next);
  head->next->next = head;
  head->next = nullptr;
  return temp;
}
template< typename T >
std::ostream& printList(std::ostream& output, List< T >* list)
{
  output << list->data;
  list = list->next;
  while (list)
  {
    output << " " << list->data;
    list = list->next;
  }
  return output;
}

int main(int argc, char** argv)
{
  List< int >* list = nullptr;
  try
  {
    list = createList(std::cin, list);
    if (argc == 0)
    {
      reverse_with_list(list);
    }
    else if (argc == 1)
    {
      reverse_cleanly(list);
    }
    else if (argc == 2)
    {
      reverse_recursively(list);
    }
    else
    {
      std::cerr << "Unknown parameter\n";
      reverse_cleanly(list);
    }
    printList(std::cout, list) << "\n";
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    deleteList(list);
    return 1;
  }
}
