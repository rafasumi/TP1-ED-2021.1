#ifndef CONTROLLER
#define CONTROLLER

#include <string>
#include "Buffer.h"
#include "ServerList.h"

class Controller {
  public:
    Controller(int serverQty);
    ~Controller();

    void info(int server, std::string data);
    void warn(int server, int pos);
    void tran(int server1, int server2);
    void erro(int server);
    void send();
    void flush();

  private:
    Buffer history;
    ServerList servers;
};

#endif
