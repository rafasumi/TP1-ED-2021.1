#include <iostream>
#include "Controller.h"

Controller::Controller(int serverQty) {
  if (serverQty <= 0) 
    throw "Controller::Controller: Quantidade inválida de de servidores!";
  
  for (int i = 0; i < serverQty; i++) {
    Buffer* buf = new Buffer();
    servers.push(buf);
  }

  args = new std::string[3];
}

Controller::~Controller() {
  history.clear();
  servers.clear();

  delete[] args;
}

void Controller::info(int server, std::string data) {
  servers.sendToServer(server, data);
}

void Controller::warn(int server, int pos) {
  Buffer* buffer = servers.getBuffer(server);
  
  if (pos != 0) buffer->jump(pos);
}

void Controller::tran(int server1, int server2) {
  if (server1 == server2) return;

  Buffer* buffer1 = servers.getBuffer(server1);
  Buffer* buffer2 = servers.getBuffer(server2);

  if (!buffer1->isEmpty()) buffer2->append(buffer1);
}

void Controller::erro(int server) {
  Buffer* buffer = servers.getBuffer(server);

  std::cout << "ERRO " << server << std::endl;
  if (!buffer->isEmpty()) buffer->flush();
}

void Controller::send() {
  servers.popAll(&history);
}

void Controller::flush() {
  if (!history.isEmpty()) history.flush();

  if (!servers.isEmpty()) servers.flushAll();
}

void Controller::execute(std::string command) {
  extractArgs(command);
  std::string method = args[0];

  if (method == "INFO") {
    info(std::stoi(args[1]), args[2]);
  } 
  else if (method == "WARN") {
    warn(std::stoi(args[1]), std::stoi(args[2]));
  }
  else if (method == "TRAN") {
    tran(std::stoi(args[1]), std::stoi(args[2]));
  }
  else if (method == "ERRO") {
    erro(std::stoi(args[1]));
  }
  else if (method == "SEND") {
    send();
  }
  else if (method == "FLUSH") {
    flush();
  }
  else {
    return;
  }
}

void Controller::extractArgs(std::string inputString) {
  size_t i = 0;
  size_t j = 0;
  size_t aux = 0;
  
  size_t inputSize = inputString.size();
  if (inputString[inputSize - 1] == '\r') inputSize--;
  
  for (i = 0; i < inputSize; i++) {
    char c = inputString[i];
    
    if (c == ' ') {
      args[aux] = inputString.substr(j, i - j);
      aux++;
      
      j = i + 1;
    } else if (c == '\"') {
      i++;
      j++;
      
      while(inputString[i] != '\"') { 
        i++; 
      }

      args[aux] = inputString.substr(j, i - j);
      aux++;
    }
  }

  if (inputString[i-1] != '\"') {
    args[aux] = inputString.substr(j, i - j);
    aux++;
  }
}
