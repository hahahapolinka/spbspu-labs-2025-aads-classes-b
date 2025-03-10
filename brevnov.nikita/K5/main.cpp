#include <iostream>

template< class T >
struct BiTree {
  T data;
  BiTree< T > * left, * right;
};

template< class T >
class Cmp
{
public:
  Cmp(const BiTree< T > & head): value_(head)
  {} 
  bool funComp(const T & mem1, const T & mem2)
  {
    bool correct = mem1 <= mem2;
    return correct;
  }
private:
  BiTree< T > value_;
}

template< class T >
void addElTree(BiTree< T > * root, const T & value, Cmp cmp)
{
  BiTree< T > * sub = root;
  bool done = false;
  while (!done)
  {
    if (cmp.funComp(sub->data, value))
    {
      if (sub->right == nullptr)
      {
        sub->right = new BiTree< T >{value, nullptr, nullptr};
        done = true;
      }
      else
      {
        sub = sub->right;
      }
    }
    else
    {
      if (sub->left == nullptr)
      {
        sub->left = new BiTree< T >{value, nullptr, nullptr};
        done = true;
      }
      else
      {
        sub = sub->left;
      }
    }
  }
}

template< class T >
void clear(BiTree< T > * head)
{
  BiTree< T > * sub = head->left;
  while (head->left != nullptr && head->right = nullptr)
  {
    if (sub->left == nullptr && sub->right == nullptr)
    {
      delete sub;
      if (head->left == nullptr)
      {
        sub = head->right;
      }
      else
      {
        sub = head->left;
      }
    }
    else if (sub->left != nullptr)
    {
      sub = sub->left;
    }
    else
    {
      sub = sub->right;
    }
  }
  delete head;
}

template< class T, class Cmp >
const BiTree< T > * find(const BiTree< T > * root, const T & value, Cmp cmp)
{

}

int main()
{

}
