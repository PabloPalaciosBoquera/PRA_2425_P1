#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

    // Devuelve puntero al nodo en posición pos (0..n-1)
    Node<T>* node_at(int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* curr = first;
        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }
        return curr;
    }

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() override {
        Node<T>* curr = first;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Inserta e en [0..size()]
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }

        if (pos == 0) {
            // insertar al principio
            first = new Node<T>(e, first);
        } else {
            // insertar en medio/final
            Node<T>* prev = node_at(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve elemento en [0..size()-1]
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }

        T val;
        if (pos == 0) {
            Node<T>* del = first;
            first = first->next;
            val = del->data;
            delete del;
        } else {
            Node<T>* prev = node_at(pos - 1);
            Node<T>* del = prev->next;
            prev->next = del->next;
            val = del->data;
            delete del;
        }
        --n;
        return val;
    }

    // Devuelve elemento en [0..size()-1]
    T get(int pos) const override {
        Node<T>* node = node_at(pos);
        return node->data;
    }

    // Operador indexación (versión const)
    T operator[](int pos) const {
        Node<T>* node = node_at(pos);
        return node->data;
    }

    int search(T e) const override {
        Node<T>* curr = first;
        int i = 0;
        while (curr != nullptr) {
            if (curr->data == e) return i;
            curr = curr->next;
            ++i;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    // Salida formateada
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<U>& list);
};

template <typename U>
std::ostream& operator<<(std::ostream& out, const ListLinked<U>& list) {
    out << "List => [\n";
    Node<U>* curr = list.first;
    while (curr != nullptr) {
        out << "  " << curr->data << "\n";
        curr = curr->next;
    }
    out << "]\n";
    return out;
}

#endif // LISTLINKED_H

