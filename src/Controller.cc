#include <iostream>
#include "Controller.h"

Controller::Controller(int serverQty) {
  for (int i = 0; i < serverQty; i++) {
    Buffer* buf = new Buffer();
    servers.push(buf);
  }
}

Controller::~Controller() {
  history.clear();
  servers.clear();
}

void Controller::info(int server, std::string data) {
  servers.sendToServer(server, data);
}

void Controller::warn(int server, int pos) {
  Buffer* buffer = servers.getBuffer(server);
  buffer->jump(pos);
}

void Controller::tran(int server1, int server2) {
  if (server1 == server2) 
    throw "Impossível transferir de um servidor para ele mesmo";

  Buffer* buffer1 = servers.getBuffer(server1);
  Buffer* buffer2 = servers.getBuffer(server2);

  buffer2->append(buffer1);
  buffer1->clear();
}

void Controller::erro(int server) {
  Buffer* buffer = servers.getBuffer(server);

  std::cout << "ERRO " << server << std::endl;
  buffer->print();
  buffer->clear();
}

void Controller::send() {
  servers.popAll(&history);
}

void Controller::flush() {
  if (!history.isEmpty()) history.print();

  if (!servers.isEmpty()) servers.print();
}
