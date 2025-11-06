#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
        virtual ~List() {}

        virtual void insert(int pos, T e) = 0;

        virtual void append(T e);

        virtual void preend(T e);

        virtual T remove(int pos);

        virtual T get(int pos);

        virtual int search(T e);

        virtual bool empty();

        virtual int size();
};

#endif
