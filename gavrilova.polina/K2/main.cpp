#include <iostream>

struct FwdList {
  int value;
  FwdList * next;
};

FwdList* dublicate(FwdList* head, size_t for_dubl, size_t number);
FwdList* createList(FwdList* head, int size);
void clear(FwdList* head, size_t size);
void clear(FwdList* head);
void outList(FwdList* head);

int main()
{
  FwdList* head = nullptr;
  try {
    head = createList(head, 10);
  } catch(const std::bad_alloc &) {
    std::cerr << "Memory error!";
    return 1;
  }

  while (std::cin && !std::cin.eof()) {
    size_t for_dubl = 0;
    size_t num = 0;
    std::cin >> for_dubl >> num;
    FwdList* node = nullptr;
    try {
      node = dublicate(head, for_dubl, num);
    } catch(const std::bad_alloc&) {
      std::cerr << "Memory error!";
      return 1;
    }
    node->next = nullptr;
  }

  outList(head);
  clear(head);
}

FwdList* createList(FwdList * head, int size)
{
  head = new FwdList{0, nullptr};
  FwdList* cur = head;
  for (int i = 1; i < size; ++i) {
    try {
      cur->next = new FwdList{i, nullptr};
      cur = cur->next;
    } catch(const std::bad_alloc&) {
      clear(head, i);
      throw;
    }
  }
  return head;
}

FwdList* dublicate(FwdList* head, size_t for_dubl, size_t number)
{
  for (size_t i = 0; i < for_dubl; ++i) {
    head = head->next;
  }
  FwdList* cur = head;
  for (size_t i = 0; i < number; ++i) {
    try {
      FwdList* node = new FwdList{cur->value, nullptr};
      node->next = cur->next;
      cur->next = node;
      cur = node;
    } catch(const std::bad_alloc&) {
      clear(head->next, i);
      throw;
    }
  }
  return head;
}

void clear(FwdList* head, size_t size)
{
  FwdList* new_head = head->next;
  for (size_t i =0; i < size; ++i) {
    delete head;
    head = new_head;
    new_head = head->next;
  }
}

void clear(FwdList* head)
{
  FwdList * new_head = head->next;
  while (head->next) {
    delete head;
    head = new_head;
    new_head = head->next;
  }
}

void outList(FwdList* head) {
  std::cout << head->value;
  while (head->next) {
    std::cout << " ";
    std::cout << head->next->value;
    head = head->next;
  }
  std::cout << "\n";
}
