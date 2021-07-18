#ifndef NODE
#define NODE

// Classe para representar uma célula em uma lista ou fila encadeada. Usa polimorfismo paramétrico
template <class T> class Node {
  public:
    // Construtor de Node
    // Foi necessário fazer a implementação da função no .h devido ao uso do recurso de template class
    Node() {
      item = T();
      next = nullptr;
    }

  private:
    T item;
    Node* next;

  friend class Buffer;
  friend class ServerList;
};

#endif
