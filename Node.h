#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;   // Valor real que guarda el nodo
    Node<T>* next;   // Puntero al siguiente nodo
    
    // Constructor
    Node(const T& d, Node<T>* n = nullptr)
        : data(d), next(n) {}
};

#endif

