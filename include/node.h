#ifndef NODE_H
#define NODE_H

template <typename T>
struct node
{
    T value;
    node<T> *next;
    node<T> *prev;
};

#endif //NODE_H