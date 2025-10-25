#include "..\include\SparseMatrix.h"

SparseMatrix::SparseMatrix(){ //No se agregan nodos para valores 0
    start = nullptr;
}

void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos < 1 || yPos < 1){
        cout << "Error, Add() en Posición inválida." << endl;
        return;
    }
    if(value == 0){
        cout << "Warning, intento de añadir valor 0 de forma directa." << endl;
        return;
    }
    
    //Si la matriz está vacía
    if(start == nullptr){
        start = new Node(value,xPos,yPos);
        return;
    }
    
    //Si tiene uno o más elementos:
    Node *cursor = start;
    Node *anterior = start;
    int fila = start -> getFila();
    int col = start -> getCol();
    
    if(xPos < fila || (xPos == fila && yPos < col) ){ //Si está antes de start
        cursor = new Node(value,xPos,yPos);
        cursor -> setNext(start);
        start = cursor;
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
        if(cursor -> getNext() == nullptr){ //En otro caso (la fila y/o columna de cursor es mayor a la de xPos y/o yPos)
            cursor -> setNext(new Node(value,xPos,yPos));
            return;
        }
        
    }
    //En el caso normal
    anterior -> setNext(new Node(value,xPos,yPos));
    anterior -> getNext() -> setNext(cursor);
    return;
}

//Excepciones: (-1,-1) = x, (-2,-2) = y, (-3,-3) = elementos, (-4,-4) = filaStart, (-5,-5) = colStart.
int SparseMatrix::get(int xPos, int yPos){
    if(start == nullptr) return 0;
    if(xPos == -4 && yPos == -4) return start -> getFila();
    if(xPos == -5 && yPos == -5) return start -> getCol();
    
    if((xPos != yPos) && (xPos < 1 || yPos < 1)){
        cout << "Error, Get() en Posición inválida." << endl;
        return 0;
    }
    
    int elementos = 1;
    int x = start -> getFila();
    int y = start -> getCol();
    Node *cursor = start;
    int fila = cursor -> getFila();
    int col = cursor -> getCol();
    
    if(start -> getNext() == nullptr){
        if(xPos == -1 && yPos == -1) return x;
        if(xPos == -2 && yPos == -2) return y;
        if(xPos == -3 && yPos == -3) return elementos;
    }
    
    //Búsqueda del valor
    while(cursor -> getNext() != nullptr){
        elementos++;
        
        if(cursor -> getFila() > x) x = cursor -> getFila();
        if(cursor -> getCol() > y) y = cursor -> getCol();
        
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
    if(cursor -> getFila() > x) x = cursor -> getFila();
    if(cursor -> getCol() > y) y = cursor -> getCol();
    
    if(xPos > x || yPos > y){
        cout << "Warning, Get() out of index." << endl;
        return 0;
    }
    
    if(xPos == -1 && yPos == -1) return x;
    if(xPos == -2 && yPos == -2) return y;
    if(xPos == -3 && yPos == -3) return elementos;
    
    //Si no se encontró en los valores no nulos
    return 0;
}

void SparseMatrix::remove(int xPos, int yPos){
    if(start == nullptr) return;
    
    if(xPos < 1 || yPos < 1){
        cout << "Error, Remove() en Posición inválida." << endl;
        return;
    }
    if(xPos > get(-1,-1) || yPos > get(-2,-2)){
        cout << "Error, Remove() out of index." << endl;
        return;
    }
    
    Node *aux = nullptr;
    
    //Si hay un elemento y se quiere eliminar a start
    if(start -> getNext() == nullptr){
        if(xPos == start -> getFila() && yPos == start -> getCol()){
            delete start;
            start = nullptr;
        }
        return;
    }
    //Si se quiere eliminar a start con 2 o más elementos
    if(xPos == start -> getFila() && yPos == start -> getCol()){
        aux = start -> getNext();
        delete start;
        start = aux;
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
        return;
    }
    
    //Si era un valor nulo
    cout << "Warning, Remove() innecesario." << endl;
    return;
}

void SparseMatrix::printStoredValues(){
    if(start == nullptr) return;
    
    cout << "(fila, columna) --> Valor" << endl;
    
    if(start -> getNext() == nullptr){
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
    if(start == nullptr) return 0;
    int x = get(-1,-1);
    int y = get(-2,-2);
    int elementos = get(-3,-3);
    
    return 100*elementos/(x*y);
}

// (nxm) * (pxq) -> (nxq)
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    if(start == nullptr || second -> get(-4,-4) == 0) {cout << "Error, Multiply() con matriz o matrices vacías." << endl; return nullptr;}
    
    int x1 = get(-1,-1);
    int y1 = get(-2,-2);
    int x2 = second -> get(-1,-1);
    int y2 = second -> get(-2,-2);
    
    if(y1 != x2) {cout << "Error, Multiply() con matrices incompatibles." << endl; return nullptr;}
    
    SparseMatrix *nueva = new SparseMatrix();
    int val = 0;
    int val1 = 0;
    int val2 = 0;
    
    for(int i = get(-4,-4); i <= x1; ++i){ //fila1
        for(int j = second -> get(-5,-5); j <= y2; ++j){ //col2
            for(int k = get(-5,-5); k <= y1; ++k){ //col1
                
                val1 = get(i,k);
                val2 = second -> get(k,j);
                val += val1 * val2;
                //cout << val << " += " << val1 << " * " << val2 << endl;
                
            }
            if(val != 0){
                //cout << "val = " << val << endl;
                nueva -> add(val,i,j);
                val = 0;
            }
        }
    }
    
    return nueva;
}

SparseMatrix::~SparseMatrix(){
    if(start == nullptr) return;
    
    if(start -> getNext() == nullptr){
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
