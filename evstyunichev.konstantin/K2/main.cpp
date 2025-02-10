#include <iostream>

struct FwdList
{
  int value;
  FwdList *next;
};

FwdList * get_index(size_t target, FwdList *ptr, size_t cur_pos = 0)
{
  if (cur_pos == target)
  {
    return ptr;
  }
  return get_index(target, ptr->next, cur_pos++);
}

FwdList * add(FwdList *ptr, int value)
{
  FwdList *cur = new FwdList{value, nullptr};
  cur->next = ptr->next;
  ptr->next = cur;
  return cur;
}

FwdList * insert_to_pos(FwdList *head, size_t pos, size_t k)
{
  FwdList *ptr = get_index(pos, head);
  for (size_t i = 0; i < k; i++)
  {
    add(ptr, ptr->value);
    ptr = ptr->next;
  }
  return ptr;
}

void clear(FwdList *ptr)
{
  FwdList *cur = ptr;
  while (ptr)
  {
    cur = ptr->next;
    delete ptr;
    ptr = cur;
  }
  return;
}

int main()
{
  FwdList *head = new FwdList{0, nullptr}, *tail = head, *cur = head;
  size_t size = 0;
  for (size_t i = 1; i < 10; i++)
  {
    add(tail, i);
    tail = tail->next;
  }
  size = 10;
  int a = 0, b = 0;
  while (std::cin >> a >> b)
  {
    tail = ((a == size) ? insert_to_pos(head, a, b) : tail);
  }
  while (cur)
  {
    std::cout << cur->value << ' ';
    cur = cur->next;
  }
  clear(head);
  return 0;
}