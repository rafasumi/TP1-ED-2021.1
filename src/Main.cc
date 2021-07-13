#include <iostream>
#include <fstream>
#include "Controller.h"
#include "ServerList.h"

int main(int argc, char const* argv[]) {
  std::ifstream inputFile(argv[1]);
  std::string serverQty;
  std::string command;

  getline (inputFile, serverQty);
  Controller controller(std::stoi(serverQty));
  
  try {
    while (getline (inputFile, command)) {
      controller.execute(command);
    }
  } catch(char const* error) {
    inputFile.close();
    std::cerr << error << std::endl;
    return -1;
  }

  inputFile.close();

  return 0;
}
