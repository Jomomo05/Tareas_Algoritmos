#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"
#include <iostream>

using namespace std;

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
        void printAll();
        void search(T dato);
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

template <class T>
void LinkedList<T>::printAll(){
    Node<T> *current = head;
    current->printNode();

    while(current->getNext() != nullptr){
        //current->printNode();
        current = current->getNext();
        current->printNode();
    }
}

template <class T>
void LinkedList<T>::search(T dato){
    Node<T> *current = head;
    //current->printNode();

    int contador = 0;
    int elementos = 0;

    while(current->getNext() != nullptr){
        if (current->getData() == dato){
            elementos++;
            cout << "Se encontro en el lugar: " << contador << endl;
        }
        current = current->getNext();
        //current->printNode();
        contador++;
    }

    if (elementos == 0){
        cout << "No se encontraron coincidencias" << endl;
    }else {
        cout << "Se encontraron " << elementos << " Coincidencias" << endl;
    }
}


#endif