#pragma once

/**
 * @class Node
 * @brief Representa un valor no nulo de una Matriz Poco Poblada en la posición (fila,columna).
 * 
 * Utiliza Listas con Nexos, Incluye métodos para cambiar y obtener su valor, Nodo siguiente, y obtener su posición en la Matriz.
 */
class Node {
    private:
        int value;
        int fila;
        int col;
        Node *next;
    public:
        /**
         * @brief Crea un nuevo Nodo y le asigna una posición de Matriz.
         * @param value Valor guardado en el Nodo.
         * @param fila Fila de la Matriz a la que se agregará.
         * @param col Columna de la Matriz a la que se agregará.
         * @return El nuevo Nodo creado.
         */
        Node(int value, int fila, int col);
        /**
         * @brief Cambia el valor guardado en el Nodo.
         * @param value Nuevo valor a guardar en el Nodo.
         */
        void setValue(int value);
        /**
         * @brief Cambia el puntero a el Nodo siguiente.
         * @param value Puntero al Nodo que estará en frente del actual.
         */
        void setNext(Node *next);
        /**
         * @brief Obtiene el valor guardado en el Nodo.
         * @return Valor actual del Nodo.
         */
        int getValue();
        /**
         * @brief Obtiene la Fila de la Matriz en la que se encuentra el Nodo.
         * @return Fila de la Matriz en la que se encuentra el Nodo.
         */
        int getFila();
        /**
         * @brief Obtiene la Columna de la Matriz en la que se encuentra el Nodo.
         * @return Columna de la Matriz en la que se encuentra el Nodo.
         */
        int getCol();
        /**
         * @brief Obtiene el puntero a el Nodo siguiente.
         * @return Puntero al Nodo que estará en frente del actual.
         */
        Node *getNext();
        /**
         * @brief Elimina el Nodo actual.
         */
        ~Node();
};
