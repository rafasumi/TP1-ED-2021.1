#ifndef NODE
#define NODE

// Classe para representar uma célula em uma lista ou fila encadeada. Usa polimorfismo paramétrico
template <class T> class Node {
  public:
    // Construtor padrão de Node
    // É necessário fazer a implementação da função no .h devido ao uso do recurso de template class
    Node() {
      item = T();
      next = nullptr;
    }

    // Construtor de Node que recebe um valor para 'item'
    // É necessário fazer a implementação da função no .h devido ao uso do recurso de template class
    Node(T item) {
      this->item = item;
      next = nullptr;
    }

  private:
    T item;
    Node* next;

  friend class Buffer;
  friend class ServerList;
};

#endif
