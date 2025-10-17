#include "SparseMatrix.h"

int main(){
    SparseMatrix *m = new SparseMatrix();
    m -> add(5,1,5);
    m -> add(3,2,1);
    m -> add(10,1,1);
    
    cout<< "Matriz: m" << endl;
    cout<< "Filas: "<< m -> getX() << endl;
    cout<< "Columnas: "<< m -> getY() << endl;
    cout<< "Elementos: "<< m -> getElementos() << endl;
    cout<< "Densidad: "<< m -> density() << "%" << endl;
    cout<< "get(1,5): "<< m -> get(1,5) << endl;
    cout<< endl;
    
    m -> printStoredValues();
    
    return 0;
}
