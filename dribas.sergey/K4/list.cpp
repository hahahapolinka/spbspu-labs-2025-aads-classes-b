#include "list.hpp"

template< class T >
dribas::List < T > * dribas::input(List < T > * head, std::istream& in)
{
  in >> head.data;
  head.next = new List< T >;
  return head;
}

template< class T >
void dribas::clear(List < T > * head)
{
  if (head) {
    List < T > * interim = head;
    while (head) {
      interim = head->next;
      delete head;
      head = interim;
    }
  }
}

template< class T >
dribas::List< T > * dribas::reverse_with_list(List< T > * head)
{
  List< T > * stackH = nullptr;

  while(head != nullptr) {
    List< T > * node = new List < T >{head->data, stackH};
    stackH = node;
    head = head.next;
  }
  return stackH;
}