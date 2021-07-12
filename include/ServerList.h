#ifndef SERVER_LIST
#define SERVER_LIST

#include <string>
#include "Buffer.h"
#include "Node.h"

class ServerList {
  public:
    ServerList();
    ~ServerList();

    bool isEmpty();
    
    Buffer* getBuffer(int server);
    void push(Buffer* buffer);
    void sendToServer(int server, std::string data);
    void popAll(Buffer* destiny);
    void clear();

    void print();

  private:
    Node<Buffer*>* getServer(int server);

    int size;
    Node<Buffer*>* first;
    Node<Buffer*>* last;

  friend class Controller;
};

#endif
