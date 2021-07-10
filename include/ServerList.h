#ifndef SERVER_LIST
#define SERVER_LIST

#include "Buffer.h"
#include "Node.h"

class ServerList {
  public:
    ServerList();
    ~ServerList();

    int getSize();
    bool isEmpty();

    Buffer getBuffer(int server);
    void push(Buffer buffer);
    void sendToServer(std::string data, int server);
    Buffer clearBuffer(int server);
    void clear();

  private:
    Node<Buffer>* getServer(int server);

    int size;
    Node<Buffer>* first;
    Node<Buffer>* last;
};

#endif
