#include "SparseMatrix.h"

//Se pueden hacer pruebas aquí con la implementación de la Matriz
int main(){
    SparseMatrix *m1 = new SparseMatrix();
    SparseMatrix *m2 = new SparseMatrix();
    
    
    for(int i = 1; i<=10; i++){
        if(i%2 == 0){
            for(int j = 1; j<=5; j++){
                m1 -> add(1,i,j);
            }
        }
    }
    
    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=10; j++){
            if(j%2 ==  0) m2 -> add(1,i,j);
        }
    }
    
    cout<< "Matriz: m1" << endl;
    cout<< "Filas: "<< m1 -> get(-1,-1) << endl;
    cout<< "Columnas: "<< m1 -> get(-2,-2) << endl;
    cout<< "Elementos: "<< m1 -> get(-3,-3) << endl;
    cout<< "Densidad: "<< m1 -> density() << "%" << endl;
    cout<< "get(1,2): "<< m1 -> get(1,2) << endl;
    cout<< endl;
    m1 -> printStoredValues();
    
    cout<< endl;
    cout<< "Matriz: m2" << endl;
    cout<< "Filas: "<< m2 -> get(-1,-1) << endl;
    cout<< "Columnas: "<< m2 -> get(-2,-2) << endl;
    cout<< "Elementos: "<< m2 -> get(-3,-3) << endl;
    cout<< "Densidad: "<< m2 -> density() << "%" << endl;
    cout<< "get(1,2): "<< m2 -> get(1,2) << endl;
    cout<< endl;
    m2 -> printStoredValues();
    cout<< endl;
    
    SparseMatrix *m3 = m1 -> multiply(m2);
    
    cout<< endl;
    cout<< "Matriz: m3" << endl;
    
    if(m3 != nullptr){
        cout<< "Filas: "<< m3 -> get(-1,-1) << endl;
        cout<< "Columnas: "<< m3 -> get(-2,-2) << endl;
        cout<< "Elementos: "<< m3 -> get(-3,-3) << endl;
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
