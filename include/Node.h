#include <string>

class Node {
  public:
    Node();

  private:
    std::string data;
    Node* next;

  friend class Buffer;
};
