#include <iostream>
#include <stdexcept>

template< class T >
struct List {
  T data;
  List< T > * next;
};
// 1
template< class T >
List< T > * reverse_with_list(List< T > * head);
// 2
template< class T >
List< T > * reverse_cleanly(List< T > * head) noexcept;
// 3
template< class T >
List< T > * reverse_recursively(List< T > * head) noexcept;

template< class T >
void clear(List< T > * head);

template< class T >
void push_back(List< T > * head, T data);

template< class T >
void push_front(List< T > * head, T data);

template< class T >
void clear(List< T > * head)
{
  List< T > * cur = head;
  while (head)
  {
    head = head->next;
    delete cur;
  }
  return;
}

template< class T >
void push_back(List< T > * head, T data)
{
  List< T > * cur = new List< T >{data, head->next};
  head->next = cur;
  return;
}

template< class T >
List< T > * push_front(List< T > * head, T data)
{
  List< T > * cur = new List< T >{data, head};
  return cur;
}

template< class T >
void insert_from_begin(List< T > * node, List< T > * tail)
{
  List< T > *cur = nullptr;
  if (tail->next)
  {
    cur = tail->next->next;
  }
  tail->next = 
  return;
}

template< class T >
List< T > * reverse_with_list(List< T > * head)
{
  List< T > * cur = nullptr;
  try
  {
    List< T > * cur = new List< T >{head->data, nullptr};
    while (head)
    {
      head = head->next;
      cur = push_front(cur, head);
    }
    return cur;
  }
  catch (const std::bad_alloc &e)
  {
    clear(cur);
    throw;
  }
}

template< class T >
List< T > * reverse_cleanly(List< T > * head) noexcept
{
  List< T > * cur = head;
  while (cur->next)
  {
    cur = cur->next;
  }

}

template< class T >
List< T > * reverse_recursively(List< T > * head) noexcept
{
  if (head->next)
  {
    List< T > * cur = head->next->next;
    head->next->next = head;
    return reverse_recursively(head->next);
  }
  return head;
}

int main()
{
  
}

