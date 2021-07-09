#include <string>
#include "Node.h"

class Buffer {
  public:
    Buffer();
    ~Buffer();
    
    int getSize();
    bool isEmpty();
    
    void push(std::string data);
    std::string popFront();
    void clear();

    void print();
  
  private:
    int size;
    Node<std::string>* front;
    Node<std::string>* back;
};
