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
    FwdList* interim = head;
    while (head) {
      interim = head->next;
      delete head;
      head = interim;
    }
  }
}