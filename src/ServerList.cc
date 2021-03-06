#include "ServerList.h"

ServerList::ServerList() {
  size = 0;
  first = new Node<Buffer*>();
  last = first;
}

ServerList::~ServerList() {
  clear();
  delete first;
}

bool ServerList::isEmpty() {
  return size == 0;
}

void ServerList::push(Buffer* buffer) {
  Node<Buffer*>* newNode = new Node<Buffer*>(buffer);
  
  last->next = newNode;
  last = newNode;
  
  size++;
}

void ServerList::sendToServer(int server, std::string data) {
  Node<Buffer*>* node = getServer(server);
  node->item->push(data);
}

void ServerList::popAll(Buffer* destiny) {
  Node<Buffer*>* aux = first->next;
  while (aux != nullptr) {
    if (!aux->item->isEmpty()) {
      std::string data = aux->item->popFront();
      destiny->push(data);
    }
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

  size = 0;
  last = first;
}

void ServerList::flushAll() {
  Node<Buffer*>* aux = first->next;
  while (aux != nullptr) {
    if (!aux->item->isEmpty()) aux->item->flush();

    aux = aux->next;
  }
}

Buffer* ServerList::getBuffer(int server) {
  Node<Buffer*>* node = getServer(server);
  return node->item;
}

Node<Buffer*>* ServerList::getServer(int server) {
  if ((server >= size) || (server < 0)) throw "ServerList::getServer: Posição inválida!";

  Node<Buffer*>* aux = first;
  for (int i = 0; i <= server; i++) {
    aux = aux->next;
  }

  return aux;
}
