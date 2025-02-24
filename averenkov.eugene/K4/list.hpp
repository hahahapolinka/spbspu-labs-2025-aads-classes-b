#ifndef LIST_HPP
#define LIST_HPP

template< class T >
struct List
{
  T data;
  List< T >* next;
};

template< class T >
void pushIn(List< T >* head, int data)
{
  List< T >* newList = new List< T > {data, nullptr};
  newList->next = head;
  head = newList;
}

template< class T >
List< T >* reverse_with_list(List< T >* head)
{
  List< T >* newHead = nullptr;
  while (head)
  {
    pushIn(head, head->data);
    head = head->next;
  }
  return newHead;
}

template< class T >
List< T >* reverse_cleanly(List< T >* head) noexcept
{
  List< T >* prev = nullptr;
  List< T >* current = head;
  List< T >* next = nullptr;
  while (current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

template< class T >
List< T >* reverse_recursively(List< T >* head) noexcept
{
  if (!head || !head->next)
  {
    return head;
  }
  List< T >* newHead = reverse_recursively(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

#endif
