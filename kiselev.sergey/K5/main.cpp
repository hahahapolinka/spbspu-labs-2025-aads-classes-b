#include <iostream>
#include <new>
template< class T >
struct BiTree {
    T data;
    BiTree< T >* left, * right;
};

template< class T, class Cmp = std::less< T > >
BiTree< T >* find(const BiTree< T >* root, const T& value, Cmp = Cmp{})
{
  while (root)
  {
    if (!cmp(value, root->data))
    {
      root = root->right;
    }
    else if (cmp(value, root->data))
    {
      root = root->left;
    }
    else
    {
      return root;
    }
  }
  return nullptr;
}

template< class T, class Cmp = std::less< T > >
void pushTree(BiTree< T >* root, const T& value, Cmp = Cmp{})
{
  while(root)
  {
    if (cmp(value, root->data))
    {
      root = root->left;
    }
    else
    {
      root = root->left;
    }
  }
  root = new BiTree< T >{ value, nullptr, nullptr };
}

template< class T >
void deleteTree(BiTree< T >* root)
{
  if (root->left)
  {
    deleteTree(root->left);
  }
  else if (root->right)
  {
    deleteTree(root->right);
  }
  delete root;
}

int main()
{
  size_t length = 0;
  std::cin >> length;
  if (length == 0)
  {
    std::cout << "sequence length 0\n";
    return 0;
  }
  BiTree< int >* root = nullptr;
  for (size_t i = 0; i < length; ++i)
  {
    int number;
    if (!(std::cin >> number))
    {
      std::cerr << "Incorrect number\n";
      deleteTree(root);
      return 1;
    }
    try
    {
      pushTree(root, number);
    }
    catch (std::bad_alloc&)
    {
      deleteTree(root);
      std::cerr << "Out of memory\n";
      return 0;
    }
  }
  int findNum;
  while (std::cin >> findNum)
  {
    if (!std::cin.eof() && std::cin.fail())
    {
      std::cerr << "Incorrect number\n";
      deleteTree(root);
      return 1;
    }
    if (find(root, findNum))
    {
      std::cout << "<FOUND>\n";
    }
    else
    {
      std::cout << "<NOT FOUND>\n";
    }
  }
  deleteTree(root);
  return 0;
}
