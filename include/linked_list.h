#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

template <typename T>
class linked_list
{
    private:
        node<T> *last;
        node<T> *first;
        int length;

    public:
        void add_last(T);
        const int &Length() { return this->length; };
        void remove_last();
        void remove_at(int i);
        T& at(int);
        T& operator[](int i){ return this->at(i); };
        linked_list();
        ~linked_list();
        linked_list<T> operator()(int start, int count);
};

template <typename T>
linked_list<T>::linked_list()
{
    node<T> *n = new node<T>;
    this->first = n;
    this->last = n;
    this->length = 0;
}

template <typename T>
linked_list<T>::~linked_list()
{
    node<T> *act = this->first;
    while(act != this->last)
    {
        node<T> *next = act->next;
        delete act;
        act = next;
    }
}

template <typename T>
void linked_list<T>::add_last(T item)
{
    node<T> *n = new node<T>;
    n->next = this->last;

    this->last->value = item;
    this->last->next = n;
    this->last = n;

    this->length++;
}

template <typename T>
void linked_list<T>::remove_last()
{
    node<T> *to_delete = this->last->prev;

    if(to_delete == this->first)
    {
        delete to_delete;
        this->first = this->last;
    }
    else
    {
        to_delete->prev->next = this->last;
        this->last->prev = to_delete->prev;
        delete to_delete;
    }
}

template <typename T>
void linked_list<T>::remove_at(int i)
{
    if(i >= length)
    {
        throw "tas inflando";
    }
    if(i == 0)
    {
        delete this->first;
        this->first = this->first->next;
    }
    else
    {
        node<T> *to_delete = this->at(i);

        to_delete->prev->next = to_delete->next;
        to_delete->next->prev = to_delete->prev;
        delete to_delete;
    }
}

template <typename T>
T& linked_list<T>::at(int i)
{
    if(i >= length)
    {
        throw "tas inflando";
    }
    node<T> *act = this->first;
    while(i > 0)
    {
        i--;
        act = act->next;
    }
    T &ret = act->value;
    return ret;
}

template <typename T>
linked_list<T> linked_list<T>::operator()(int start, int count)
{
    if((start + count) > this->length)
    {
        throw "tas inflando again";
    }

    linked_list<T> ret;

    node<T> *act = this->first;
    for(int i = 0; i < start; i++)
    {
        act = act->next;
    }
    while(count > 0)
    {
        ret.add_last(act->value);
        act = act->next;
        count--;
    }

    return ret;
}

#endif //LINKED_LIST_H