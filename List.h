#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual ~List() {}

    // Inserta el elemento e en la posición pos (0..size())
    virtual void insert(int pos, T e) = 0;

    // Añade al final
    virtual void append(T e) = 0;

    // Añade al principio
    virtual void prepend(T e) = 0;

    // Elimina y devuelve el elemento en pos (0..size()-1)
    virtual T remove(int pos) = 0;

    // Devuelve el elemento en pos (0..size()-1)
    virtual T get(int pos) const = 0;

    // Devuelve la posición de e o -1 si no está
    virtual int search(T e) const = 0;

    // ¿Está vacía?
    virtual bool empty() const = 0;

    // Nº de elementos
    virtual int size() const = 0;
};

#endif

