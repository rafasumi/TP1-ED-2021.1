#ifndef SERVER_LIST
#define SERVER_LIST

#include <string>
#include "Buffer.h"
#include "Node.h"

// Classe para representar a lista com todos os servidores do sistema. É uma implementação de lista encadeada
class ServerList {
  public:
    // Construtor de ServerList
    ServerList();
    // Destrutor de ServerList
    ~ServerList();

    // Retorna se a lista está vazia
    bool isEmpty();
    
    // Insere um Buffer ao final da lista
    void push(Buffer* buffer);
    // Envia um dado (string) ao Buffer do servidor 'server'
    void sendToServer(int server, std::string data);
    // Chama a função popFront de todos os Buffers se não estiverem vazios e envia os dados retornados para o Buffer destiny
    void popAll(Buffer* destiny);
    // Limpa a lista, liberando posições de memória alocadas e zerando o tamanho
    void clear();
    
    // Chama a função 'flush' de todos os Buffers não-vazios
    void flushAll();

  private:
    // Retorna um ponteiro para o Buffer do servidor 'server', caso exista
    Buffer* getBuffer(int server);
    // Retorna o Node que representa servidor 'server' na lista
    Node<Buffer*>* getServer(int server);

    int size;
    Node<Buffer*>* first;
    Node<Buffer*>* last;

  friend class Controller;
};

#endif
