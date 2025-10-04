#pragma once

class Node {
    private:
        int value;
        bool isLast;
        Node *next;
    public:
        Node(int value, bool isLast);
        void setValue(int value);
        void setIsLast(bool isLast);
        void setNext(Node *next);
        int getValue();
        bool isLast();
        Node *getNext();
        ~Node();
};