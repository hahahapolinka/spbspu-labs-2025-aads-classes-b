#include <iostream>

template< class T >
struct List {
  T data;
  List< T > * next;
};

template< class T >
void clear(List< T >* head)
{
  while (head)
  {
    List< T >* current = head->next;
    delete head;
    head = current;
  }
}

template< class T >
List< T > * reverse_with_list(List< T >* head)
{

}

template< class T >
List< T > * reverse_cleanly(List< T > * head) noexcept
{

}

template< class T >
void output_list(std::ostream& out, List< T > * head)
{

}

int main(int argc, char** argv)
{

}