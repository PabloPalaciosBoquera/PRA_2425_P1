#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& d, Node<T>* n = nullptr)
        : data(d), next(n) {}
};

#endif

