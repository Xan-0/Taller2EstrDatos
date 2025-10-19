#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(){ //No se agregan nodos para valores 0
    x = 0;
    y = 0;
    elementos = 0;
}

void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos < 1 || yPos < 1){
        cout << "Error, Add() en Posición inválida." << endl;
        return;
    }
    
    //Si la matriz está vacía
    if(elementos == 0){
        start = new Node(value,xPos,yPos);
        x = xPos;
        y = yPos;
        elementos = 1;
        return;
    }
    
    //Si tiene uno o más elementos:
    if(xPos > x) x = xPos;
    if(yPos > y) y = yPos;
    
    Node *cursor = start;
    Node *anterior = start;
    int fila = start -> getFila();
    int col = start -> getCol();
    
    if(yPos < col && xPos == 1){ //Si está antes de start
        cursor = new Node(value,xPos,yPos);
        cursor -> setNext(start);
        start = cursor;
        elementos++;
        return;
    } else if(yPos == col && xPos == fila){ //Si está en start
        cout << "Error, Add() en Posición ya ocupada." << endl;
        return;
    }
    
    while(fila < xPos && cursor -> getNext() != nullptr){ //lleva a la fila deseada
        anterior = cursor;
        cursor = cursor -> getNext();
        fila = cursor -> getFila();
    }
    //Si llegó al final de la matriz
    if(cursor -> getNext() == nullptr){
        cursor -> setNext(new Node(value,xPos,yPos));
        elementos++;
        return;
    }
    //Si llegó a la fila
    if(fila == xPos){ //Si aún hay posibles nodos antes de llegar al destino
        col = cursor -> getCol();
        
        while(col < yPos && fila == xPos && cursor -> getNext() != nullptr){
            anterior = cursor;
            cursor = cursor -> getNext();
            col = cursor -> getCol();
            fila = cursor -> getFila();
        }
        if(col == yPos){
            cout << "Error, Add() en Posición ya ocupada." << endl;
            return;
        }
        if(cursor -> getNext() == nullptr){ //Si llegó al final de la matriz
            cursor -> setNext(new Node(value,xPos,yPos));
            elementos++;
            return;
        }
        
    }
    //En otro caso (la fila y/o columna de cursor es mayor a la de xPos y/o yPos)
    anterior -> setNext(new Node(value,xPos,yPos));
    anterior -> getNext() -> setNext(cursor);
    elementos++;
    return;
}

int SparseMatrix::get(int xPos, int yPos){
    if(elementos == 0) return 0;
    
    if(xPos < 1 || yPos < 1){
        cout << "Error, Get() en Posición inválida." << endl;
        return 0;
    } else if(xPos > x || yPos > y){
        cout << "Warning, Get() out of index." << endl;
        return 0;
    }
    
    Node *cursor = start;
    int fila = cursor -> getFila();
    int col = cursor -> getCol();
    
    //Búsqueda del valor
    while(cursor -> getNext() != nullptr){
        
        if(fila == xPos && col == yPos){
            return cursor -> getValue();
        }
        
        cursor = cursor -> getNext();
        fila = cursor -> getFila();
        col = cursor -> getCol();
    }
    //último valor
    if(fila == xPos && col == yPos){
        return cursor -> getValue();
    }
    //Si no se encontró en los valores no nulos
    return 0;
}

int SparseMatrix::getX(){
    return x;
}

int SparseMatrix::getY(){
    return y;
}

int SparseMatrix::getElementos(){
    return elementos;
}

