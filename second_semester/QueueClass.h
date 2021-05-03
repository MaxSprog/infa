#pragma once
#include <cstddef>
template <class T>
class Queue{
    private:
        struct list {
            T data;
            struct list * next;
        };
        typedef struct queue {struct list *top; struct list *bottom;} queue;
        queue *Q;

    public:
        Queue();
        ~Queue();
        void makenull();
        T front();
        T last();
        T pop();
        void push(T a);
        bool empty();
};