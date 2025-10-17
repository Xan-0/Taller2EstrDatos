#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class SparseMatrix {
    private:
        Node* start;
        int x;
        int y;
        int elementos;
    public:
        SparseMatrix();
        
        void add(int value, int xPos, int yPos);
        int get(int xPos, int yPos);
        int getX();
        int getY();
        int getElementos();
        void remove(int xPos, int yPos);
        void printStoredValues();
        int density();
        void refreshXY();
        SparseMatrix* multiply(SparseMatrix* second);
        ~SparseMatrix();
};