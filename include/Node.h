#ifndef NODE
#define NODE

template <class T> class Node {
  public:
    Node() {
      item = T();
      next = nullptr;
    }

  private:
    T item;
    Node* next;

  friend class Buffer;
  friend class ServerList;
};

#endif
