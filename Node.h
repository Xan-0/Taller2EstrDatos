#pragma once

class Node {
    private:
        int value;
        int fila;
        int col;
        Node *next;
    public:
        Node(int value, int fila, int col);
        void setValue(int value);
        void setNext(Node *next);
        int getValue();
        int getFila();
        int getCol();
        Node *getNext();
        ~Node();
};
