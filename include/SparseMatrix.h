#pragma once
#include "Node.h"

/**
 * @class SparseMatrix
 * @brief Representa una Matriz Poco Poblada formada con Nodos organizados en filas y columnas.
 * 
 * Está clase contiene métodos de agregación, obtención, eliminación, impresión de valores no nulos guardados y multiplicación
 */
class SparseMatrix {
    private:
        Node* start;
        
    public:
        /**
        * @brief Crea una Matriz Poco Poblada.
        * @return una nueva SparseMatrix.
        */
        SparseMatrix();
        /**
         * @brief Añade un valor a la Matriz en la posición indicada.
         * @param value Valor que se guardará en la posición.
         * @param xPos Fila en la que se guardará el valor.
         * @param yPos Columna en la que se guardará el valor.
         */
        void add(int value, int xPos, int yPos);
        /**
         * @brief Obtiene un valor de la Matriz.
         * @param xPos Fila en la que se encuentra el valor.
         * @param yPos Columna en la que se encuentra el valor.
         * @return el valor en la posición indicada.
         * 
         * Excepciones de entrada: al ingresar ciertos datos específicos obtienes atributos
         * de la Matriz, como: al ingresar (-1,-1) obtienes las filas, con (-2,-2) obtienes
         * las columnas, con (-3,-3) obtienes la cantidad de elementos no nulos
         * de la Matriz, con (-4,-4) obtienes la fila en la que se encuentra el primer valor
         * no nulo (start), y con (-5,-5) la columna en la que se encuentra.
         */
        int get(int xPos, int yPos);
        /**
         * @brief Elimina un elemento de la Matriz en la posición.
         * @param xPos Fila en la que se encuentra el valor a eliminar.
         * @param yPos Columna en la que se encuentra el valor a eliminar.
         */
        void remove(int xPos, int yPos);
        /**
         * @brief Imprime todos los valores no nulos de la Matriz.
         */
        void printStoredValues();
        /**
         * @brief Obtiene el porcentaje de densidad de Elementos no nulos de la Matriz (100 * cantidad de elementos no nulos / cantidad de elementos totales).
         * @return La densidad de Elementos no nulos de la Matriz (%).
         */
        int density();
        /**
         * @brief Elimina la Matriz actual.
         * @param second La segunda matriz con la que se multiplicará la actual.
         * @return una nueva Matriz que es la resultante de la multiplicación.
         */
        SparseMatrix* multiply(SparseMatrix* second);
        /**
         * @brief Elimina la Matriz actual.
         */
        ~SparseMatrix();
};
