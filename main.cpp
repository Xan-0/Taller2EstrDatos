#include "SparseMatrix.h"

int main(){
    SparseMatrix *m1 = new SparseMatrix();
    SparseMatrix *m2 = new SparseMatrix();
    
    m1 -> add(1,1,1);
    m1 -> add(3,1,2);
    m1 -> add(7,2,1);
    m1 -> add(11,2,2);
    
    m2 -> add(2,1,1);
    m2 -> add(5,1,2);
    m2 -> add(10,2,1);
    m2 -> add(13,2,2);
    
    cout<< "Matriz: m1" << endl;
    cout<< "Filas: "<< m1 -> getX() << endl;
    cout<< "Columnas: "<< m1 -> getY() << endl;
    cout<< "Elementos: "<< m1 -> getElementos() << endl;
    cout<< "Densidad: "<< m1 -> density() << "%" << endl;
    cout<< "get(1,2): "<< m1 -> get(1,2) << endl;
    cout<< endl;
    m1 -> printStoredValues();
    
    cout<< endl;
    cout<< "Matriz: m2" << endl;
    cout<< "Filas: "<< m2 -> getX() << endl;
    cout<< "Columnas: "<< m2 -> getY() << endl;
    cout<< "Elementos: "<< m2 -> getElementos() << endl;
    cout<< "Densidad: "<< m2 -> density() << "%" << endl;
    cout<< "get(1,2): "<< m2 -> get(1,2) << endl;
    cout<< endl;
    m2 -> printStoredValues();
    cout<< endl;
    
    SparseMatrix *m3 = m1 -> multiply(m2);
    
    cout<< endl;
    cout<< "Matriz: m3" << endl;
    
    if(m3 != nullptr){
        cout<< "Filas: "<< m3 -> getX() << endl;
        cout<< "Columnas: "<< m3 -> getY() << endl;
        cout<< "Elementos: "<< m3 -> getElementos() << endl;
        cout<< "Densidad: "<< m3 -> density() << "%" << endl;
        cout<< "get(1,2): "<< m3 -> get(1,2) << endl;
        cout<< endl;
        m3 -> printStoredValues();
    }
    
    delete m1;
    delete m2;
    delete m3;
    m1 = nullptr;
    m2 = nullptr;
    m3 = nullptr;
    
    return 0;
}
