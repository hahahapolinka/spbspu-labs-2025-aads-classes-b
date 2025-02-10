struct FwdList
{
  int value;
  FwdList * next;
};

struct ListIterator
{
  FwdList* node;
  using this_t = ListIterator;

  ListIterator(): node(nullptr) {}
  ~ListIterator() = default
  ListIterator(const this_t&) = default;
  this_t& operator=(const this_t&) = default;

  this_t& operator++();
  this_t operator++(int);

  int& operator*();
  int* operator->();

  bool operator!=(const this_t&) const;
  bool operator==(const this_t&) const;
};

ListIterator::this_t& ListIterator::operator++()
{
  assert(node != nullptr);
  node = node->next;
  return *this;
}

ListIterator::this_t& ListIterator::operator++(int)
{
  assert(node != nullptr);
  this_t result(*this);
  ++(*this);
  return result;
}


int main()
{
  size_t input[10000] = {};
  while
}

FwdList* editList(FwdList* head, size_t element, size_t count)
{
  FwdList* now = head;
  for (size_t i = 1; i < element; i++)
  {
    now = now->next;
  }
}
