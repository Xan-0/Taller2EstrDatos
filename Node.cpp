#include "Node.h"

Node::Node(int value, bool isLast) {
    this -> value = value;
    this -> isLast = isLast;
    next = nullptr;
}

void Node::setValue(int value){
    this -> nota = nota;
}

void Node::setIsLast(bool isLast){
    this -> isLast = isLast;
}

void Node::setNext(Node *next){
    this -> next = next;
}

int Node::getValue(){
    return value;
}

int Node::isLast(){
    return isLast;
}

Node *Node::getNext(){
    return next;
}

Node::~Node(){
    next = nullptr;
}