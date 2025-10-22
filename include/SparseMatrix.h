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
         * @brief Añade un valor a la Matriz.
         * @param value Valor que se guardará en la posición.
         * @param xPos Fila en la que se guardará el valor.
         * @param yPos Columna en la que se guardará el valor.
         */
         
        void add(int value, int xPos, int yPos);
        /**
         * @brief Obtiene un valor de la Matriz.
         * @param xPos Fila en la que se encuentra el valor.
         */
        int get(int xPos, int yPos);
        /**
         * @brief Elimina un elemento de la Matriz en la posición.
         * @param xPos Fila en la que se encuentra el valor a eliminar.
         * @param yPos Columna en la que se encuentra el valor a eliminar.
         * 
         * Excepciones de entrada: al ingresar ciertos datos específicos obtienes atributos
         * de la Matriz, como: al ingresar (-1,-1) obtienes las filas, con (-2,-2) obtienes
         * las columnas, y al ingresar (-3,-3) obtienes la cantidad de elementos no nulos
         * de la Matriz.
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
         * @brief Refresca las dimensiones (Filas, Columnas) de la Matriz, dados los nodos más alejados de start.
         */
        SparseMatrix* multiply(SparseMatrix* second);
        /**
         * @brief Elimina la Matriz actual.
         */
        ~SparseMatrix();
};
