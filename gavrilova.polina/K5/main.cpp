#include <iostream>

template< class T >
struct BiTree {
  T data;
  BiTree< T > * left, * right;
};

template< class T, class Cmp >
BiTree< T > * find(BiTree< T > * root, const T & value, Cmp cmp);

template< class T, class Cmp >
BiTree< T > * insertBT(T new_val, BiTree< T > * root, Cmp cmp);

template< class T >
void clear(BiTree< T > * root);

bool pred(size_t first, size_t second) {
  return first < second;
}

int main()
{
  size_t n = 0;
  if (!(std::cin >> n)) {
    std::cerr << "Invalid input!\n";
    return 1;
  }
  BiTree< size_t >* root = nullptr;
  for (; n > 0; --n) {
    size_t cur_num = 0;
    if (!(std::cin >> cur_num)) {
      std::cerr << "Invalid input!\n";
      return 1;
    }
    
    try {
      root = insertBT<size_t>(cur_num, root, pred);
    } catch(const std::bad_alloc) {
      clear< size_t>(root);
      std::cerr << "Memory error!\n";
      return 1;
    }
  }

  size_t num_for_search = 0;
  while (!std::cin.eof() || std::cin >> num_for_search) {
    if (find(root, num_for_search, pred)) {
      std::cout << "<FOUND>\n";
    } else {
      std::cout << "<NOT FOUND>\n";
    }
  }
}

template< class T, class Cmp >
BiTree< T > * insertBT(T new_val, BiTree< T > * root, Cmp cmp)
{
  BiTree< T >* cur_root = root;
  while (cur_root) {
    if (cmp(root->data, new_val)) {
      cur_root = cur_root->left;
    } else {
      cur_root = cur_root->right;
    }
  }
  cur_root = new BiTree<T>{new_val, nullptr, nullptr};
  return cur_root;
}

template< class T >
void clear(BiTree< T > * root)
{
  if (!root) {
    return;
  }
  clear< T >(root->left);
  clear< T >(root->right);
  delete root;
}

template< class T, class Cmp >
BiTree< T > * find(BiTree< T > * root, const T & value, Cmp cmp)
{
  while (root && root->data != value) {
    if (cmp(root->data, value)) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return root;
}