#ifndef CONTROLLER
#define CONTROLLER

#include <string>
#include "Buffer.h"
#include "ServerList.h"

class Controller {
  public:
    Controller(int serverQty);
    ~Controller();

    void execute(std::string command);

  private:
    void info(int server, std::string data);
    void warn(int server, int pos);
    void tran(int server1, int server2);
    void erro(int server);
    void send();
    void flush();

    void extractArgs(std::string inputString);

    Buffer history;
    ServerList servers;
    std::string* args;
};

#endif
