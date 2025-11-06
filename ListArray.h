#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        if (new_size < MINSIZE) new_size = MINSIZE;
        T* nuevo = new T[new_size];
        for (int i = 0; i < n; ++i) nuevo[i] = arr[i];
        delete[] arr;
        arr = nuevo;
        max = new_size;
    }

public:
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    ~ListArray() override {
        delete[] arr;
    }

    void insert(int pos, const T& e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        if (n == max) resize(max * 2);
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        ++n;
    }

    void append(const T& e) override { insert(n, e); }
    void prepend(const T& e) override { insert(0, e); }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        T val = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n <= max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }
        return val;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        return arr[pos];
    }

    int search(const T& e) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    bool empty() const override { return n == 0; }

    int size() const override { return n; }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);
};

template <typename U>
std::ostream& operator<<(std::ostream& out, const ListArray<U>& list) {
    out << "List => [\n";
    for (int i = 0; i < list.n; ++i) {
        out << "  " << list.arr[i] << "\n";
    }
    out << "]\n";
    return out;
}

#endif
