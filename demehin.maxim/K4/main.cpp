#include <iostream>

template< class T >
struct List
{
  T data;
  List< T >* next;
};

template< class T >
List< T >* reverse_with_list(List< T >* head)
{
  return nullptr;
}

template< class T >
List< T >* reverce_cleanly(List< T >* head) noexcept
{
  return nullptr;
}

template< class T >
List< T >* reverse_recursively(List< T >* head) noexcept
{
  return nullptr;
}

template< class T >
void free_list(List< T >* head)
{
  List< T >* current = head;
  while (current != nullptr)
  {
    List< T >* next = current->next;
    delete current;
    current = next;
  }
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    return 1;
  }
  int num = 0;
  std::cin >> num;
  List< int >* head = new List< int >{num, nullptr};
  try
  {
    while(std::cin >> num)
    {
      if (!std::cin)
      {
        std::cerr << "incorrect input\n";
        free_list(head);
        return 1;
      }
      List< int >* newNode = new List< int >{num, nullptr};
      List< int >* current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = newNode;
    }
  }
  catch (const std::bad_alloc&)
  {
    free_list(head);
    return 1;
  }


  std::string param = argv[1];
  if (param == "1")
  {
    std::cout << "fgsgsg\n";
  }

  free_list(head);
}
