#include "StackClass.h"

template<class T>
Stack<T>::Stack(){
    S = new stck;
    S->top = NULL;
}
template<class T>
Stack<T>::~Stack(){
    struct list *p;
    while (S->top){
        p = S->top;
        S->top = p->next;
        delete[] p;
    }
    delete[] S;
}
template<class T>
void Stack<T>::makenull(){
    struct list *p;
    while (S->top){
        p = S->top;
        S->top = p->next;
        delete[] p;
    }
}
template <class T>
T Stack<T>::top(){//return S->top ? (S->top->data) : 0;
    if(S->top != NULL)
        return S->top->data;
    return 0;
}
template <class T>
T Stack<T>::pop(){
	T a;
	struct list *p;
	p = S->top;
	a = p->data;
	S->top = p->next;
	delete[] p;
	return a;
}
template <class T>
void Stack<T>::push(T a){
	struct list *p;
	p = new struct list;
	p->data = a;
	p->next = S->top;
	S->top = p;
}
template <class T>
bool Stack<T>::empty(){return S->top == NULL;}