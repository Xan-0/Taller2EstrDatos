#include "include\SparseMatrix.h"
#include <limits>
#include <chrono>
#include <cstdlib>
using namespace chrono;

//Ejemplo: caso con 50 datos, 100% densidad
void muestra(int num){
    srand(time(NULL));
    SparseMatrix *m1 = new SparseMatrix();
    SparseMatrix *m2 = new SparseMatrix();
    
    for(int i = 10; i>=1; i--){
        for(int j = 5; j>=1; j--){
            //Un número entre 1 y 10
            m1 -> add(1 + rand() % 10,i,j);
        }
    }
    
    cout << "__Muestra numero " << num << "__" << endl;
    auto inicio = high_resolution_clock::now();
    
    m1 -> add(1,11,1);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<nanoseconds>(fin - inicio);
    
    cout << "Tiempo de ejecucion de add() en m1 -> (11,1): " << duracion.count() << " nanosegundos" << endl << endl;
    
    m1 -> remove(11,1);
    
    inicio = high_resolution_clock::now();
    
    m1 -> get(10,5);
    
    fin = high_resolution_clock::now();
    duracion = duration_cast<nanoseconds>(fin - inicio);
    
    cout << "Tiempo de ejecucion de get() en m1 -> (10,5): " << duracion.count() << " nanosegundos" << endl << endl;
    
    for(int i = 5; i>=1; i--){
        for(int j = 10; j>=1; j--){
            m2 -> add(1 + rand() % 10,i,j);
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
    cout<< endl;
    
    inicio = high_resolution_clock::now();
    
    SparseMatrix *m3 = m1 -> multiply(m2);
    
    fin = high_resolution_clock::now();
    duracion = duration_cast<microseconds>(fin - inicio);
    
    cout << "Tiempo de ejecucion de multiply() (m1 x m2): " << duracion.count() / 1000 << " milisegundos" << endl;
    cout << endl;
    
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
}

//Aquí se pueden tomar muestras de pruebas con la implementación de la Matriz
int main(){
    int muestras = 5
    for(int i = 1; i<=muestras; i++){
        muestra(i);
    }
    
    return 0;
}
