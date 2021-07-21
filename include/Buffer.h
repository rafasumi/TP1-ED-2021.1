#ifndef BUFFER
#define BUFFER

#include <string>
#include "Node.h"

// Classe para representar o Buffer de um servidor. É uma implementação de fila encadeada
class Buffer {
  public:
    // Construtor de Buffer
    Buffer();
    // Destrutor de Buffer
    ~Buffer();
    
    // Retorna se o Buffer está vazio
    bool isEmpty();
    
    // Insere um novo dado ao final do Buffer
    void push(std::string data);
    // Concatena o conteúdo de um segundo Buffer ao final do Buffer atual
    // O conteúdo do Buffer passado como parâmetro é removido
    void append(Buffer* buffer);
    // Retira o primeiro elemento do Buffer. Retorna o seu dado (string)
    std::string popFront();
    // Faz com que o elemento da posição 'pos' do Buffer passe a ser o novo primeiro elemento
    void jump(int pos);
    // Limpa o Buffer, liberando aa posições de memória alocadas e zerando o tamanho
    void clear();
    
    // Imprime o conteúdo do Buffer e os deleta em sequência
    void flush();
  
  private:
    // Método auxiliar para retornar o Node na posição 'pos' do Buffer, caso seja válida
    Node<std::string>* position(int pos);
    
    int size;
    Node<std::string>* front;
    Node<std::string>* back;
};

#endif
