#ifndef BITREE_HPP
#define BITREE_HPP

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

#endif