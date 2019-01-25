#pragma once

#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream>
#include "node.hpp"

template<class T>
class DLL{
private:
    Node<T> *head;          // the pointer to the front of the list
    Node<T> *tail;          // the pointer to the back of the list
    int count;
public:
    // desc: Inializes a new, empty list
	DLL();

    // desc:  Adds new data to the front of the list
    // param: data The data to add to the list
	void prepend(T &data);

    // desc:  Adds new data to the end of the list
    // param: data The data to add to the list
	void append(T &data);   

    // desc:    Searches the list for the node that contains data and removes it
    //          from the list
    // param:   data The data to be searched for and removed
    // returns: true if the node was found and removed, false if not
    bool remove(T data); 

    // desc:    Removes the node at the front of the list
    // returns: true if the node was successfully removed, false if not
	bool removeFront(void);

    // desc:    Removes the node at the back of the list
    // returns: true if the node was successfully removed, false if not
	bool removeBack(void);

    // desc:    Searches the list for a node containing the specified data
    // param:   data The data to be searched for
    // returns: A pointer to the node containing the data or NULL if a node
    //          cannot be found
	Node<T> *search(T data);

    // desc::   Returns the data found at the front of the list
    // returns: The data at the front of the list
    T getFront(void);

    // desc::   Returns the data found at the back of the list
    // returns: The data at the back of the list. Return 0 if empty
    T getBack(void);

    // desc: Prints the contents of the list from front to back
	void print();

    // deletes a node form a pointer
    bool deleteFromPtr(Node<T>** dblNodePtr);
};


// constructor
template<class T>
DLL<T>::DLL()
{
	head = NULL;
    tail = NULL;
    count = 0;
}

template<class T>
void DLL<T>::prepend(T &data)
{
	Node<T>* node = new Node<T>(data);

    if (head == NULL) {
        head = node;
        return;
    }

    node->set_next(head);
    head = node;

    return;
}

template<class T>
void DLL<T>::append(T &data)
{
    Node<T>** dblNodePtr = &(head);

    while(*dblNodePtr)
    {
        dblNodePtr = &(*dblNodePtr)->next;
    }

    *dblNodePtr = new Node<T>(data);
}

template<class T>
bool DLL<T>::removeFront()
{
    if (!head) 
    {
        return false;
    }

	Node<T>* toShift = head->next;
	delete head;
	head = toShift;

	return true;
}

template<class T>
bool DLL<T>::removeBack()
{
	if(!head) 
    {
        return false;
    }

	Node<T>** dblNodePtr = &(head);

	while((*dblNodePtr)->next)
    {
		dblNodePtr = &(*dblNodePtr)->next;
    }

	return deleteFromPtr(dblNodePtr);
}

template<class T>
Node<T> *DLL<T>::search(T target)
{
    Node<T>* nodePtr = this->head;

	while(nodePtr && nodePtr->get_data() != target)
    {
		nodePtr = nodePtr->next;
    }

	return nodePtr;
}

template<class T>
void DLL<T>::print()
{
    Node<T> *itr = head;

    std::cout << "Your List: ";
	while (itr != NULL)
	{
        std::cout << itr->get_data() << " -> ";
        itr = itr->get_next();
	}
    std::cout << "NULL" << std::endl;
}

template<class T>
bool DLL<T>::remove(T target)
{
    Node<T>** dblNodePtr = &(this->head);

    while(*dblNodePtr && (**dblNodePtr).get_data() != target) 
    {
        dblNodePtr = &(*dblNodePtr)->next;
    }

    return deleteFromPtr(dblNodePtr);
}

template<class T>
T DLL<T>::getFront(void)
{
    if (!head) 
    {
        return 0;
    }

    return (head->get_data());
}

template<class T>
T DLL<T>::getBack(void)
{
	Node<T>* nodePtr = this->head;

	while(nodePtr->get_next())
    {
		nodePtr = nodePtr->next;
    }

    if (nodePtr)
    {
        return nodePtr->get_data();
    }
    else
    {
        return 0;
    }
}

template<class T>
bool DLL<T>::deleteFromPtr(Node<T>** dblNodePtr)
{
	if(!*dblNodePtr)
    {
		return false;
    }

	Node<T>* toRemove = *dblNodePtr;
	*dblNodePtr = toRemove->next;
	delete toRemove;
	return true;
}