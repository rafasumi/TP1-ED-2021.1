#include <iostream>
#include <fstream>
#include <string>
#include "Controller.h"

// Função main do programa. É responsável pela leitura do arquivo de input e pela chamada do controller
// para a execução de comandos
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
    return 1;
  }

  inputFile.close();

  return 0;
}
