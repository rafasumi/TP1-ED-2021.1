#ifndef CONTROLLER
#define CONTROLLER

#include <string>
#include "Buffer.h"
#include "ServerList.h"

// Classe para representar o controlador principal do sistema. É responsável por executar os comandos
class Controller {
  public:
    // Construtor de Controller
    Controller(int serverQty);
    // Destrutor de Controller
    ~Controller();

    // Executa um comando passado no arquivo de input
    void execute(std::string command);

  private:
    // Execução do comando INFO
    void info(int server, std::string data);
    // Execução do comando WARN
    void warn(int server, int pos);
    // Execução do comando TRAN
    void tran(int server1, int server2);
    // Execução do comando ERRO
    void erro(int server);
    // Execução do comando SEND
    void send();
    // Execução do comando FLUSH
    void flush();

    // Método auxiliar para extrair os parâmetros passados juntos à string de comando
    void extractArgs(std::string inputString);

    Buffer history;
    ServerList servers;
    std::string* args;
};

#endif
