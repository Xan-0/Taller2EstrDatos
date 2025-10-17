#include "Node.h"

Node::Node(int value, int fila, int col) {
    this -> value = value;
    this -> fila = fila;
    this -> col = col;
    next = nullptr;
}

void Node::setValue(int value) {
    this -> value = value;
}

void Node::setNext(Node *next) {
    this -> next = next;
}

int Node::getValue() {
    return value;
}

int Node::getFila() {
    return fila;
}

int Node::getCol() {
    return col;
}

Node *Node::getNext() {
    return next;
}

Node::~Node() {
    next = nullptr;
}
