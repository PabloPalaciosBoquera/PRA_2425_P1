#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;   // Puntero al array dinámico
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        if (new_size < MINSIZE) new_size = MINSIZE;   // Si es más pequeño, vale2 porque no puede valer menos
        T* nuevo = new T[new_size];   // Reserva memoria nueva para un array de new_size elementos de tipo T
        for (int i = 0; i < n; ++i) nuevo[i] = arr[i];   // Copia los n elementos válidos del array nuevo al viejo
        delete[] arr;   // Libera memoria del array viejo
        arr = nuevo;   // El puntero arr apunta al nuevo array
        max = new_size;   // Actualiza la capacidad máxima de la lista
    }

public:
    // Constructor
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor
    ~ListArray() override {
        delete[] arr;
    }

    void insert(int pos,T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        if (n == max) resize(max * 2);   // Si el array está lleno duplica la capacidad
        for (int i = n; i > pos; --i) {   // Desplaza todos los elementos desde pos hasta el final a la derecha
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;   // Coloca el nuevo elemento donde toca
        ++n;
    }

    void append(T e) override { insert(n, e); }
    void prepend(T e) override { insert(0, e); }

    T remove(int pos) override {   // Elimina el elemento que hay en la posición pos, lo devuelve y reorganiza
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        T val = arr[pos];   // Guarda el elemento que se va a eliminar
        for (int i = pos; i < n - 1; ++i) {   // Reorganiza la lista
            arr[i] = arr[i + 1];
        }
        --n;
        if (n <= max / 4 && max / 2 >= MINSIZE) {   // Si usas menos del 25%, se reduce el array a la mitad
            resize(max / 2);
        }
        return val;   // Devuelve el elemento eliminado
    }

    T get(int pos) const override {   // Obtiene el elemento de una posición concreta
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    T operator[](int pos) const {   // Usa la lista como un array, igual que get pero con []
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    int search(T e) const override {   // Busca un elemento y devuelve la posición
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;   // Si no está
    }

    bool empty() const override { return n == 0; }   // Dice si la lista está vacía o no

    int size() const override { return n; }   // Devuelve el número total de elementos actuales

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);
};

template <typename U>
std::ostream& operator<<(std::ostream& out, const ListArray<U>& list) {
    out << "List => [\n";
    for (int i = 0; i < list.n; ++i) {   // Imprime cada elemento de la lista
        out << "  " << list.arr[i] << "\n";
    }
    out << "]\n";
    return out;
}

#endif
