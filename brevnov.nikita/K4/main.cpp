#include <iostream>

template< class T >
struct List
{
  T data;
  List< T > * next;
};

template< class T >
void clear(List< T > * head)
{
  List< T > * deletehelp = head->next;
  while (deletehelp->next != nullptr)
  {
    delete head;
    head = deletehelp;
    deletehelp = deletehelp->next;
  }
  delete head;
}

template< class T >
void outputing(List< T > * head, std::ostream& out)
{
  std::cout << head->value;
  while (head->next != nullptr)
  {
    std::cout << " " << head->next->value;
    head = head->next;
  }
}

template< class T >
List< T > * reverse_with_list(List< T > * head)
{
  List< T > * dhead = head;
  List< T > * last = new List< T >{help->value, nullptr};
  while (dhead->next != nullptr)
  {
    dhead = dhead->next;
    last = new List< T >{dhead->value, last};
  }
  clear(head);
  return last;
}

template< class T >
List< T > * reverse_cleanly(List< T > * head) noexcept
{
  List< T > * nextl = head->next;
  List< T > * help = nextl->next;
  head->next = nullptr;
  while (help != nullptr)
  {
    nextl->next = head;
    head = nextl;
    nextl = help;
    help = help->next;
  }
  nextl->next = head;
  return nextl;
}

template< class T >
List< T > * headreturn(List< T > * head, List< T > * nextl) noexcept
{
  if (nextl == nullptr)
  {
    return head;
  }
  else
  {
    List< T > * help = nextl->next;
    nextl->next = head;
    return headreturn(nextl, help);
  }
}

template< class T >
List< T > * reverse_recursively(List< T > * head) noexcept
{
  List< T > * nextl = head->next;
  head->next = nullptr;
  nextl->next = head;
  return headreturn(nextl, nextl->next);
}

int main (int argc, char** argv)
{
  int a = 0;
  std::cin >> a;
  if (std::cin.fail())
  {
    std::cerr << "Not correct input\n";
    return 1;
  }
  else if (std::cin.eof())
  {
    std::cout << "\n";
    return 0;
  }
  List< int > * head = nullptr;
  try
  {
    head = new List< int >{a, nullptr};
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory!\n";
    return 1;
  }
  List< int > * tail = head;
  while (!std::cin.eof())
  {
    std::cin >> a;
    if (std::cin.fail())
    {
      std::cerr << "Not correct input\n";
      return 1;
    }
    try
    {
      tail->next = new List< int >{a, nullptr};
    }
    catch (const std::bad_alloc& e)
    {
      clear(head);
      std::cerr << "Not enough memory!\n";
      return 1;
    }
    tail = tail->next;
  }
  if (argc == 2)
  {
    head = reverse_recursively(head);
  }
  else if (argc == 0)
  {
    try
    {
      head = reverse_with_list(head);
    }
    catch (const std::bad_alloc& e)
    {
      clear(head);
      std::cerr << "Not enough memory!\n";
      return 1;
    }
  }
  else
  {
    head = reverse_cleanly(head);
  }
  outputing(head, std::cout);
  clear(head);
  std::cout << "\n";
  return 0;
}
