#ifndef BUFFER
#define BUFFER

#include <string>
#include "Node.h"
class Buffer {
  public:
    Buffer();
    ~Buffer();
    
    bool isEmpty();
    
    void push(std::string data);
    void append(Buffer* buffer);
    std::string popFront();
    void jump(int pos);
    void clear();

    void print();
  
  private:
    Node<std::string>* position(int pos);
    
    int size;
    Node<std::string>* front;
    Node<std::string>* back;
};

#endif
