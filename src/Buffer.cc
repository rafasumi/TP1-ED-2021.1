#include <iostream>
#include "Buffer.h"

Buffer::Buffer() {
  size = 0;
  front = new Node<std::string>();
  back = front;
}

Buffer::~Buffer() {
  if (size > 0) {
    clear();
  }

  delete front;
}

int Buffer::getSize() {
  return size;
}

bool Buffer::isEmpty() {
  return size == 0;
}

void Buffer::push(std::string data) {
  Node<std::string>* newNode = new Node<std::string>();
  newNode->item = data;

  back->next = newNode;
  back = newNode;

  size++;
}

void Buffer::append(Buffer* buffer) {
  if (buffer->isEmpty()) throw "O buffer está vazio";

  Node<std::string>* aux = buffer->front->next;
  while (aux != nullptr) {
    this->push(aux->item);
    aux = aux->next;
  }

  this->size += buffer->getSize();

  buffer->clear();
}

std::string Buffer::popFront() {
  if (size == 0) throw "O buffer está vazio!";

  std::string auxString = front->next->item;
  Node<std::string>* auxNode = front;
  
  front = front->next;
  delete auxNode;

  size--;

  return auxString;
}

void Buffer::jump(int pos) {
  if (pos == 0) throw "Não é possível pular o item da posição 0";
  
  Node<std::string>* prev = position(pos-1);
  Node<std::string>* node = prev->next;
  prev->next = node->next;

  Node<std::string>* aux = front->next;
  front->next = node;
  node->next = aux;
}

void Buffer::clear() {
  Node<std::string>* aux = front->next;
  while (aux != nullptr) {
    front->next = aux->next;
    delete aux;
    aux = front->next;
  }

  size = 0;
  back = front;
}

void Buffer::print() {
  if (size == 0) throw "O buffer está vazio!";

  Node<std::string>* aux = front->next;
  while (aux != nullptr) {
    std::cout << aux->item << std::endl;
    aux = aux->next;
  }
}

Node<std::string>* Buffer::position(int pos) {
  if ((pos > size) || (pos < 0)) throw "Posição inválida!";

  Node<std::string>* aux = front;
  for (int i = 0; i <= pos; i++) {
    aux = aux->next;
  }

  return aux;
}
