#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"

template <class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void deleteAll();

        void addFirst(T data);
        void addLast(T data);
};


template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *current = head;
    while(head != nullptr){
        head = head->getNext();
        delete current;
        current = head;
    }
    size = 0;
}


template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    Node<T> *current = head;
    if(size == 0){
        addFirst(data);
        return;
    }

    while(current->getNext() != nullptr){
        current = current->getNext();
    }

    current->setNext(new Node<T>(data));
    size++;
}
#endif