void SparseMatrix::remove(int xPos, int yPos){
    if(elementos == 0) return;
    
    if(xPos < 1 || yPos < 1){
        cout << "Error, Remove() en Posición inválida." << endl;
        return;
    } else if(xPos > x || yPos > y){
        cout << "Error, Remove() out of index." << endl;
        return;
    }
    
    Node *aux = nullptr;
    
    //Si hay un elemento y se quiere eliminar a start
    if(elementos == 1){
        if(xPos == start -> getFila() && yPos == start -> getCol()){
            delete start;
            start = nullptr;
            elementos = 0;
            x = 0;
            y = 0;
        }
        return;
    }
    //Si se quiere eliminar a start con 2 o más elementos
    if(xPos == start -> getFila() && yPos == start -> getCol()){
        aux = start -> getNext();
        delete start;
        start = aux;
        elementos--;
        refreshXY();
        return;
    }
    
    //Si hay 2 o más elementos y no es start
    Node *cursor = start -> getNext();
    Node *anterior = start;
    int fila = cursor -> getFila();
    int col = cursor -> getCol();
    
    while(cursor -> getNext() != nullptr){
        
        if(fila == xPos && col == yPos){ //Entre 2 nodos
            aux = cursor -> getNext();
            delete cursor;
            anterior -> setNext(aux);
            
            cursor = nullptr;
            elementos--;
            return;
        }
        
        anterior = cursor;
        cursor = cursor -> getNext();
        fila = cursor -> getFila();
        col = cursor -> getCol();
    }
    
    if(fila == xPos && col == yPos){ //último nodo
        anterior -> setNext(nullptr);
        delete cursor;
        cursor = nullptr;
        
        elementos--;
        refreshXY();
        return;
    }
    
    //Si era un valor nulo
    cout << "Warning, Remove() innecesario." << endl;
    return;
}

void SparseMatrix::printStoredValues(){
    if(start == nullptr) return;
    
    cout << "(fila, columna) --> Valor" << endl;
    
    if(elementos == 1){
        cout << "(" << start -> getFila() << ", " << start -> getCol() << ") --> " << start -> getValue() << endl;
        return;
    }
    
    Node *cursor = start;
    
    while(cursor -> getNext() != nullptr){
        cout << "(" << cursor -> getFila() << ", " << cursor -> getCol() << ") --> " << cursor -> getValue() << endl;
        cursor = cursor -> getNext();
    }
    cout << "(" << cursor -> getFila() << ", " << cursor -> getCol() << ") --> " << cursor -> getValue() << endl;
    return;
}

int SparseMatrix::density(){
    if(elementos == 0) return 0;
    return 100*elementos/(x*y);
}

void SparseMatrix::refreshXY(){
    if(elementos == 0) {x = 0; y = 0; return;}
    if(elementos == 1) {x = start -> getFila(); y = start -> getCol(); return;}
    
    //Si hay 2 o más elementos
    Node *cursor = start;
    int filaMayor = 0;
    int colMayor = 0;
    
    while(cursor -> getNext() != nullptr){
        if(cursor -> getFila() > filaMayor){
            filaMayor = cursor -> getFila();
        }
        if(cursor -> getCol() > colMayor){
            colMayor = cursor -> getCol();
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getFila() > filaMayor){
        filaMayor = cursor -> getFila();
    }
    if(cursor -> getCol() > colMayor){
        colMayor = cursor -> getCol();
    }
    
    x = filaMayor;
    y = colMayor;
    return;
}

// (nxm) * (pxq) -> (nxq)
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    if(elementos == 0) {cout << "Error, Multiply() con matriz o matrices vacías." << endl; return nullptr;}
    if(y != second -> getX()) {cout << "Error, Multiply() con matrices incompatibles." << endl; return nullptr;}
    
    SparseMatrix *nueva = new SparseMatrix();
    int val = 0;
    int val1 = 0;
    int val2 = 0;
    
    for(int i = 1; i <= x; ++i){ //fila1
        for(int j = 1; j <= second -> getY(); ++j){ //col2
            for(int k = 1; k <= y; ++k){ //col1
                
                val1 = get(i,k);
                val2 = second -> get(k,j);
                val += val1 * val2;
                cout << val1 << " * " << val2 << " = " << val << endl;
                
            }
            if(val != 0){
                nueva -> add(val,i,j);
                val = 0;
            }
        }
    }
    
    return nueva;
}

SparseMatrix::~SparseMatrix(){
    if(elementos == 0) return;
    
    if(elementos == 1){
        delete start;
        start = nullptr;
        return;
    }
    //2 o más elementos
    Node *cursor = start -> getNext();
    Node *anterior = start;
    
    while(cursor -> getNext() != nullptr){
        delete anterior;
        anterior = cursor;
        cursor = cursor -> getNext();
    }
    delete anterior;
    delete cursor;
    start = nullptr;
    cursor = nullptr;
    anterior = nullptr;
    return;
}
