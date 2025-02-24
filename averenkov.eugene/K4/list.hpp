template< class T >
struct List
{
  T data;
  List< T >* next;
};
// 1
template< class T >
void pushIn(List< T >* head, int data)
{
  List< T >* newList = new List< T > {data, nullptr};
  newList->next = head;
  head = newNode;
}

template< class T >
List< T >* reverse_with_list(List< T >* head)
{
  Node* newHead = nullptr;
  while (head)
  {
    pushIn(head, head->data);
    head = head->next;
  }
  return newHead;
}
// 2
template< class T >
List< T >* reverse_cleanly(List< T >* head) noexcept
{

}
// 3
template< class T >
List< T >* reverse_recursively(List< T >* head) noexcept
{

}
