#include <iostream>

template< class T >
struct List
{
  T data;
  List< T > * next;
}
template< class T >
void clear(List< T > * head)
{
  List< T > * deletehelp = head->next;
  while (deletehelp->value != nullptr)
  {
    delete head;
    head = deletehelp;
    deletehelp = deletehelp->next;
  }
  delete head;
}

template< class T >
List< T > * reverse_with_list(List< T > * head)
{

}

template< class T >
List< T > * reverse_cleanly(List< T > * head) noexcept
{

}

template< class T >
List< T > * reverse_recursively(List< T > * head) noexcept
{

}

int main (int argc) 
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
  try
  {
    List * head = new List{a, nullptr};
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory!\n";
    return 1;
  }
  List * tail = head;
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
      tail->next = new List{a, nullptr};
    }
    catch (const std::bad_alloc& e)
    {
      clear(head);
      std::cerr << "Not enough memory!\n";
      return 1;
    }
    tail = tail->next;
  }
  
}