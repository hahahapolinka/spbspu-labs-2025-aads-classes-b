#include <iostream>

template< class T >
struct BiTree {
  T data;
  BiTree< T > * left, * right;
};

template< class T >
class Comperator
{
public:
  Comperator(const BiTree< T > & head): value_(head)
  {} 
  bool funComp(const T & member)
  {
    bool correct = value_->data < member;
    return correct;
  }
private:
  BiTree< T > value_;
}

template< class T, class Cmp >
const BiTree< T > * find(const BiTree< T > * root, const T & value, Cmp cmp)
{

}

int main()
{

}
