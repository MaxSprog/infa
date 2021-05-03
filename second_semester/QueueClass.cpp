#include "QueueClass.h"

template<class T>
Queue<T>::Queue(){
    Q = new queue;
    Q->top = NULL;
    Q->bottom = NULL;
}
template<class T>
Queue<T>::~Queue(){
    struct list *p;
    while (Q->top){
        p = Q->top;
        Q->top = p->next;
        delete[] p;
    }
    delete[] Q;
}
template<class T>
void Queue<T>::makenull(){
    struct list *p;
    while (Q->top){
        p = Q->top;
        Q->top = p->next;
        delete[] p;
    }
}
template <class T>
T Queue<T>::front(){//return Q->top ? (Q->top->data) : 0;
    if(Q->top != NULL)
        return Q->top->data;
    return 0;
}
template <class T>
T Queue<T>::last(){
    if(Q->bottom != NULL)
        return Q->bottom->data;
    return 0;
}
template <class T>
T Queue<T>::pop(){
	T a;
	struct list *p;
	p = Q->top;
	a = p->data;
	Q->top = p->next;
	delete[] p;
	return a;
}
template <class T>
void Queue<T>::push(T a){
	struct list *p;
	p = new struct list;
	p->data = a;
    p->next = NULL;
    if(Q->top == NULL){
        Q->top = p;
        Q->bottom = p;
        return;
    }
	Q->bottom->next = p;
	Q->bottom = p;
}
template <class T>
bool Queue<T>::empty(){return Q->top == NULL;}