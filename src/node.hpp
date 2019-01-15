#pragma once
#include <cstddef>
template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
    
       Node(void);
       Node(T &data);
       Node<T>* set_data(T &new_data);
       Node<T>* set_next(Node<T> *next_node);
       Node<T>* set_prev(Node<T> *prev_node);
       T get_data(void);
       Node<T> *get_next(void);
       Node<T> *get_prev(void);
};

template<class T>
Node<T>::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}

template<class T>
Node<T>::Node(T &new_data)
{
    data = new_data;
    next = NULL;
}

template<class T>
 Node<T>* Node<T>::set_data(T &new_data)
{
    data = new_data;
    return this;
}

template<class T>
T Node<T>::get_data()
{
    return data;
}

template<class T>
Node<T>* Node<T>::set_next(Node<T> *next_node_ptr)
{
   next = next_node_ptr;
   return this;
}

template<class T>
Node<T>* Node<T>::set_prev(Node<T> *prev_node_ptr)
{
   prev = prev_node_ptr;
   return this;
}

template<class T>
Node<T> *Node<T>::get_next()
{
    return next;
}

template<class T>
Node<T> *Node<T>::get_prev()
{
    return prev;
}
