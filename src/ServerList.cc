#include <iostream>
#include "ServerList.h"

ServerList::ServerList() {
  size = 0;
  first = new Node<Buffer*>;
  last = first;
}

ServerList::~ServerList() {
  clear();
  delete first;
}

bool ServerList::isEmpty() {
  return size == 0;
}

Buffer* ServerList::getBuffer(int server) {
  Node<Buffer*>* node = getServer(server);
  return node->item;
}

void ServerList::push(Buffer* buffer) {
  if (size == 0) {
    first->item = buffer;
  } else {
    Node<Buffer*>* newNode = new Node<Buffer*>;
    newNode->item = buffer;
    
    last->next = newNode;
    last = newNode;
  }
  
  size++;
}

void ServerList::sendToServer(int server, std::string data) {
  Node<Buffer*>* node = getServer(server);
  node->item->push(data);
}

void ServerList::popAll(Buffer* destiny) {
  Node<Buffer*>* aux = first;
  while (aux != nullptr) {
    std::string data = aux->item->popFront();
    destiny->push(data);
    aux = aux->next;
  }
}

void ServerList::clear() {
  Node<Buffer*>* aux = first->next;
  while (aux != nullptr) {
    first->next = aux->next;
    delete aux->item;
    delete aux;
    aux = first->next;
  }

  first->item->clear();
  last = first;
  size = 0;
}

void ServerList::print() {
  Node<Buffer*>* aux = first;
  while (aux != nullptr) {
    if (!aux->item->isEmpty()) aux->item->print();

    aux = aux->next;
  }
}

Node<Buffer*>* ServerList::getServer(int server) {
  if ((server > size) || (server < 0)) throw "Posição inválida!";

  Node<Buffer*>* aux = first;
  for (int i = 0; i < server; i++) {
    aux = aux->next;
  }

  return aux;
}
