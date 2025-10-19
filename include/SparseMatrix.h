#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

/**
 * @class SparseMatrix
 * @brief Representa una Matriz Poco Poblada con x Filas e Y Columnas.
 * 
 * Está clase contiene métodos
 */
class SparseMatrix {
    private:
        Node* start;
        int x;
        int y;
        int elementos;
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
         * @brief Obtiene la cantidad de Filas de la Matriz.
         * @return La cantidad de filas de la Matriz.
         */
        int getX();
        /**
         * @brief Obtiene la cantidad de Columnas de la Matriz.
         * @return La cantidad de Columnas de la Matriz.
         */
        int getY();
        /**
         * @brief Obtiene la cantidad de Elementos no nulos de la Matriz.
         * @return La cantidad de Elementos no nulos de la Matriz.
         */
        int getElementos();
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
         * @brief Refresca las dimensiones (Filas, Columnas) de la Matriz, dados los nodos más alejados de start.
         */
        void refreshXY();
        /**
         * @brief Multiplica esta Matriz por una segunda Matriz.
         * @param second La segunda Matriz a multiplicar.
         * @return La Matriz resultante de la multiplicación.
         */
        SparseMatrix* multiply(SparseMatrix* second);
        /**
         * @brief Elimina la Matriz actual.
         */
        ~SparseMatrix();
};
