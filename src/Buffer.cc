#include <iostream>
#include "Buffer.h"

Buffer::Buffer() {
  size = 0;
  front = new Node<std::string>();
  back = front;
}

Buffer::~Buffer() {
  clear();
  delete front;
}

bool Buffer::isEmpty() {
  return size == 0;
}

void Buffer::push(std::string data) {
  Node<std::string>* newNode = new Node<std::string>(data);

  back->next = newNode;
  back = newNode;

  size++;
}

void Buffer::append(Buffer* buffer) {
  if (buffer->isEmpty()) throw "Buffer::append: O buffer está vazio";

  Node<std::string>* aux = buffer->front->next;
  while (aux != nullptr) {
    buffer->front->next = aux->next;
    this->push(aux->item);
    delete aux;
    aux = buffer->front->next;
  }

  buffer->size = 0;
  buffer->back = buffer->front;
}

std::string Buffer::popFront() {
  if (size == 0) throw "Buffer::popFront: O buffer está vazio!";

  std::string auxString = front->next->item;
  Node<std::string>* auxNode = front;
  
  front = front->next;
  delete auxNode;

  size--;

  return auxString;
}

void Buffer::jump(int pos) {
  if ((pos >= size) || (pos <= 0)) throw "Buffer::jump: Posição inválida!";
  
  Node<std::string>* prev = position(pos-1);
  Node<std::string>* node = prev->next;
  prev->next = node->next;

  Node<std::string>* aux = front->next;
  front->next = node;
  node->next = aux;

  if (back == node) 
    back = prev;
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

void Buffer::flush() {
  if (size == 0) throw "Buffer::flush: O buffer está vazio!";

  Node<std::string>* aux = front->next;
  while (aux != nullptr) {
    front->next = aux->next;
    std::cout << aux->item << std::endl;
    delete aux;
    aux = front->next;
  }

  size = 0;
  back = front; 
}

Node<std::string>* Buffer::position(int pos) {
  if ((pos >= size) || (pos < 0)) throw "Buffer::position: Posição inválida!";

  Node<std::string>* aux = front;
  for (int i = 0; i <= pos; i++) {
    aux = aux->next;
  }

  return aux;
}
