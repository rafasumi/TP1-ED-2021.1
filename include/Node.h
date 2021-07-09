template <class T> class Node {
  public:
    Node() {
      data = T();
      next = nullptr;
    }

  private:
    T data;
    Node* next;

  friend class Buffer;
};
