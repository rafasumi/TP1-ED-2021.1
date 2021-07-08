#include <iostream>
#include "Buffer.h"

Buffer::Buffer() {
  size = 0;
  front = new Node();
  back = front;
}

Buffer::~Buffer() {
  clear();
  delete front;
}

int Buffer::getSize() {
  return size;
}

bool Buffer::isEmpty() {
  return size == 0;
}

void Buffer::push(std::string data) {
  Node* newNode = new Node();
  newNode->data = data;

  back->next = newNode;
  back = newNode;

  size++;
}

std::string Buffer::popFront() {
  if (size == 0) throw "O buffer está vazio!";

  std::string auxString = front->next->data;
  Node* auxNode = front;
  
  front = front->next;
  delete auxNode;

  size--;

  return auxString;
}

void Buffer::clear() {
  Node* aux = front->next;
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

  Node* aux = front->next;
  while (aux != nullptr) {
    std::cout << aux->data << std::endl;
    aux = aux->next;
  }
}
