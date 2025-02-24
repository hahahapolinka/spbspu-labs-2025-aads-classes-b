#include <iostream>

template< class T >
struct List {
  T data;
  List< T > * next;
};

template< class T >
List< T >* create_element(List< T >* last, T element)
{
    last->next = new List< T >{element, nullptr};
    return last->next;
}

template< class T >
void clear(List< T >* head)
{
  while (head)
  {
    List< T >* now = head->next;
    delete head;
    head = now;
  }
}

int main(int argc, char ** argv)
{
  int x = 0;
  List< int >* head = nullptr;
  List< int >* last = head;
  try
  {
    while (std::cin >> x && !std::cin.eof())
    {
      last = create_element(last, x);
    }
  }
  catch (const std::bad_alloc& e)
  {
    clear(head);
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (!std::cin.eof())
  {
    std::cerr << "Error in input\n";
    clear(head);
    return 1;
  }
}