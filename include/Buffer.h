#ifndef BUFFER
#define BUFFER

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
